#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    int big = (n+m-1)/m;
    int small = n/m;
    int bigtables = n-m*(n/m);
    int smalltables = m-bigtables;
    int s = 0;
    while (k--) {
      int u = s;
      for (int i = 0; i < bigtables; i++) {
        cout << big << ' ';
        for (int j = 0; j < big; j++) {
          cout << u%n+1 << ' ';
          u = (u+1)%n;
        }
        cout << '\n';
      }
      for (int i = 0; i < smalltables; i++) {
        cout << small << ' ';
        for (int j = 0; j < small; j++) {
          cout << u%n+1 << ' ';
          u = (u+1)%n;
        }
        cout << '\n';
      }
      s = (s+bigtables*big) % n;
    }
    cout << '\n';
  }
}