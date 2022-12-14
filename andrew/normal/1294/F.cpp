#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> v[MAXN];
ll dp_down[MAXN], dp_up[MAXN], p[MAXN], what[MAXN], what_up[MAXN];
ll A, B, C, ans;

void dfs(ll x, ll pr = 0){
    p[x] = pr;
    vector <pll> c;
    for(auto to : v[x])if(to != pr){
        dfs(to, x);
        c.p_b({dp_down[to] + 1, to});
    }
    sort(c.rbegin(), c.rend());

    if(sz(c) > 1){
        if(c[0].fi + c[1].fi > ans){
            A = x;
            B = what[c[0].se];
            C = what[c[1].se];
            ans = c[0].fi + c[1].fi;
        }
    }

    if(sz(c) > 2){
        if(c[0].fi + c[1].fi + c[2].fi > ans){
            A = what[c[0].se];
            B = what[c[1].se];
            C = what[c[2].se];
            ans = c[0].fi + c[1].fi + c[2].fi;
        }
    }

    what[x] = x;

    if(!c.empty()){
        dp_down[x] = c[0].fi;
        what[x] = what[c[0].se];
    }

}

void go(ll x, pll mx = {0, 1}){
    multiset <pll> s;
    dp_up[x] = mx.fi;
    what_up[x] = mx.se;
    for(auto to : v[x])if(to != p[x]){
        s.insert({dp_down[to] + 2, what[to]});
    }

    for(auto to : v[x])if(to != p[x]){
        s.erase({dp_down[to] + 2, what[to]});
        pll kek = {mx.fi + 1, mx.se};
        if(!s.empty())kek = max(kek, *--s.end());
        go(to, kek);
        s.insert({dp_down[to] + 2, what[to]});
    }

    vector <pll> c;

    for(auto to : v[x])if(to != p[x]){
        c.p_b({dp_down[to] + 1, to});
    }
    sort(c.rbegin(), c.rend());

    if(sz(c) > 1){
        if(c[0].fi + c[1].fi + dp_up[x] > ans){
            A = what_up[x];
            B = what[c[0].se];
            C = what[c[1].se];
            ans = c[0].fi + c[1].fi + dp_up[x];
        }
    }

    if(!c.empty()){
        if(x != 1 && c[0].fi + dp_up[x] > ans){
            A = what_up[x];
            B = what[c[0].se];
            C = x;
            ans = c[0].fi + dp_up[x];
        }
    }

}

void main_solve(){
    ll n;
    cin >> n;

    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    dfs(1);
    go(1);

    cout << ans << "\n";
    cout << A << " " << B << " " << C << "\n";

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        ll t;
        cin >> t;
        ll id = 0;
        while(t--){
            cout << "Test number " << ++id << ": \n";
            main_solve();
        }
    #else
        main_solve();
    #endif // LOCAL



    return 0;
}