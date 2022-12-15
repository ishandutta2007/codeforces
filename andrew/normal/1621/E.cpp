#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
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
const ll inf = -1e18;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

set <int> sl, sr, s;

struct dv{
    ll a, b, c;
    // dv(ll x, ll y, ll id){
    //     a = x, b = y, c = id;
    // }

    friend bool operator < (dv a, dv b){
        return (m_p(a.a * b.b, a.c) < m_p(b.a * a.b, b.c));
    }
        
};

bool ok(dv a, dv b){
    return (a.a * b.b <= b.a * a.b);
}

bool in_s(ll l, ll r){
    if(l > r) return 0;
    if(s.lower_bound(l) != s.end() && *s.lower_bound(l) <= r) return 1;
    return 0;
}

bool in_sl(ll l, ll r){
    if(l > r) return 0;
    if(sl.lower_bound(l) != sl.end() && *sl.lower_bound(l) <= r) return 1;
    return 0;
}

bool in_sr(ll l, ll r){
    if(l > r) return 0;
    if(sr.lower_bound(l) != sr.end() && *sr.lower_bound(l) <= r) return 1;
    return 0;
}


void solve(){   
    sl.clear();
    s.clear();
    sr.clear();
    ordered_set <dv> st;
    int n, m;
    cin >> n >> m;
    vector <ll> a(m + 1), arr(n + 1), sum(m + 1);
    vector <dv> a1(m + 1);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr.begin() + 1, arr.end());
    for(int i = m, idx = n; i > 0; i--, idx--) a[i] = arr[idx];
    for(int i = 1; i <= m; i++){
        a1[i].a = a[i], a1[i].b = 1, a1[i].c = i;                
    }
    vector <vector <ll>> b(m + 1);
    vector <pll> c;
    vector <dv> vc;
    for(int i = 1; i <= m; i++){
        ll k;
        cin >> k;
        b[i].resize(k);
        ll s = 0;
        for(auto &j : b[i]) {
            cin >> j;
            s += j;
        }
        dv tmp;
        tmp.a = s, tmp.b = k, tmp.c = i;
        //dv tmp = *new dv(s, k, i);
        st.insert(tmp);
        sum[i] = s;
        vc.p_b(tmp);
    }

    sort(all(vc));

    vector <ll> wh(m + 1);

    for(int i = 1; i <= m; i++){
        if(i < m){
            if(!ok(vc[i - 1], a1[i + 1])){
                sr.insert(i);
            }
        }
        if(!ok(vc[i - 1], a1[i])){
            s.insert(i);
        }
        if(i > 1){
            if(!ok(vc[i - 1], a1[i - 1])){
                sl.insert(i);
            }
        }
        wh[vc[i - 1].c] = i;
    }

    string ans;

    for(int i = 1; i <= m; i++){
        ll last_pos = wh[i], new_pos;
        dv t;
        t.a = sum[i], t.b = sz(b[i]), t.c = i;
        //dv t = * new dv(sum[i], sz(b[i]), i);
        char odp;
        st.erase(vc[wh[i] - 1]);
        for(int j = 0; j < sz(b[i]); j++){
            t.a = sum[i] - b[i][j];
            t.b--;
            odp = '1';
            new_pos = st.order_of_key(t) + 1;
            if(last_pos <= new_pos){
                if(in_s(1, last_pos - 1) || in_s(new_pos + 1, m) || in_sl(last_pos + 1, new_pos)) odp = '0';
                if(!ok(t, a1[new_pos])) odp = '0';
            }else{
                if(in_s(1, new_pos - 1) || in_s(last_pos + 1, m) || in_sr(new_pos, last_pos - 1)) odp = '0';
                if(!ok(t, a1[new_pos])) odp = '0';
            }
            ans += odp;
            t.b++;
        }
        st.insert(vc[wh[i] - 1]);
    }   
    cout << ans << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;    
    t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        //cin >> t;
    #endif      

    cin >> t;  
    
    while(t--){
        solve();
    }

    return 0;
}