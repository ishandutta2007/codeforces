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

const int N = 16;
const int inf = 1e9;

namespace make {
void sol(int *a, int n) {
    int u = 1 << n;
		std::vector<int> sv;
		std::vector<int> dl;
		std::vector<int> h(u * 2, 0);
		std::vector<std::vector<int>> f(n + 1, std::vector<int>(u * 2, 0));
		std::vector<std::vector<int>> g(n + 1, std::vector<int>(u * 2, 0));
		for (int l = 0; l < n; l++) {
			bool found = false;
			for (int s = 0; s < u; s++) {
				if (__builtin_popcount(s) == l) {
					sv.clear(), sv.emplace_back(0);
					dl.clear();
					for (int i = 0; i < n; i++) {
						if (s >> i & 1) {
							dl.emplace_back(i);
						} else {
							sv.emplace_back(i);
						}
					}
					int uu = 1 << (int)dl.size();
					for (int i = 0; i < uu; i++) {
						h[i] = 0;
						for (int j = 0; j < (int)dl.size(); j++) {
							if (i >> j & 1) {
								h[i] += a[dl[j]];
							}
						}
					}
					f[0][0] = 0;
					for (int i = 1; i < uu; i++) {
						f[0][i] = inf;
					}
					for (int i = 1; i < (int)sv.size(); i++) {
						for (int j = 0; j < uu; j++) {
							f[i][j] = inf;
							if (a[sv[i]] > f[i - 1][j]) {
								f[i][j] = a[sv[i]];
								g[i][j] = 0;
							} else {
								for (int k = j; k; --k &= j) {
									if (a[sv[i]] + h[k] > f[i - 1][j ^ k] && a[sv[i]] + h[k] < f[i][j]) {
										f[i][j] = a[sv[i]] + h[k];
										g[i][j] = k;
									}
								}
							}
						}
					}
					if (f[(int)sv.size() - 1][uu - 1] != inf) {
						found = true;
						break;
					}
				}
			}
			if (found) {
				// std::cout << l << "\n";
				std::vector<int> p(n);
				std::iota(p.begin(), p.end(), 0);
				int k = 1 << (int)dl.size();
				--k;
				for (int i = (int)sv.size() - 1; i > 0; --i) {
					for (int j = 0; j < (int)dl.size(); j++) {
						if (g[i][k] >> j & 1) {
							std::cout << p[dl[j]] + 1 << " " << p[sv[i]] + 1 << "\n";
							for (int t = dl[j]; t < n; ++t) {
								--p[t];
							}
						}
					}
					k ^= g[i][k];
				}
				break;
			}
		}
}
}

// dp[mask][num][pos]
int go[1 << N][N];
int dp[1 << N][N + 1][N + 1], sum[1 << N];
int a[N], n;

void solve() {
  n = read();
  for (int i = 0; i < n; i++) a[i] = read();
  int all = 1 << n;
  for (int i = 0; i < all; i++) sum[i] = 0;
  for (int i = 1; i < all; i++) {
    int t = __builtin_ctz(i);
    sum[i] = sum[i ^ 1 << t] + a[t];
    // printf("sum[%d] = %d\n", i, sum[i]);
  }
  for (int i = 0; i < all; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++)
        dp[i][j][k] = 1e9;
  dp[0][0][0] = 0;
  for (int S = 0; S < all; S++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dp[S][i][j] == 1e9) continue;
        // printf("dp[%d][%d][%d] = %d\n", S, i, j, dp[S][i][j]);
        int lef = (all - 1) ^ S;
        for (int T = lef; T; T = (T - 1) & lef) {
          if (sum[T] > dp[S][i][j] && go[T][j] != -1)
            ckmin(dp[S ^ T][i + 1][go[T][j] + 1], sum[T]);
        }
      }
    }
  }
  int ans = 1e9;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      if (dp[all - 1][i][j] != 1e9)
        // printf("dp[%d][%d][%d] = %d\n", all - 1, i, j, dp[all - 1][i][j]),
        ckmin(ans, n - i);
  print(ans, '\n');
  make::sol(a, n);
}

int main() {
  for (int i = 0; i < 1 << N; i++) {
    int qwq = -1;
    for (int j = N - 1; j >= 0; j--) {
      if (i >> j & 1) qwq = j;
      go[i][j] = qwq;
    }
  }
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}