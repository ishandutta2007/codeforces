///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

const int mod = 7*17*(1<<23) + 1;
const int N = 4096;
const int K = 75;
vector<int> A1[N], A2[N];
int a[N][N], b[N][N];
bool ma[N], mb[N];
ll sa1[K], sa2[K];
int n1, n2, k;

#define min(x, y) ((x)<(y)?(x):(y))
#define smod(x, y) do {                   \
	unsigned int __a = (y);           \
	unsigned int __b = __a - mod;     \
	unsigned int __c = min(__a, __b); \
	(x) = __c;                        \
} while (0)

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n1 >> n2 >> k;
	for (int cnt : {0, 1}) {
		int n = cnt? n2: n1;
		auto sa = cnt? sa2: sa1;
		auto A = cnt? A2: A1;
		Loop (i,0,n-1) {
			int v, u;
			cin >> v >> u;
			--v; --u;
			//v=i; u=i+1;
			A[v].push_back(u);
			A[u].push_back(v);
		}
		Loop (i,0,N) Loop (j,0,N)
			a[i][j] = 0;
		Loop (i,0,n) {
			a[i][i] = 1;
		}
		sa[0] = n;
		memset(ma, 1, N);
		Loop (i,0,k) {
			#define Do(a, b, ma, mb) do { \
				memset(mb, 0, N); \
				Loop (v,0,n) for (int u : A[v]) { \
					if (!ma[u]) \
						continue; \
					if (mb[v]) { \
						Loop (w,0,n) \
							smod(b[v][w], b[v][w] + a[u][w]); \
					} else { \
						Loop (w,0,n) \
							smod(b[v][w], a[u][w]); \
						mb[v] = 1; \
					} \
				} \
				Loop (j,0,n) \
					if (mb[j]) \
						smod(sa[i+1], sa[i+1] + b[j][j]); \
			} while (0)
			if (i&1)
				Do(b, a, mb, ma);
			else
				Do(a, b, ma, mb);
		}
	}

	// a[i][j] = C(i, j) from now
	memset(a, 0, 4*N*N);
	a[0][0] = 1;
	Loop (i,1,N) {
		a[i][0] = a[i][i] = 1;
		Loop (j,1,i)
			smod(a[i][j], a[i-1][j] + a[i-1][j-1]);
	}

	ll ans = 0;
	Loop (i,0,k+1) {
		//cout << sa1[i] << ' ' << sa2[i] << '\n';
		ans += sa1[i]*sa2[k-i] % mod * a[k][i];
		ans %= mod;
	}
	cout << ans << '\n';
}