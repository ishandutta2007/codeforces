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
const int N = 50001;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll dp[200001][4];
vector <pll> vvv[200001];
vector <pll> qry[200001];
ll answer[300001];

ll f(ll l, ll r) {
    return dp[r - l + 1][3];
}

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

void solve(ll idx) {
    ll l, r;
    cin >> l >> r;
    answer[idx] = f(l, r);
    qry[r].p_b({l, idx});
}

void pre_calc() {
    for (int i = 1; i <= 200000; i++) {        
        vector <ll> v;
        for (int j = 1; j * j <= i; j++) if (i % j == 0){
            v.p_b(j);
            if (j * j != i)v.p_b(i / j);
        }
        vector <ll> ve;        
        sort(all(v));        
        v.pop_back();
        for (auto j : v) {
            if (i % (j * 2) != 0 && j * 2 < i) {
                ve.p_b(j * 2);
            }
        }        
        ll uk = sz(ve) - 1;

        for (int idx = 0; idx < sz(ve); idx++){
            while (uk > idx && ve[uk] + ve[idx] >= i) uk--;
            while (uk < idx) uk++;            
            vvv[i].p_b({ve[idx], sz(ve) - uk - 1});                                            
        }        
        reverse(all(ve)); 
        ll s = 0;       
        for (int idx = sz(v) - 1; idx >= 0; idx--){            
            s = sz(v) - idx - 1;
            while (sz(ve) && ve.back() + v[idx] <= i) {                
                ve.pop_back();
            }                                    
            s += sz(ve);            
            vvv[i].p_b({v[idx], s});
        }                
        sort(all(vvv[i]));
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;    
    t = 1;    

    dp[0][0] = 1;
    for (int i = 1; i <= 200000; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= 3; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    pre_calc();

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        // cin >> t;
    #endif    

    cin >> t;

    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    fenwick_tree<ll> tree(200001);

    for (int i = 1; i <= 200000; i++) {
        for (auto j : vvv[i]) {
            tree.update(j.fi, j.se);
        }
        for (auto j : qry[i]) {
            answer[j.se] -= tree.get(j.fi, i);
        }
    }

    for (int i = 1; i <= t; i++) {
        cout << answer[i] << "\n";
    }

    return 0;
}