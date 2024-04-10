#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 6;

#define ll long long

const int fac[6] = {1, 1, 2, 6, 24, 120};

int n, m;
int bit[128];

class init_t {
	public:
		init_t() {
			bit[0] = 0;
			for (int i = 1; i < 128; i++)
				bit[i] = bit[i >> 1] + (i & 1);
		}
} init_t;

typedef class perm_t {
	public:
		int p[5];

		perm_t() {	}
		perm_t(int n) {
			for (int i = 0; i < n; i++)
				p[i] = i;
		}
		int& operator [] (int pos) {
			return p[pos];
		}
		perm_t operator * (perm_t b) {
			perm_t rt;
			for (int i = 0; i < m; i++)
				rt[i] = b[p[i]];
			return rt;
		}
		int rank() {
			int rt = 0, vis = 0;
			for (int i = 0; i < m; i++) {
				rt += (p[i] - bit[vis & ((1 << p[i]) - 1)]) * fac[m - i - 1];
				vis |= 1 << p[i];
			}
			return rt;
		}
		void read() {
			for (int i = 0; i < m; i++) {
				scanf("%d", p + i);
				--p[i];
			}
		}
} perm_t;

int a[N];
int h[130];
bitset<130> vis;
vector<int> S, Sb;

int tab[130][130];
vector<perm_t> SP;
void dfs(int d, int vis) {
	static perm_t p;
	if (d == m) {
		SP.push_back(p);
		return;
	}
	for (int i = 0; i < m; i++) {
		if (!((vis >> i) & 1)) {
			p[d] = i;
			dfs(d + 1, vis | (1 << i));
		}
	}
}

void join(int p) {
	vector<int> newS;
	for (auto& q : S) {
		int rk = tab[p][q];
		if (!vis.test(rk)) {
			newS.push_back(rk);
			vis.set(rk);
		}
	}
	Sb.push_back(p);
	for (int i = 0; i < (signed) newS.size(); i++) {
		for (auto& q : Sb) {
			int rk = tab[newS[i]][q];
			if (!vis.test(rk)) {
				newS.push_back(rk);
				vis.set(rk);
			}
		}
		S.push_back(newS[i]);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	dfs(0, 0);
	for (int i = 0; i < (signed) SP.size(); i++) {
		for (int j = 0; j < (signed) SP.size(); j++) {
			tab[i][j] = (SP[i] * SP[j]).rank();
		}
	}
	perm_t b;
	for (int i = 1; i <= n; i++) {
		b.read();
		a[i] = b.rank();
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int ps = i, nps;
		S.clear();
		Sb.clear();
		vis.reset();
		vis.set(0);
		S.push_back(0);
		do {
			join(a[ps]);
			nps = 0;
			for (int j = 0; j < fac[m]; j++) {
				if (!vis.test(j)) {
					nps = max(nps, h[j]);
				}
			}
			ans += 1ll * (ps - nps) * S.size();
			ps = nps;
		} while (ps);
		h[a[i]] = i;
	}
	printf("%lld\n", ans);
	return 0;
}