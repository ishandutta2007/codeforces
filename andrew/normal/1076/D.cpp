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


vector <pll> v[MAXN];

map <pll, ll> mp;

ll dp[MAXN], pr[MAXN];
bool f[MAXN];
pll a[MAXN];



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("numbers.in","r",stdin);
    //freopen("numbers.out","w",stdout);

    ll n, m, k;
    cin >> n >> m >> k;
    ll i;
    for(i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        mp[{a, b}] = i;
        mp[{b, a}] = i;
        v[a].p_b({b, c});
        v[b].p_b({a, c});
    }
    for(i = 1; i <= n; i++)dp[i] = 1e18;
    dp[1] = 0;
    set <pll> st;
    st.insert({0ll, 1ll});
    ll j = 0;
    while(!st.empty()){
        ll x = st.begin() -> se, val = st.begin() -> fi;
        st.erase(st.begin());
        pll i;
        for(int j = 0; j < v[x].size(); j++){
            i = v[x][j];
            ll to = i.fi, val1 = val + i.se;
            if(dp[to] > val1){
                st.erase({dp[to], to});
                dp[to] = val1;
                pr[to] = x;
                st.insert({dp[to], to});
            }
        }
    }

    for(int i = 1; i <= n; i++)a[i] = m_p(dp[i], i);
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    ll kol = n - 1;
    ll pust = 0;
    if(k < kol){
        pust = kol - k;
    }
    set <ll> sans;

    for(i = pust + 1; i < n; i++){
        ll x = a[i].se;
        sans.insert(mp[{x, pr[x]}]);
    }

    cout << sans.size() << "\n";
    for(auto i : sans)cout << i + 1 << " ";
    return 0;
}