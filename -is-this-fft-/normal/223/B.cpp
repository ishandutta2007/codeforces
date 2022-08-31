#include <iostream>
#include <set>
#include <map>

using namespace std;

void failure () {
  cout << "No" << endl;
  exit(0);
}

const int ALPH = 200;

set<int> pos [ALPH];
set<int> t_pos [ALPH];

bool t_contains (int l, int r, char c) {
  auto it = t_pos[c].lower_bound(l);
  if (it == t_pos[c].end()) {
    return false;
  }

  return *it <= r;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s, t;
  cin >> s >> t;

  for (int i = 0; i < (int) s.size(); i++) {
    pos[s[i]].insert(i);
  }

  for (int i = 0; i < (int) t.size(); i++) {
    t_pos[t[i]].insert(i);
  }

  map<int, int> lmost; // s positions to t positions
  int cur_pos = -1;
  for (int i = 0; i < (int) t.size(); i++) {
    auto it = pos[t[i]].upper_bound(cur_pos);
    if (it == pos[t[i]].end()) {
      failure();
    }

    cur_pos = *it;
    lmost[cur_pos] = i;
  }

  map<int, int> rmost;
  cur_pos = s.size() + 1;
  for (int i = (int) t.size() - 1; i >= 0; i--) {
    auto it = prev(pos[t[i]].lower_bound(cur_pos));
    cur_pos = *it;
    rmost[cur_pos] = i;
  }

  for (int i = 0; i < (int) s.size(); i++) {
    int L;
    auto lowest_r = rmost.upper_bound(i);
    if (lowest_r == rmost.end()) {
      L = (int) t.size() - 1;
    } else {
      L = lowest_r->second - 1;
    }

    int R;
    auto lft = lmost.lower_bound(i);
    if (lft == lmost.end()) {
      R = (int) t.size() - 1;
    } else {
      R = lft->second;
    }

    if (L > R) {
      failure();
    }

    if (!t_contains(L, R, s[i])) {
      failure();
    }
  }

  cout << "Yes" << endl;
}