#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

ll arr [MAX_N];
ll cost [MAX_N];
ll rcost [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 2; i <= n; i++) {
    cost[i] = max(0LL, arr[i - 1] - arr[i]);
    rcost[i] = max(0LL, arr[i] - arr[i - 1]);

    cost[i] += cost[i - 1];
    rcost[i] += rcost[i - 1];
  }

  for (int i = 0; i < m; i++) {
    int s, t;
    cin >> s >> t;

    if (s < t) {
      cout << cost[t] - cost[s] << '\n';
    } else {
      cout << rcost[s] - rcost[t] << '\n';
    }
  }
}