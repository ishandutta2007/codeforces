#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, r, b;
    cin >> n >> r >> b;
    int big = r/(b+1)+1;
    int small = r/(b+1);
    for (int i = 0; i < r%(b+1); i++) {
      cout << string(big, 'R');
      cout << 'B';
    }
    for (int i = 0; i < b+1-r%(b+1); i++) {
      cout << string(small, 'R');
      if (i < b-r%(b+1)) cout << 'B';
    }
    cout << '\n';
  }
}