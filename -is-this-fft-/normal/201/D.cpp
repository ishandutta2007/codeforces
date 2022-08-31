#include <iostream>
#include <map>
#include <vector>

using namespace std;

int pc (int x) {
  return (x * (x - 1)) / 2;
}

const int INF = 1e9 + 5;
const int MAX_N = 15;
const int MAX_L = 5e5 + 5;

vector<int> dp [1 << MAX_N];
int nxt [MAX_N][MAX_L];

int add_invs (int mask, int k) {
  int small_mask = (1 << k) - 1;
  return __builtin_popcount(mask & ~small_mask);
}

int main () {
  int n;
  cin >> n;

  map<string, int> id;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    id[s] = i;
  }

  for (int mask = 0; mask < 1 << n; mask++) {
    dp[mask] = vector<int> (pc(__builtin_popcount(mask)) + 1);
  }

  int qc;
  cin >> qc;

  pair<int, int> ans = make_pair(INF, -1);
  for (int t = 0; t < qc; t++) {
    vector<int> arr;

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      string s;
      cin >> s;

      if (id.count(s)) {
        arr.push_back(id[s]);
      }
    }
    m = arr.size();

    for (int i = 0; i < n; i++) {
      nxt[i][m] = m;
      for (int j = m - 1; j >= 0; j--) {
        if (arr[j] == i) {
          nxt[i][j] = j;
        } else {
          nxt[i][j] = nxt[i][j + 1];
        }
      }
    }
    
    for (int mask = 0; mask < 1 << n; mask++) {
      fill(dp[mask].begin(), dp[mask].end(), m);
    }

    dp[0][0] = 0;
    for (int mask = 0; mask < 1 << n; mask++) {
      for (int invc = 0; invc < (int) dp[mask].size(); invc++) {
        for (int k = 0; k < n; k++) {
          if (mask & 1 << k) {
            continue;
          }

          int nxt_mask = mask | 1 << k;
          int nxt_invc = invc + add_invs(mask, k);
          dp[nxt_mask][nxt_invc] = min(dp[nxt_mask][nxt_invc], nxt[k][dp[mask][invc]]);
        }
      }
    }

    int cur_ans = INF;
    const auto &last_dp = dp[(1 << n) - 1];
    for (int i = 0; i < (int) last_dp.size(); i++) {
      if (last_dp[i] < m) {
        cur_ans = i;
        break;
      }
    }

    ans = min(ans, make_pair(cur_ans, t));
  }

  if (ans.first == INF) {
    cout << "Brand new problem!" << endl;
  } else {
    cout << 1 + ans.second << endl;
    int sim = pc(n) - ans.first + 1;
    cout << "[:";
    for (int i = 0; i < sim; i++) {
      cout << "|";
    }
    cout << ":]" << endl;
  }
}