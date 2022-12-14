#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define pll pair <ll, ll>
#define all(x) x.begin(),x.end()
#define pii pair <int, int>
#define sqr(x) ((x)*(x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll inf = 1e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
template <typename T> void vout(T s){cout << s << endl; exit(0);}

vector <ll> g[MAXN], g1[MAXN];

ll dp[MAXN];



int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, m;
    cin >> n >> m;

    while(m--){
        ll a, b;
        cin >> a >> b;
        g[a].p_b(b);
        g1[b].p_b(a);
    }

    ll k;

    cin >> k;

    vector <ll> p(k + 1);

    for(int i = 1; i <= k; i++)cin >> p[i];

    for(int i = 1; i <= n; i++)dp[i] = inf;

    ll ra, rb;
    ra = rb = 0;

    dp[p[k]] = 0;

    set <pll> st;

    st.insert({0, p[k]});

    while(!st.empty()){
        pll xe = *st.begin();
        st.erase(st.begin());
        for(auto to : g1[xe.se]){
            ll val = xe.fi + 1;
            if(dp[to] > val){
                st.erase({dp[to], to});
                dp[to] = val;
                st.insert({dp[to], to});
            }
        }
    }


    for(int i = 1; i < k; i++){
        ll mn = inf;
        for(auto j : g[p[i]]){
            mn = min(mn, dp[j]);
        }
        bool f, f1;
        f = f1 = 0;
        for(auto j : g[p[i]])if(dp[j] == mn){
            if(j == p[i + 1])f = 1;
            else f1 = 1;
        }
        if(f1){
            if(!f)ra++, rb++;
            else rb++;
        }
    }

    cout << ra << " " << rb << "\n";

    return 0;
}