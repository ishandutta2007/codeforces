#include <bits/stdc++.h>
#ifdef local
#define Auto "%lld"
#else
#define Auto "%I64d"
#endif
using namespace std;
typedef bool boolean;

#define ll long long
#define pii pair<ll, int>

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

template <typename T, class Comp = vector<T>, class compare = less<T> >
class Heap {
	public:
		priority_queue<T, Comp, compare> Q, D;

		void insert(const T& x) {
			Q.push(x);
		}
		void remove(const T& x) {
			D.push(x);
		}
		T top() {
			while (!Q.empty() && !D.empty() && Q.top() == D.top())
				Q.pop(), D.pop();
			assert(!Q.empty());
			return Q.top();
		}
		void pop() {
			top();
			Q.pop();
		}
		int size() {
			return Q.size() - D.size();
		}
		boolean empty() {
			return !size();
		}
};

const int N = 250005;

int n;
ll cost_all;
vector<pii> G[N];
int dep[N], deg[N];

inline void init() {
	scanf("%d", &n);
	for (int i = 1, u, v, w; i < n; i++) {
		scanf("%d%d%d", &u, &v, &w);
		cost_all += w;
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
}

int fa[N], uf[N], fw[N];
void dfs(int p, int ls, int w) {
	dep[p] = dep[ls] + 1;
	fa[p] = ls, fw[p] = w;
	for (auto& par : G[p]) {
		if (par.first ^ ls) {
			dfs(par.first, p, par.second);
		} 
	}
}

int pre[N], suf[N];
inline void init_list() { // in depth
	vector<int> all (n + 2);
	all[0] = 0, all[n + 1] = n + 1;
	for (int i = 1; i <= n; i++) {
		all[i] = i;
	}
	sort(all.begin() + 1, all.end() - 1, [&] (const int& a, const int& b) {
			return dep[a] < dep[b];		
		});
	pre[0] = 0;
	suf[0] = all[1];
	for (int i = 1; i <= n; i++) {
		pre[all[i]] = all[i - 1];
		suf[all[i]] = all[i + 1];
	}
	pre[n + 1] = all[n];
	suf[n + 1] = n + 1;
}

int id[N];
int active[N];
boolean isfun[N];
int find(int x) {
	return (uf[x] == x) ? (x) : (uf[x] = find(uf[x]));
}
inline void init_rest() {
	for (int i = 0; i <= n; i++) {
		uf[i] = i;
	}
	memset(isfun, true, sizeof(boolean) * (n + 1));
	for (int i = 2; i <= n; i++) {
		active[fa[i]]++;
	}
	vector<int> cnt(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		id[i] = cnt[fa[i]]++;
	}
}

void link_erase(int x) {
	uf[x] = fa[x];
	pre[suf[x]] = pre[x];
	suf[pre[x]] = suf[x];
}

int mx_deg;
class dp_t {
	public:
		Heap<pii, vector<pii>, greater<pii> > Q0;
		Heap<pii> Q1;
		int* wh, fw;

		ll dp0, dif;
		ll o_dp0, o_dif;

		void recalc() {
			while (!Q0.empty() && (Q0.top().first < 0 || (!Q1.empty() && Q0.top() < Q1.top()))) {
				pii a = Q0.top();
				Q0.pop();
				dp0 -= a.first;
				wh[a.second] = 1;
				Q1.insert(a);
			}

			while (!Q1.empty() && Q1.top().first >= 0 && Q0.size() < mx_deg) {
				pii a = Q1.top();
				Q1.pop();
				dp0 += a.first;
				wh[a.second] = 0;
				Q0.insert(a);
			}

			if (Q0.size() == mx_deg && !Q0.empty()) {
				dif = fw - Q0.top().first;
			} else {
				dif = fw;
			}
		}
		void reset() {
			o_dp0 = dp0, o_dif = dif;
		}
		void update(int id, dp_t* dp) {
			dp0 += dp->dp0 - dp->o_dp0;
			if (wh[id] == 0) {
				Q0.remove(pii(dp->o_dif, id));
				Q0.insert(pii(dp->dif, id));
				dp0 -= dp->o_dif, dp0 += dp->dif;
			} else {
				Q1.remove(pii(dp->o_dif, id));
				Q1.insert(pii(dp->dif, id));
			}
		}
		void update(dp_t* dp) {
			dp0 += dp->dp0 - dp->o_dp0;
			dp0 += max(dp->dif, 0ll) - max(dp->o_dif, 0ll);
		}
} f[N];

int main() {
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	init();
	dfs(1, 0, 0);
	init_list();
	init_rest();

	f[0].wh = new int[2];
	pfill(f[0].wh, f[0].wh + 2, 1);
	for (int i = 1; i <= n; i++) {
		f[i].wh = new int[G[i].size()];
		pfill(f[i].wh, f[i].wh + G[i].size(), 1);
		f[i].dp0 = 0, f[i].dif = fw[i], f[i].fw = fw[i];
		f[fa[i]].Q1.insert(pii(fw[i], id[i]));
		f[i].reset();
		deg[i] = G[i].size();
	}
	deg[0] = n + 1;
	printf(Auto, cost_all);
	for (mx_deg = 1; mx_deg <= n - 1; mx_deg++) {
//		cerr << "=========================\n";
		for (int p = pre[n + 1]; p; p = pre[p]) {
			f[p].recalc();
			int q = find(fa[p]);
			if (q == fa[p]) {
				f[q].update(id[p], f + p);
			} else {
				f[q].update(f + p);
			}
			f[p].reset();
//			cerr << p << " " << f[p].dp0 << " " << f[p].dif << '\n';
		}
		for (int p = suf[0]; p <= n; p = suf[p]) {
			if (deg[p] <= mx_deg) {
				if (isfun[p] && !--active[fa[p]] && !isfun[fa[p]]) {
					link_erase(fa[p]);
				}
				isfun[p] = false;
				if (!active[p]) {
					link_erase(p);
				}
			}
		}
//		if (n == 100000) {
//			cout << " " << clock() << "ms\n";
//		}
//		f[0].recalc();
		printf(" "Auto, cost_all - f[0].dp0);
	}
//	cerr << clock() << "ms" << '\n';
	return 0;
}