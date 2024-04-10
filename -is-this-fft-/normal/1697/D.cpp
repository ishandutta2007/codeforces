#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

char at (int pos) {
  cout << "? 1 " << pos << endl;

  char resp;
  cin >> resp;
  return resp;
}

int cnt (int l, int r) {
  cout << "? 2 " << l << " " << r << endl;

  int resp;
  cin >> resp;
  return resp;
}

const int MAX_N = 1e3 + 5;
const int ALPH = 26;

char str_ans [MAX_N];
int pref [ALPH][MAX_N];

// must be called sequentially
void set_pos (int pos, char val) {
  str_ans[pos] = val;
  pref[val - 'a'][pos] = 1;

  for (int i = 0; i < ALPH; i++) {
    pref[i][pos] += pref[i][pos - 1];
  }
}

int cnt_kn (int l, int r) {
  int ans = 0;

  for (int i = 0; i < ALPH; i++) {
    if (pref[i][r] - pref[i][l - 1]) {
      ans++;
    }
  }

  return ans;
}

int main () {
  int n;
  cin >> n;

  map<char, int> last_seen;
  int last_p = 0;
  for (int i = 1; i <= n; i++) {
    int cur_p = cnt(1, i);
    char cur_c;
    if (cur_p > last_p) {
      // a new value
      cur_c = at(i);
    } else {
      vector<pair<int, char>> starts;
      for (auto p : last_seen) {
        starts.push_back(make_pair(p.second, p.first));
      }

      sort(starts.begin(), starts.end());

      int ans = 0;
      for (int k = 16; k != 0; k /= 2) {
        int cur = ans + k;
        if (cur >= (int) starts.size()) {
          continue;
        }

        if (cnt_kn(starts[cur].first, i - 1) == cnt(starts[cur].first, i)) {
          ans = cur;
        }
      }

      cur_c = starts[ans].second;
    }

    set_pos(i, cur_c);
    last_seen[cur_c] = i;

    last_p = cur_p;
  }

  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << str_ans[i];
  }
  cout << endl;
}