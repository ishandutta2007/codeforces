#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int MAX_N = 5e3 + 5;

ll arr [MAX_N];
ll pref [MAX_N];

bool dp [MAX_N][MAX_N]; // dp[k][i] - min h if we have k blocks ending at i
int upd [MAX_N][MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  map<ll, int> ppos;
  for (int i = 1; i <= n; i++) {
    pref[i] = arr[i] + pref[i - 1];
    ppos[pref[i]] = i;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      upd[k][i] = -1;
    }
  }

  upd[1][1] = 0;
  for (int k = 1; k <= n; k++) {
    int j = -1; // rightmost j that works
    for (int i = k; i <= n; i++) {
      j = max(j, upd[k][i]);

      if (j == -1) {
        continue;
      }

      auto cur = pref[i] - pref[j];
      dp[k][i] = true;
      auto nxtit = ppos.lower_bound(cur + pref[i]);
      if (nxtit != ppos.end()) {
        int nxt = nxtit->second;
        upd[k + 1][nxt] = max(upd[k + 1][nxt], i);
      }
    }
  }

  for (int k = n; k >= 1; k--) {
    if (dp[k][n]) {
      cout << n - k << endl;
      return 0;
    }
  }
}