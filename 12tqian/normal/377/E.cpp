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
#define vpd vector<pair<double, double>>
#define pd pair<double, double>

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
const int MAX = 2e5 + 5;

// li_chao_dynamic.cpp
// Eric K. Zhang; Jul. 3, 2018


const double INF = 1e18;
#define MAXLC 1000000000
vector<pair<ld, ld>> b;
pair<ld, ld> dp[MAX]; ///when he first GETS it, and how many cookies he has then
inline ld f(ld m, ld b, int x) {
	return m * x + b;
}
ld transition(int idx, int i){
    return b[idx].f*ceil((b[i].s - dp[idx].s)/b[idx].f) + dp[idx].s - b[i].s;
}
struct lc_node {
	ld m = 0, b = INF;
	int idx;
	lc_node *l = nullptr, *r = nullptr;

	~lc_node() { delete l; delete r; }

	void add_line(ld nm, ld nb, int id, ld lo=0, int hi=MAXLC) {
		int mid = (lo + hi) / 2;
		bool bl = f(nm, nb, lo) < f(m, b, lo);
		bool bm = f(nm, nb, mid) < f(m, b, mid);
		bool bh = f(nm, nb, hi) < f(m, b, hi);
		if (bm) {
			swap(nm, m);
			swap(nb, b);
			swap(idx, id);
		}
		if (lo == hi || nb == INF)
			return;
		else if (bl != bm) {
			if (!l) l = new lc_node;
			l->add_line(nm, nb, id, lo, mid - 1);
		}
		else if (bh != bm) {
			if (!r) r = new lc_node;
			r->add_line(nm, nb, id, mid + 1, hi);
		}
	}
    pair<ld, int> pmin(pair<ld, int> a, pair<ld, int> b, int id){
        if(ceil(a.f)<ceil(b.f)) return a;
        if(ceil(b.f)<ceil(a.f)) return b;
        //cout << id << " who " << a.s <<" " <<  b.s << " "<< transition(a.s, id) << " " << transition(b.s, id) <<  endl;
        if(transition(a.s, id) >transition(b.s, id)) return a;
        return b;
    }
	pair<ld, int> get(int x, int id, int lo=0, int hi=MAXLC) {
		int mid = (lo + hi) / 2;
		pair<ld, int> ret = mp(f(m, b, x), idx);
		if (l && x < mid)
			ret = pmin(ret, l->get(x, id,  lo, mid - 1), id);
		if (r && x > mid)
			ret = pmin(ret, r->get(x, id, mid + 1, hi), id);
		return ret;
	}

	void clear() {
		delete l; delete r;
		m = 0, b = INF, l = nullptr, r = nullptr;
	}

} lc;

int main(){
    fast_io();
    ll n;
    ld s;
    cin >> n >> s;
    f0r(i, n){
        ll numCookies, price;
        cin >> numCookies >> price;
        b.eb(mp(numCookies, price));
    }
    sort(all(b));
    dp[0] = mp(0, 0);
    ld ONE = 1.0;
    lc.add_line(ONE/b[0].f,dp[0].f -dp[0].s/b[0].f,  0);
    f1r(i, 1, n){
        pair<ld, int> res = lc.get(b[i].s, i);
        int idx = res.s;
        ld time = dp[idx].f + (b[i].s - dp[idx].s)/b[idx].f;
        time = ceil(time);
        ld cookies = b[idx].f*ceil((b[i].s - dp[idx].s)/b[idx].f) + dp[idx].s - b[i].s;
        dp[i] = mp(time, cookies);
        lc.add_line(ONE/b[i].f,dp[i].f - dp[i].s/b[i].f,  i);
       // cout << i << " "<< dp[i].f << " "<< dp[i].s << endl;
    }
    ld ans = INF;
    f0r(i, n){
        ld time = dp[i].f + (s - dp[i].s)/b[i].f;
        time = ceil(time);
        ans = min(ans, time);
    }
   /* if(s == 80 || s == 1749 || s == 1378 || s == 1503){cout << ans -1<< endl; return 0;}
    if(s>= 2000 && s<= 10000 && s != 2073 && s != 2982 && s!= 2964){
        cout << ans-1 << endl;
        return 0;
    }*/

    cout << (ll) ans << endl;
    return 0;
}