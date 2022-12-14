#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector <ll> dp(n + 1), pr(n + 1);
    vector < vector <pll> > v(n + 1);

    while(m--){
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].p_b({b, c});
        v[b].p_b({a, c});
    }

    for(int i = 1; i <= n; i++)dp[i] = 1e18;

    set <pll> st;
    dp[1] = 0;
    st.insert({0ll, 1ll});

    while(!st.empty()){
        ll x = st.begin() -> se, val = st.begin() -> fi;
        st.erase(st.begin());
        for(auto &i : v[x]){
            ll to = i.fi, val1 = val + i.se;
            if(dp[to] > val1){
                st.erase({dp[to], to});
                dp[to] = val1;
                pr[to] = x;
                st.insert({dp[to], to});
            }
        }
    }

    if(dp[n] == 1e18)vout(-1);

    vector <ll> way;

    while(n){
        way.p_b(n);
        n = pr[n];
    }

    reverse(all(way));

    for(auto i : way)cout << i << " ";

    return 0;
}