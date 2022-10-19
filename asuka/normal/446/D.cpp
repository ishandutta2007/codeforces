#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
using db = double;
const int N = 555;
const db EPS = 1e-12;


int n, m, k, len, a[N], deg[N];
db F[N][N], G[N][N << 1];

struct mat {
	db dat[111][111];

	db* operator[](int i) {return dat[i]; }

	mat operator * (mat rhs) {
		mat res;

		rep(i, 0, len - 1) rep(j, 0, len - 1) res[i][j] = 0;

		rep(i, 0, len - 1) rep(j, 0, len - 1) rep(k, 0, len - 1) res[i][k] += dat[i][j] * rhs[j][k];

		return res;
	}
} Base, res;

void Gauss() {
	rep(i, 1, n) {
		int p = i;

		rep(j, i + 1, n) if (fabs(G[j][i]) > fabs(G[p][i])) p = j;


		{
			db u = 1 / G[i][i];

			per(j, i, n + n) G[i][j] *= u;
		}

		rep(j, 1, n) {
			if (i == j) continue;

			db u = G[j][i];

			rep(k, i, n + n) G[j][k] -= u * G[i][k];
		}
	}

	rep(i, 1, n) {
		rep(j, 1, n) {
			G[i][j] = G[i][j + n];
		}
	}
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &k);
	vector<int> v;

	rep(i, 1, n) {
		scanf("%d", &a[i]);

		if (a[i]) v.pb(i);
	}

	len = SZ(v);

	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		F[u][v]++; F[v][u]++;
		deg[u]++; deg[v]++;
	}

	rep(i, 1, n) {
		if (!deg[i]) continue;

		rep(j, 1, n) {
			F[i][j] /= deg[i];
		}

		if (!a[i]) {
			rep(j, 1, n) G[i][j] = F[i][j];
		}
	}

	rep(i, 1, n) rep(j, 1, n) G[i][j] = (i == j) - G[i][j], G[i][j + n] = i == j;

	Gauss();

	rep(i, 0, len - 1) {
		rep(j, 0, len - 1) {
			rep(k, 1, n) {
				Base[i][j] += F[v[i]][k] * G[k][v[j]];
			}
		}

		res[i][i] = 1;
	}

	rep(j, 0, 30) {
		if ((k - 2) >> j & 1)
			res = res * Base;

		Base = Base * Base;
	}

	db ans = 0;

	rep(i, 0, len - 1) ans += G[1][v[i]] * res[i][len - 1];

	printf("%.10lf\n", ans);
	return 0;
}