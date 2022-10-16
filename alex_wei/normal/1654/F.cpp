#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool Mbe;
constexpr int N = 1 << 18;
int n, rk[N], sa[N];
string s;
pair<pair<int, int>, int> p[N];
bool Med;
int main() {
  fprintf(stderr, "%.4lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin >> n >> s;
  for(int i = 0; i < 1 << n; i++) rk[i] = s[i] - 'a';
  for(int w = 1; w < 1 << n; w <<= 1) {
    for(int i = 0; i < 1 << n; i++) p[i] = {{rk[i], rk[i ^ w]}, i};
    sort(p, p + (1 << n));
    for(int i = 0, cnt = 0; i < 1 << n; i++) rk[p[i].second] = cnt, cnt += p[i].first != p[i + 1].first;
  }
  for(int i = 0; i < 1 << n; i++) cout << s[p[0].second ^ i];
  cout << "\n";
  return cerr << "Time: " << 1e3 * clock() / CLOCKS_PER_SEC << " ms\n", 0;
}
/*
2022/7/15
start coding at 16:07
finish debugging at 16:20
*/