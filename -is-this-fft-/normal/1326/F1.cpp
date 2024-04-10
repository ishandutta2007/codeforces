#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 15;

vector<ll> dp [1 << MAX_N][MAX_N];

int conn [MAX_N][MAX_N];
ll ans [1 << MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;

      if (c == '1') conn[i][j] = 1;
    }
  }

  for (int i = 0; i < 1 << n; i++) {
    for (int j = 0; j < n; j++) {
      if (i & 1 << j) {
	dp[i][j] = vector<ll> (1 << (__builtin_popcount(i) - 1), 0);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    dp[1 << i][i][0] = 1;
  }
  
  for (int mask = 1; mask < 1 << n; mask++) {
    vector<int> us;
    vector<int> them;
    for (int i = 0; i < n; i++) {
      if (mask & 1 << i) {
	us.push_back(i);
      } else {
	them.push_back(i);
      }
    }

    int ppc = __builtin_popcount(mask);
    for (int u : us) {
      for (int str = 0; str < 1 << (ppc - 1); str++) {
	for (int v : them) {
	  if (conn[u][v]) {
	    dp[mask | 1 << v][v][2 * str + 1] += dp[mask][u][str];
	  } else {
	    dp[mask | 1 << v][v][2 * str] += dp[mask][u][str];
	  }
	}
      }
    }
  }

  int state = (1 << n) - 1;
  for (int i = 0; i < n; i++) {
    for (int str = 0; str < 1 << (n - 1); str++) {
      ans[str] += dp[state][i][str];
    }
  }

  for (int i = 0; i < 1 << (n - 1); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}