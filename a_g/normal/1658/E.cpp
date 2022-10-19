#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const int INF = 1e9;
int x[N*N], y[N*N];
bool win[N][N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      x[a] = i;
      y[a] = j;
    }
  }
  int a = -INF; // max x+y
  int b = INF; // min x+y
  int c = -INF; // max x-y
  int d = INF; // min x-y
  for (int z = n*n; z >= 1; z--) {
    int i = x[z];
    int j = y[z];
    if (i+j >= a-k && i+j <= b+k && i-j >= c-k && i-j <= d+k) {
      win[i][j] = 1;
      a = max(a, i+j);
      b = min(b, i+j);
      c = max(c, i-j);
      d = min(d, i-j);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << (win[i][j] ? 'M' : 'G');
    }
    cout << '\n';
  }
}