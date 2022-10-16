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
vector<ll> h;
Tree<ll> t;
set<int> s;
unordered_map<int, int> um;
int dp[MAX];
int best[MAX];
struct Seg {
    vpi seg;
    pii MN = mp(0, -1);
    int SZ;
    void build(int sz){
        SZ = sz;
        seg.resize(2*SZ);
       f0r(i, 2*SZ){
           seg[i] = mp(0, -1);
       }
    }

    pii comb(pii a, pii b) {
        if(a.f> b.f) return a;
        if(b.f>a.f) return b;
        return a;
    } // easily change this to min or max
    void upd(int p, pii value) {  // set value at position p
        for (seg[p += SZ] = value; p > 1; p >>= 1)
            seg[p>>1] = comb(seg[(p|1)^1],seg[p|1]); // non-commutative operations
    }
    void update(int p, pii value){
        if(query(p, p).f<value.f){
            upd(p, value);
        }
    }
    pii query(int l, int r) {  // sum on interval [l, r]
        pii res1 = MN, res2 = MN; r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l&1) res1 = comb(res1,seg[l++]);
            if (r&1) res2 = comb(seg[--r],res2);
        }
        return comb(res1,res2);
    }
};
Seg se;
int main(){
    fast_io();
    ll n, d;
    cin >> n >> d;
    ll mx = 0;
    se.build((1<<17));
    f0r(i, n){
        ll hi;
        cin >> hi;
        h.eb(hi);
        t.insert(hi);
        mx = max(mx, hi);
    }
    f0r(i, n){
        best[i] = -1;
        dp[i] = 1;
        if(i == 0){
            int id = t.order_of_key(h[i]);
            se.update(id, mp(dp[i], i));
            continue;
        }
        ll hi = -1;
        if(h[i]-d>0){
            hi = t.order_of_key(h[i] - d);
            if(*t.find_by_order(hi) > h[i] - d)hi--;
        }
        ll lo = -1;
        if(h[i] + d<= mx){
            lo = t.order_of_key(h[i] + d);
            if(*t.find_by_order(lo) < h[i] + d) lo++;
        }
        if(lo != -1){
            auto res = se.query(lo, (1<<17) - 1);
            if(res.f+1>dp[i]){
                dp[i] = res.f+1;
                best[i] = res.s;
            }
        }
        if(hi != -1){
            auto res = se.query(0, hi);
            if(res.f+1>dp[i]){
                dp[i] = res.f + 1;
                best[i] = res.s;
            }
        }
        int id = t.order_of_key(h[i]);
        se.update(id, mp(dp[i], i));
    }
    mx = 0;
    int idx = -1;
    f0r(i, n){
        if(dp[i] >mx){
            mx = dp[i];
            idx = i;
        }
    }
    vi ans;
    int cur = idx;
    while(cur != -1){
        ans.eb(cur);
        cur = best[cur];
    }
    reverse(all(ans));
    cout << sz(ans) << endl;
    assert(sz(ans) == mx);
    for(int x: ans) cout << x +1<<" " ;
    cout << endl;

    return 0;
}