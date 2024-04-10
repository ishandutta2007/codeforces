#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;

char s[N];
vector <ll> b;
string p = "#1337";
int t; ll n, tri[N], f[N][5];

int main() {
  for (int i = 1; i < N; ++i) {
    tri[i] = i * 1LL * (i - 1) / 2LL;
  }
  cin >> t;
  while (t--) {
    cin >> n;
    ll _n = n;
    while (n) {
      ll at = 1;
      while (tri[at + 1] <= n) ++at;
      b.emplace_back(at);
      n -= tri[at];
    }
    // for (int i = b.size() - 1; i >= 0; --i) {
    //   cout << b[i] << " " << c[i] << endl;
    // }
    s[1] = '1';
    int len = 1, cur = 0;
    while (!b.empty()) {
      ll x = b.back(); b.pop_back();
      while (cur < x) s[++len] = '3', ++cur;
      s[++len] = '7';
    }
    s[len + 1] = 0; puts(s + 1);
    // assert(len <= 100000);
    // // f[0][0] = 1;
    // // for (int i = 1; i <= len; ++i) {
    // //   for (int j = 1; j <= 4; ++j) {
    // //     f[i][j] = f[i - 1][j];
    // //     if (s[i] == p[j]) f[i][j] += f[i - 1][j - 1];
    // //   }
    // // }
    // // // cout << f[len][4] << endl;
    // // assert(f[len][4] == _n);
  }
  return 0;
}