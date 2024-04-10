#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, C;
  cin >> n >> C;
  vector<long long> pow(C+1);
  for (int i = 0; i < n; i++) {
    int c, d, h;
    cin >> c >> d >> h;
    pow[c] = max(pow[c], 1LL*d*h);
  }
  for (int i = 1; i <= C; i++) {
    pow[i] = max(pow[i], pow[i-1]);
    for (int k = 2; i*k <= C; k++) {
      int j = i*k;
      pow[j] = max(pow[j], pow[i]*k);
    }
  }
  int m;
  cin >> m;
  while (m--) {
    long long D, H;
    cin >> D >> H;
    long long x = D*H;
    auto it = lower_bound(pow.begin(), pow.end(), x+1);
    if (it == pow.end()) {
      cout << "-1 ";
    }
    else {
      cout << it-pow.begin() << " ";
    }
  }
  cout << '\n';
}