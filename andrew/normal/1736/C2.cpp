#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e6;;
const int M = pw(16);
const long long mod = 998244353;
const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
struct fenwick_tree{
    vector <T> t;
    fenwick_tree(int n){
        t.resize(n + 1);
        fill(t.begin(), t.end(), 0);
    }
    
    T get(int l, int r){
        return f(r) - f(l - 1);
    }
    
    void update(int pos, T val){
        u(pos, val);
    }

private:
    T f(int pos){
        T res = 0;
        for(int i = pos; i > 0; i -= i & -i) res += t[i];
        return res;
    }
    void u(int pos, T val){
        for(int i = pos; i < (int)t.size(); i += i & -i) t[i] += val;
    }
};

void solve(){
    ll n;
    cin >> n;
    vector <ll> a(n + 1), b(n), l(n + 1), r(n + 1);
    vector <vector <pll>> vv(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        l[i] = max(1LL, i - a[i] + 1);
    }

    vector <pll> rofl;

    ll ans = 0;

    vector <vector <ll>> rr(n + 1);

    for (int i = 1; i <= n; i++) {
        rofl.p_b({l[i], i});
        sort(all(rofl));
        if (rofl.size() == 3) {
            rofl.erase(rofl.begin());
        }        
        if (i > 1) {    
            rr[rofl[1].se].p_b(rofl[0].fi);
        }
        r[i] = max(r[i - 1], l[i]);        
        ans += i - r[i] + 1;
    }    

    fenwick_tree <ll> f(n + 1), f1(n + 1);

    
    vector < vector <pll> > xx(n + 1);
    vector < vector <pll> > xxe(n + 1);

    ll q;
    cin >> q;

    vector <ll> res(q);

    for (int i = 0; i < q; i++) {
        ll p, x;
        cin >> p >> x;
        res[i] = ans;
        if (p == 1 || x == a[p]) continue;
        res[i] = -1;
        if(p - x + 1 > l[p]) xx[p].p_b({i, x});
        else xxe[p].p_b({max(1LL, p - x + 1), i});
    }

    for (int i = 1; i <= n; i++) {
        sort(all(rr[i]));
        ll tt = 0;
        for (auto j : rr[i]) tt += j;
        ll uk = 0;

        sort(all(xxe[i]));
        for (auto j : xxe[i]) {
            res[j.se] = ans + sz(rr[i]) * l[i];
            while (uk < sz(rr[i]) && rr[i][uk] < j.fi) {
                tt -= rr[i][uk];
                uk++;
            }
            res[j.se] -= tt + uk * j.fi;            
        }
    }

    for (int i = n; i > 0; i--) {    
        f.update(r[i], r[i]);
        f1.update(r[i], 1);            
        for (auto j : xx[i]) {
            ll val = max(1LL, i - j.se + 1);                    
            res[j.fi] = ans;
            res[j.fi] += f.get(1, val);
            res[j.fi] -= f1.get(1, val) * val;
        }        
    }

    for (int i = 0; i < q; i++) {
        cout << res[i] << "\n";
    }
    cout << "\n";

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;    
    t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> t;
    #endif    
    // cin >> t;
    
    while(t--){
        solve();
    }


    return 0;
}