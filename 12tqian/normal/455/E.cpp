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
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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
#define trav(a, x) for (auto& a : x)

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
const int MAX = 1e5 + 5;
const ll INF = 1e18;
const int SZ = (1<<17);
ll a[MAX];


typedef long long LL;

#define MAXLC 1000000000
#define INF (1LL<<60)

inline LL f(LL m, LL b, int x) {
	return m * x + b;
}

struct lc_node {
	LL m = 0, b = INF;
	lc_node *l = nullptr, *r = nullptr;

	~lc_node() { delete l; delete r; }

	void add_line(LL nm, LL nb, int lo=0, int hi=MAXLC) {
		int mid = (lo + hi) / 2;
		bool bl = f(nm, nb, lo) < f(m, b, lo);
		bool bm = f(nm, nb, mid) < f(m, b, mid);
		bool bh = f(nm, nb, hi) < f(m, b, hi);
		if (bm) {
			swap(nm, m);
			swap(nb, b);
		}
		if (lo == hi || nb == INF)
			return;
		else if (bl != bm) {
			if (!l) l = new lc_node;
			l->add_line(nm, nb, lo, mid - 1);
		}
		else if (bh != bm) {
			if (!r) r = new lc_node;
			r->add_line(nm, nb, mid + 1, hi);
		}
	}

	LL get(int x, int lo=0, int hi=MAXLC) {
		int mid = (lo + hi) / 2;
		LL ret = f(m, b, x);
		if (l && x < mid)
			ret = min(ret, l->get(x, lo, mid - 1));
		if (r && x > mid)
			ret = min(ret, r->get(x, mid + 1, hi));
		return ret;
	}

	void clear() {
		delete l; delete r;
		m = 0, b = INF, l = nullptr, r = nullptr;
	}

};
lc_node seg[2*SZ];
ll ID = INF;
void upd(int p, ll m, ll b){
    for(seg[p += SZ].add_line(m, b); p>1; p>>=1){
        seg[p>>1].add_line(m, b);
    }
}
ll query(int l, int r, ll x){
    ll res1 = ID;
    ll res2 = ID;
    r++;
    for(l += SZ, r+= SZ; l<r; l>>= 1, r>>= 1){
        if(l&1){
            res1 = min(res1, seg[l++].get(x));
        }
        if(r &1){
            res2 = min(res2, seg[--r].get(x));
        }
    }
    return(min(res1, res2));
}

ll pre[MAX];
int main(){
    fast_io();
    int n, m;
    scanf("%d", &n);

    f1r(i, 1, n+1){
        scanf("%d", &a[i]);
    }

    f1r(i, 1, n+1){
        if(i == 1){
            pre[i] = a[i];
        }
        else{
            pre[i] = pre[i-1] + a[i];
        }
    }
    f1r(i, 1, n+1){
        upd(i, -a[i], i*a[i] -pre[i-1]);
    }
    scanf("%d", &m);
    f0r(i, m){
        int xi, yi;
        scanf("%d %d", &xi, &yi);
        int l = yi - xi+1;
        int r = yi;
        printf("%d\n", pre[r] + query(l, r, l));

    }
    return 0;
}