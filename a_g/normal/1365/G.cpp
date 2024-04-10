#include <bits/stdc++.h>
using namespace std;

const int K = 13;
int id[2000];
long long ans[2000];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int c = 0;
  for (int i = 0; i < (1<<K); i++) {
    if (__builtin_popcount(i) == K/2) {
      id[c++] = i;
    }
  }
  int n;
  cin >> n;
  for (int bit = 0; bit < K; bit++) {
    c = 0;
    for (int i = 1; i <= n; i++) {
      if ((id[i]>>bit)&1) {
        c++;
      }
    }
    if (c) {
      cout << "? " << c;
      for (int i = 1; i <= n; i++) {
        if ((id[i]>>bit)&1) {
          cout << ' ' << i;
        }
      }
      cout << endl;
      long long x;
      cin >> x;
      for (int i = 1; i <= n; i++) {
        if (!((id[i]>>bit)&1)) {
          ans[i] |= x;
        }
      }
    }
  }
  cout << '!';
  for (int i = 1; i <= n; i++) {
    cout << ' ' << ans[i];
  }
  cout << endl;
}