#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

ll A [MAX_N];
ll B [MAX_N];
ll pref [MAX_N];

vector<int> oths [MAX_N];

set<int> inactive;
bool active [MAX_N];
vector<pair<int, int>> stk;

void activate (int pos) {
  inactive.erase(pos);
  active[pos] = true;

  for (int e : oths[pos]) {
    if (active[e]) {
      stk.push_back({min(pos, e), max(pos, e)});
    }
  }
}

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> B[i];
  }

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + A[i] - B[i];
  }

  inactive.clear();
  stk.clear();
  for (int i = 0; i <= n; i++) {
    oths[i].clear();
    active[i] = false;
    inactive.insert(i);
  }
  
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--;

    oths[l].push_back(r);
    oths[r].push_back(l);
  }

  for (int i = 0; i <= n; i++) {
    if (pref[i] == 0) {
      activate(i);
    }
  }

  while (!stk.empty()) {
    auto lr = stk.back();
    stk.pop_back();

    int l = lr.first;
    int r = lr.second;
    vector<int> to_activate;
    for (auto it = inactive.upper_bound(l); it != inactive.end() && *it < r; it++) {
      to_activate.push_back(*it);
    }

    for (auto i : to_activate) {
      activate(i);
    }
  }

  for (int i = 0; i <= n; i++) {
    if (!active[i]) {
      cout << "NO" << '\n';
      return;
    }
  }

  cout << "YES" << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}