#include <bits/stdc++.h>
using namespace std;

const int N = 18;
long long mx[2][1<<N], mxr[2][1<<N], mxl[2][1<<N], sum[2][1<<N];
int a[1<<N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < (1<<n); i++) {
    cin >> a[i];
    sum[0][i] = a[i];
    if (a[i] > 0) {
      mx[0][i] = a[i];
      mxr[0][i] = a[i];
      mxl[0][i] = a[i];
    }
  }

  for (int i = 0; i < n; i++) {
    int u = i&1;
    for (int j = 0; j < (1<<n); j++) {
      int z = 1<<i;
      mx[1-u][j] = max({mx[u][j], mx[u][j^z], mxr[u][j]+mxl[u][j^z]});
      mxl[1-u][j] = max(mxl[u][j], sum[u][j]+mxl[u][j^z]);
      mxr[1-u][j] = max(mxr[u][j^z], sum[u][j^z]+mxr[u][j]);
      sum[1-u][j] = sum[u][j]+sum[u][j^z];
    }
  }

  int q;
  cin >> q;
  int cur = 0;
  while (q--) {
    int k;
    cin >> k;
    cur ^= (1<<k);
    cout << mx[n&1][cur] << '\n';
  }
}