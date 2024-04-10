#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+2;
bool vis[N];
int a[N], t[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      a[i] = i-k;
    }
    int v = 0, time = 0;
    while (!vis[v]) {
      vis[v] = 1;
      t[v] = time++;
      v = a[v];
    }
    cout << time-t[v] << '\n';
    fill(vis, vis+n, 0);
    while (!vis[v]) {
      cout << v+1 << ' ';
      vis[v] = 1;
      v = a[v];
    }
    fill(vis, vis+n, 0);
    cout << '\n';
  }
}