#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
inline int read() {
  int x = 0;
  char s = getchar();
  while(!isdigit(s)) s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return x;
}
inline void print(int x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int N = 500 + 5;
int n, m, k, v[N];
pii query(vector<int> ind) {
  sort(ind.begin(), ind.end());
  cout << "? ";
  for(int it : ind) cout << it << " ";
  cout << endl;
  int pos, v;
  cin >> pos >> v;
  return make_pair(pos, v);
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  /*
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  */
  cin >> n >> k;
  vector<int> ind(k);
  for(int i = 0; i < k; i++) ind[i] = i + 1;
  pii info = query(ind);
  int pos = info.first, val = info.second;
  ind[pos - 1] = n;
  int less = query(ind).second < val;
  ind[pos - 1] = pos;
  for(int i = 1; i <= k; i++) {
    if(i == pos) continue;
    ind[i - 1] = n;
    int diff = query(ind).second != val;
    ind[i - 1] = i;
    v[i] = less ^ diff;
  }
  int ans = 1;
  for(int i = 1; i <= k; i++) ans += v[i];
  cout << "! " << ans << endl;
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/9
author: Alex_Wei
start coding at 20:11
finish debugging at 20:21
*/