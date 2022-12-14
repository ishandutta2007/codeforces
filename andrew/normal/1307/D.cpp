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
#define fout(x) {cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> v[MAXN], v1[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, m, k;
    cin >> n >> m >> k;

    vector <ll> a(k + 1), dp(n + 1, inf), dp1(n + 1, inf), dp2(n + 1);

    queue <ll> st;

    for(int i = 1; i <= k; i++){
        cin >> a[i];
    }

    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    dp[1] = 0;

    st.push(1);

    while(!st.empty()){
        ll x = st.front();
        st.pop();
        for(auto to : v[x])if(dp[to] > dp[x] + 1){
            dp[to] = dp[x] + 1;
            st.push(to);
        }
    }

    dp1[n] = 0;

    st.push(n);

    while(!st.empty()){
        ll x = st.front();
        st.pop();
        for(auto to : v[x])if(dp1[to] > dp1[x] + 1){
            dp1[to] = dp1[x] + 1;
            st.push(to);
        }
    }
    vector <pll> b(k);
    vector <ll> suf(k + 1);
    for(int i = 0; i < k; i++){
        b[i] = {dp[a[i + 1]], dp1[a[i + 1]]};
    }

    sort(all(b));

    for(int i = k - 1; i >= 0; i--)suf[i] = max(suf[i + 1], b[i].se);

    ll l = 1, r = dp[n];

    while(l < r){
        ll c = (l + r + 1) >> 1;
        bool ok = 0;
        for(int i = 0; i < k - 1; i++){
            ll le = i + 1, ri = k;
            while(le < ri){
                ll mid = (le + ri) >> 1;
                if(b[i].se + b[le].fi + 1 >= c)ri = mid;
                else le = mid + 1;
            }
            if(le < k){
                if(b[i].fi + suf[le] + 1 >= c)ok = 1;
            }
        }
        if(ok)l = c;
        else r = c - 1;
    }

    cout << l << "\n";

    return 0;
}