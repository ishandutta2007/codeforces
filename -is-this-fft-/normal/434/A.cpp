#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];
vector<int> pos [MAX_N];
int m;

ll solve (int x) {
  ll ans = 0;
  
  vector<int> nbs;
  for (int u : pos[x]) {
    if (u > 0 && arr[u - 1] != x) {
      nbs.push_back(arr[u - 1]);
    }
    
    if (u < m - 1 && arr[u + 1] != x) {
      nbs.push_back(arr[u + 1]);
    }
  }

  sort(nbs.begin(), nbs.end());
  for (int y : nbs) {
    ans -= abs(x - y);
  }

  int nx = 1;
  if (!nbs.empty()) {
    nx = nbs[(int) nbs.size() / 2];
  }

  for (int y : nbs) {
    ans += abs(nx - y);
  }

  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> arr[i];
    pos[arr[i]].push_back(i);
  }

  ll base = 0;
  for (int i = 0; i < m - 1; i++) {
    base += abs(arr[i + 1] - arr[i]);
  }

  ll ans = base;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, base + solve(i));
  }

  cout << ans << endl;
}