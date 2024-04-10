#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

int a [MAX_N];
int b [MAX_N];
int nxt [MAX_N];

int vis [MAX_N];

int dfs (int u) {
  vis[u] = 1;

  int ans = 1;
  if (!vis[nxt[u]]) {
    ans += dfs(nxt[u]);
  }

  return ans;
}

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i]--;
  }

  for (int i = 0; i < n; i++) {
    nxt[a[i]] = b[i];
  }

  for (int i = 0; i < n; i++) {
    vis[i] = 0;
  }

  int lo = 0, hi = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      int cycsz = dfs(i);

      lo += cycsz / 2;
      hi += cycsz / 2; 
    }
  }

  ll ans = 0;
  for (int i = 1; i <= lo; i++) {
    ans -= i;
  }

  for (int i = n; i > n - hi; i--) {
    ans += i;
  }

  cout << 2 * ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++)
    solve();
}