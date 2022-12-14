#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


#define fi first
#define se second
#define p_b push_back
#define pll pair <ll, ll>
#define pii pair <int, int>
#define m_p make_pair
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}


using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 3123456;
const ll N = 2e5;
const ll inf = 3e18;
const ll buben = 338;
const ll mod = 1e9 + 7;
const ll step = 200003;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector <pll> v[MAXN][2];
ll sum = 0;

multiset < pair <ll, pll> > s, s2;

int dfs(int x, int p = 0){
    int leaves = 0;
    bool leaf = 1;
    for(auto to : v[x][0])if(to.fi != p){
        leaf = 0;
        ll t = dfs(to.fi, x);
        sum += to.se * t;
        s.insert({(to.se - (to.se / 2)) * t, {t, to.se}});
        leaves += t;
    }
    for(auto to : v[x][1])if(to.fi != p){
        leaf = 0;
        ll t = dfs(to.fi, x);
        sum += to.se * t;
        s2.insert({(to.se - (to.se / 2)) * t, {t, to.se}});
        leaves += t;
    }
    if(leaf)leaves++;
    return leaves;
}

void solve(){
    int n;
    ll S;
    cin >> n >> S;
    sum = 0;
    s.clear();
    for(int i = 1; i <= n; i++)v[i][0].clear(), v[i][1].clear();
    for(int i = 1; i < n; i++){
        ll a, b, w, c;
        cin >> a >> b >> w >> c;
        c--;
        v[a][c].p_b({b, w});
        v[b][c].p_b({a, w});
    }
    dfs(1);
    ll ans = 0;
    vector <ll> v;
    while(sum > S && sz(s)){
        pair <ll, pll> xe = *--s.end();
        if(!xe.fi)break;
        s.erase(--s.end());
        ans++;
        sum -= xe.fi;
        v.p_b(xe.fi);
        xe.se.se /= 2;
        xe.fi = ((xe.se.se + 1) / 2) * xe.se.fi;
        s.insert(xe);
    }
    ll temp_ans = ans;
    ans = inf;
    if(sum <= S)ans = temp_ans;
    while(sz(s2)){
        pair <ll, pll> xe = *--s2.end();
        if(!xe.fi)break;
        temp_ans += 2;
        s2.erase(--s2.end());
        sum -= xe.fi;
        xe.se.se /= 2;
        xe.fi = ((xe.se.se + 1) / 2) * xe.se.fi;
        s2.insert(xe);
        while(sum <= S && !v.empty()){
            ans = min(ans, temp_ans);
            ll x = v.back();
            if(sum + x > S)break;
            sum += x;
            v.pop_back();
            temp_ans--;
        }
        if(sum <= S)ans = min(ans, temp_ans);
    }
    fout(ans);
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL


    cin >> t;
    while(t--)solve();

    return 0;
}