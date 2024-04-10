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

const double PI = 4 * atan(1);

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
#define vpi vector<pair<int, int>>

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

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
const int MAX = 1e5+5;
const int MAXP = 100 + 5;
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
        m = -m;
        b = -b;
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
pair<ll, ll> f(pair<ll, ll> a, pair<ll, ll> b) {
    /* point of intersection */
    ll x = ((ll)(b.s-a.s))/(a.f-b.f);
    ll y = a.f * x + a.s;
    return mp(x, y);
}

struct cht {
    vector<ll> pts;
    vector<pair<ll, ll> > taken;

    void addline(pair<ll, ll> i) {
        if (taken.size() <= 1) {
            if (taken.empty()) { taken.pb(i); }
            else {
                if (i.f == taken.back().f) {
                    if (taken.back().s > i.s) {
                        taken.pop_back();
                        taken.pb(i);
                    }
                }
                else {
                    pts.pb(f(i, taken.back()).f);
                    taken.pb(i);
                }
            }
        }
        else {
            if (i.f == taken.back().f) {
                if (taken.back().s > i.s) {
                    taken.pop_back(); pts.pop_back();
                    pts.pb(f(i, taken.back()).f);
                    taken.pb(i);
                }
            }
            else {
                while (taken.size() >= 2) {
                    pair<ll, ll> l1 = taken[taken.size()-1];
                    pair<ll, ll> l2 = taken[taken.size()-2];
                    if (f(i, l2) > f(l1, l2)) { break; }
                    else { taken.pop_back(); pts.pop_back(); }
                }
                pts.pb(f(i, taken.back()).f);
                taken.pb(i);
            }
        }
    }

    ll query(ll x) {
        int idx = lower_bound(pts.begin(), pts.end(), x) - pts.begin();
        return taken[idx].f * x + taken[idx].s;
    }
};

ll dist[MAX];
ll dp[MAX][MAXP];
ll sum[MAX];
vector<ll> cats;
int main(){
    fast_io();
    ll n, m, p;
    cin >> n >> m >> p;
    f1r(i, 2, n+1){
        ll temp; cin >> temp;
        dist[i] = dist[i-1] + temp;
    }
    f0r(i, m){
        ll h, t;
        cin >> h >> t;
        cats.eb(t- dist[h]);
    }

    cats.eb(1e9);
    sort(all(cats));
    reverse(all(cats));
    sum[0] = 0;
    f1r(i, 1, m+1){
        sum[i] = sum[i-1] + cats[i];
    }
    f1r(i, 1, m+1){
        dp[i][1] = sum[1]*i - sum[i];
    }
    f1r(j, 2, p+1){
        cht c;
        f1r(i,1, m+1){
            c.addline({cats[i], dp[i-1][j-1] + sum[i-1] - i*cats[i] + cats[i]});
            if(i<j){
                dp[i][j] = dp[i][j-1];
                continue;
            }
            dp[i][j] = (ll)-sum[i] + c.query(i);
        }

    }
    cout << dp[m][p] << endl;
    return 0;
}