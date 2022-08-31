#include <iostream>

using namespace std;

const int MAX_N = 1e3 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  int ans = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    ans += min(arr[u], arr[v]);
  }
  cout << ans << endl;
}