#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Tree;

#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

#define read1(a) int a; scanf("%d", &a)
#define read2(a,b) int a,b; scanf("%d %d", &a, &b)
#define read3(a,b,c) int a,b,c; scanf("%d %d %d", &a, &b, &c)
#define read(n,arr) int arr[n]; f0r(i,n){ scanf("%d", &arr[i]); }
#define print1(a) printf("%d \n", a)
#define print2(a, b) printf("%d %d \n", a, b)
#define print3(a, b, c) printf("%d %d %d \n", a, b, c)
#define print(v) for (int i : v) { printf("%d ", i); } printf("\n")

#define debug printf("asdf\n");
#define newl printf("\n");
#define usaco(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void io(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    fast_io();
}
const long double inf = 1e18;
struct chtDynamic {
	struct line {
		long long m, b; long double x;
		long long val; bool isQuery;
		line(long long _m = 0, long long  _b = 0) :
			m(_m), b(_b), val(0), x(-inf), isQuery(false) {}

		long long eval(long long x) const { return m * x + b;	}
		bool parallel(const line &l) const { return m == l.m; }
		long double intersect(const line &l) const {
			return parallel(l) ? inf : 1.0 * (l.b - b) / (m - l.m);
		}
		bool operator < (const line &l) const {
			if(l.isQuery) return x < l.val;
			else return m < l.m;
		}
	};

	set<line> hull;
	typedef set<line> :: iterator iter;

	bool cPrev(iter it) { return it != hull.begin(); }
	bool cNext(iter it) { return it != hull.end() && next(it) != hull.end(); }

	bool bad(const line &l1, const line &l2, const line &l3) {
		return l1.intersect(l3) <= l1.intersect(l2);
	}
	bool bad(iter it) {
		return cPrev(it) && cNext(it) && bad(*prev(it), *it, *next(it));
	}

	iter update(iter it) {
		if(!cPrev(it)) return it;
		long double x = it -> intersect(*prev(it));
		line tmp(*it); tmp.x = x;
		it = hull.erase(it);
		return hull.insert(it, tmp);
	}

	void addLine(long long m, long long b) {
		line l(m, b);
		iter it = hull.lower_bound(l);
		if(it != hull.end() && l.parallel(*it)) {
			if(it -> b < b) it = hull.erase(it);
			else return;
		}

		it = hull.insert(it, l);
		if(bad(it)) return (void) hull.erase(it);

		while(cPrev(it) && bad(prev(it))) hull.erase(prev(it));
		while(cNext(it) && bad(next(it))) hull.erase(next(it));

		it = update(it);
		if(cPrev(it)) update(prev(it));
		if(cNext(it)) update(next(it));
	}

	long long query(long long x) const {
	if(hull.empty()) return -inf;
		line q; q.val = x, q.isQuery = 1;
		iter it = --hull.lower_bound(q);
		return it -> eval(x);
	}
} ds;
vector<ll> a;
vector<ll> b;
const int MAX = 1e5+5;
ll dp[MAX];
static chtDynamic h;
int main(){
    fast_io();
    int n;
    cin >> n;
    f0r(i, n){
        ll d;
        cin >> d;
        a.eb(d);
    }
    f0r(i, n){
        ll d;
        cin >> d;
        b.eb(d);
    }
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    dp[0] = 0;
    h.addLine(-b[0], -dp[0]);
    f1r(i, 1 ,n){
        dp[i] = -h.query(a[i]);
        h.addLine(-b[i], -dp[i]);
    }
    cout << dp[n-1] << endl;
    return 0;
}