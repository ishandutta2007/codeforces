// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 100005;
const int L = 17;
const ll inf = 1e16;

vector<int> d[N];
ll sum[N], phi[N], mu[N];
ll f[18][N];

int askl = 1, askr = 1;
ll res = 1;
ll calcL() {
  return sum[askr / askl];
}
ll calcR() {
  ll res = 0;
  for (auto x: d[askr]) {
    if (x >= askl)
      res += phi[askr / x];
  }
  return res;
}
inline ll c(int l, int r) {
  while (askl > l) --askl, res += calcL();
  while (askr < r) ++askr, res += calcR();
  while (askl < l) res -= calcL(), ++askl;
  while (askr > r) res -= calcR(), --askr;
  return res; 
}
void dfs(int k, int l, int r, int L, int R) {
  if (l > r) return ;
  int mid = l + r >> 1;
  int p = mid;
  f[k][mid] = f[k - 1][mid];
  for (int i = min(mid - 1, R); i >= L; i--) {
    ll v = f[k - 1][i] + c(i + 1, mid);
    if (f[k][mid] > v) f[k][mid] = v, p = i;
  }
  dfs(k, l, mid - 1, L, p);
  dfs(k, mid + 1, r, p, R);
}

void init() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i)
      d[j].pb(i);
  }
  for (int i = 1; i < N; i++) {
    phi[i] += i;
    sum[i] = sum[i - 1] + phi[i];
    for (int j = i + i; j < N; j += i) {
      phi[j] -= phi[i];
    }
  }
  for (int i = 1; i < N; i++) f[0][i] = inf;
  for (int k = 1; k <= L; k++) dfs(k, 0, N - 1, 0, N - 1);
}

int main() {
  init();
  int T = read();
  while (T--) {
    int n = read(), k = read();
    if (k > L) {
      print(n, '\n');
    } else {
      print(f[k][n], '\n');
    }
  }
  return 0;
}