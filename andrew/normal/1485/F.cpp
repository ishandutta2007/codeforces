#include <bits/stdc++.h>

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
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const ll M = 2e5;
const int inf = 1e8;
const ll mod = 1e9 + 7;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll dec(ll a, ll b){
    ll res = (a - b);
    while(res < 0)res += mod;
    return res;
}

void solve(){
    int n;
    cin >> n;

    vector <ll> b(n + 1), pref(n + 1), dp(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> b[i];
        pref[i] = pref[i - 1] + b[i];
    }

    map <ll, ll> mp;

    ll sum = 0;
    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        ll con = 0;
        if(pref[i - 1] != 0)con = 1;
        dp[i] = 0;
        (dp[i] += dp[i - 1]) %= mod;
        ll val = dec(sum, mp[- pref[i - 1]]) + con;
        (dp[i] += val) %= mod;
        (sum += val) %= mod;
        (mp[b[i] - pref[i]] += val) %= mod;
    }

    cout << dp[n] << "\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }


    return 0;
}

/*
1
10
2 -1 1 -2 2 3 -5 0 2 -1
*/