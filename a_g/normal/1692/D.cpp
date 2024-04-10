#include <bits/stdc++.h>
using namespace std;

const int N = 1440;
bool a[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = 0; i < 24; i++) {
    for (int j = 0; j < 60; j++) {
      if (j%10 == i/10 && j/10 == i%10) {
        a[60*i+j] = 1;
      }
    }
  }

  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int z = 60*(10*(s[0]-'0')+s[1]-'0') + 10*(s[3]-'0')+s[4]-'0';
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 0; i < N/__gcd(x, N); i++) {
      ans += a[(z+i*x)%N];
    }
    cout << ans << '\n';
  }
}