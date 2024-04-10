#include <bits/stdc++.h>

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

#define all(a) (a).begin(), (a).end()
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back

#define x first
#define y second

using namespace std;

template<class A, class B> ostream& operator << (ostream &out, const pair<A, B> &p) {
	return out << "(" << p.first << ", " << p.second << ")";
}

template<class A> ostream& operator << (ostream &out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i > 0)
			out << " ";
		out << v[i];
	}
	return out << "]";
}

mt19937 myRand(time(NULL));

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

inline int gett() {
	return clock() * 1000 / CLOCKS_PER_SEC;
}

const ld EPS = 1e-9;
const int INF = int(1e9);
const li INF64 = li(INF) * INF;
const ld PI = 3.1415926535897932384626433832795;

const int N = 100 * 1000 + 555;

int n, m, aa[N], a[N];
int qt[N], qx[N], qy[N];

inline bool read() {
	if(!(cin >> n >> m))
		return false;
	
	forn(i, n)
		assert(scanf("%d", &aa[i]) == 1);
		
	forn(i, m) {
		assert(scanf("%d%d%d", &qt[i], &qx[i], &qy[i]) == 3);
		qx[i]--;
	}
		
	return true;
}

vector<int> vars[4 * N];
vector<li> f[4 * N];
li sumAll[4 * N];

inline void addValF(int k, int pos, int val) {
	sumAll[k] += val;
	for(; pos < sz(f[k]); pos |= pos + 1)
		f[k][pos] += val;
}

inline li sum(int k, int pos) {
	li ans = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		ans += f[k][pos];
		
	return ans;
}

inline li getSumF(int k, int pos) {
	return sumAll[k] - sum(k, pos - 1);
}

li getSumST(int v, int l, int r, int lf, int rg, int val) {
	if(l >= r || lf >= rg)
		return 0;
		
	if(l == lf && r == rg) {
		int pos = int(lower_bound(all(vars[v]), val) - vars[v].begin());
		return getSumF(v, pos);
	}
	
	int mid = (l + r) >> 1;
	
	li ans = 0;
	if(lf < mid)
		ans += getSumST(2 * v + 1, l, mid, lf, min(mid, rg), val);
	if(rg > mid)
		ans += getSumST(2 * v + 2, mid, r, max(lf, mid), rg, val);
		
	return ans;
}

void addValST(int k, int v, int l, int r, int pos, int pos2, int val) {
	if(l >= r)
		return;
		
	if(!k)
		vars[v].pb(pos2);
	else {
		int cpos = int(lower_bound(all(vars[v]), pos2) - vars[v].begin());
		addValF(v, cpos, val);
	}
	
	if(l + 1 == r) {
		assert(l == pos);
		return;
	}
	
	int mid = (l + r) >> 1;
	
	if(pos < mid)
		addValST(k, 2 * v + 1, l, mid, pos, pos2, val);
	else
		addValST(k, 2 * v + 2, mid, r, pos, pos2, val);
}

int pr[N];
set<int> ids[N];

void build(int k, int v, int l, int r) {
	fore(i, l, r)
		if(!k)
			vars[v].pb(pr[i]);
		else {
			int pos = int(lower_bound(all(vars[v]), pr[i]) - vars[v].begin());
			addValF(v, pos, i - pr[i]);
		}
			
	if(l + 1 == r)
		return;
		
	int mid = (l + r) >> 1;
	
	build(k, 2 * v + 1, l, mid);
	build(k, 2 * v + 2, mid, r);
}

inline void eraseSets(int k, int pos) {
	addValST(k, 0, 0, n, pos, pr[pos], -(pos - pr[pos]));
	ids[ a[pos] ].erase(pos);
	
	auto it2 = ids[ a[pos] ].lower_bound(pos);
	
	if(it2 != ids[ a[pos] ].end()) {
		int np = *it2;
		assert(a[np] == a[pos]);
		assert(pr[np] == pos);
		
		addValST(k, 0, 0, n, np, pr[np], -(np - pr[np]));
		
		pr[np] = pr[pos];
		addValST(k, 0, 0, n, np, pr[np], +(np - pr[np]));
	}
	
	a[pos] = -1;
	pr[pos] = -1;
}

inline void insertSets(int k, int pos, int nval) {
	auto it2 = ids[nval].lower_bound(pos);
	assert(it2 == ids[nval].end() || *it2 > pos);
	
	if(it2 != ids[nval].end()) {
		int np = *it2;
		assert(a[np] == nval);
		
		addValST(k, 0, 0, n, np, pr[np], -(np - pr[np]));

		pr[np] = pos;
		addValST(k, 0, 0, n, np, pr[np], +(np - pr[np]));
	}
	
	pr[pos] = -1;
	if(it2 != ids[nval].begin()) {
		auto it1 = it2; it1--;
		assert(*it1 < pos);
		
		pr[pos] = *it1;
	}
	addValST(k, 0, 0, n, pos, pr[pos], +(pos - pr[pos]));
	
	ids[nval].insert(pos);
	a[pos] = nval;
}

inline void precalc() {
	forn(v, 4 * N) {
		sort(all(vars[v]));
		vars[v].erase(unique(all(vars[v])), vars[v].end());
		
		f[v].assign(sz(vars[v]), 0);
		sumAll[v] = 0;
	}
}

inline void solve() {
	forn(k, 2) {
		if(k) precalc();
		
		forn(i, N)
			ids[i].clear();
		forn(i, n)
			a[i] = aa[i];
			
		vector<int> ls(n + 1, -1);
		forn(i, n) {
			pr[i] = ls[ a[i] ];
			ls[ a[i] ] = i;
			
			ids[ a[i] ].insert(i);
		}
		
		build(k, 0, 0, n);
		
//		cerr << k << " " << clock() << endl;
		
		forn(q, m) {
			if(qt[q] == 1) {
				eraseSets(k, qx[q]);
				insertSets(k, qx[q], qy[q]);
			} else
				if(k) printf("%I64d\n", getSumST(0, 0, n, qx[q], qy[q], qx[q]));
		}
		
//		cerr << k << " " << clock() << endl;
	}
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t = gett();
#endif

	srand(time(NULL));
	cout << fixed << setprecision(10);

	while(read()) {
		solve();	
		
#ifdef _DEBUG
		cerr << "TIME = " << gett() - t << endl;
		t = gett();
#endif
	}
	return 0;
}