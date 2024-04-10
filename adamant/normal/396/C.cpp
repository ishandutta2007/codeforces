#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long       LL;
typedef pair<int, int>  PII;
typedef pair<LL, LL>    PLL;
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<PII>     VPII;
typedef vector<VI>      VVI;
typedef vector<VPII>    VVPII;
#define MM(a,x) memset(a,x,sizeof(a));
#define ALL(x)  (x).begin(), (x).end()
#define P(x)	 cerr<<"["#x<<" = "<<(x)<<"]"<<endl;
#define P2(x,y)	 cerr<<"["#x" = "<<(x)<<", "#y" = "<<(y)<<"]"<<endl;
#define P3(x,y,z)cerr<<"["#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<"]"<<endl;
#define PP(x,i)	 cerr<<"["#x<<i<<" = "<<x[i]<<"]"<<endl;
#define TM(a,b)	 cerr<<"["#a" -> "#b": "<<1e3*(b-a)/CLOCKS_PER_SEC<<"ms]\n";
#define UN(v)   sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define x first
#define y second
struct _ {_() {ios_base::sync_with_stdio(0);}} _;
template<class A, class B> ostream& operator<<(ostream &o, pair<A, B> t) {o << "(" << t.x << ", " << t.y << ")"; return o;}
template<class T> string tostring(T x, int len = 0, char c = '0') {stringstream ss; ss << x; string r = ss.str(); if(r.length() < len) r = string(len - r.length(), c) + r; return r;}
template<class T> void PV(T a, T b, int n = 0, int w = 0, string s = " ") {int c = 0; while(a != b) {cout << tostring(*a++, w, ' '); if(a != b && (n == 0 || ++c % n)) cout << s; else cout << "\n"; cout.flush();}}
template<class T> inline bool chmin(T &a, T b) {return a > b ? a = b, 1 : 0;}
template<class T> inline bool chmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 311111;


template<class T>
struct BIT {
	static const int Z = N;
	T a[Z + 1];
	int n;

	void init(int n = Z) {this->n = n; memset(a, 0, sizeof(T) * (n + 1));}
	BIT(int n = Z) {init(n);}

	void add(int x, T v) {
		for(int i = x; i <= n; i += i & -i) {a[i] += v;}
	}

	T sum(int x) {
		T res = 0;
		for(int i = x; i > 0; i -= i & -i) {res += a[i];}
		return res;
	}

	T sum(int L, int R) {return sum(R) - sum(L - 1);}

	T get(int x) {return sum(x) - sum(x - 1);}
	void set(int x, T v) {add(x, v - get(x));}
};

BIT<LL> bt[2];

int n;
int p[N];

VI g[N];

int depth[N], father[N], sz[N];
int startCnt[N], endCnt[N];
int timeCnt;

void dfsTree(int u, int par, int dep) {
	father[u] = par;
	depth[u] = dep;
	startCnt[u] = ++timeCnt;
	for(int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if(v == par) continue;
		dfsTree(v, u, dep + 1);
	}
	endCnt[u] = timeCnt;
	sz[u] = endCnt[u] - startCnt[u] + 1;
}

void initTree(int root = 0) {
	timeCnt = 0;
	MM(depth, 0);
	MM(father, -1);
	dfsTree(root, -1, 0);
}

LL A[N];
LL B[N];
int main() {
cin.tie(0);
	cin >> n;
	p[0] = -1;
	for(int i = 1; i < n; i++) cin >> p[i];
	for(int i = 1; i < n; i++) g[p[i] - 1].pb(i);

	initTree(0);

	VI res;

	int q;
	cin >> q;
	while(q--) {
		int op;
		cin >> op;
		if(op == 1) {
			int v, x, k;
			cin >> v >> x >> k;
			v--;
			int from = startCnt[v], to = endCnt[v];
			int t = (x + (LL) depth[v] * k) % mod;
			for(int i = from; i <= n; i += i & -i) A[i] += t, B[i] += k;
			for(int i = to + 1; i <= n; i += i & -i) A[i] -= t, B[i] -= k;
			/*
			bt[0].add(from, t);
			bt[0].add(to + 1, -t);
			bt[1].add(from, k);
			bt[1].add(to + 1, -k);
			*/
		} else {
			int v;
			cin >> v;
			v--;
			int i = startCnt[v];
			LL s0 = 0, s1 = 0;
			for(int j = i; j > 0; j -= j & -j) s0 += A[j], s1 += B[j];
			//LL t = bt[0].sum(i) - depth[v] * (bt[1].sum(i) % mod);
			LL t = s0 - depth[v] * (s1 % mod);
			t = (t % mod + mod) % mod;
			res.pb(t);
		}
	}
	for(int i = 0; i < res.size(); i++) printf("%d\n", res[i]);
	return 0;
}