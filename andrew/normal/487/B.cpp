#include <bits/stdc++.h>

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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m, k;
    cin >> n >> m >> k;
    vector <ll> a(n + 1);
    vector <ll> dp(n + 1);
    vector <bool> f(n + 1);
    dp[0] = 0;

    ll uk = 0;

    multiset <ll> s, dpp;

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i <= n; i++){
        dp[i] = 1e18;

        if(i - k + 1 > 0 && uk <= i - k + 1){
                dpp.insert(dp[i - k]);
                f[i - k] = 1;
        }

        s.insert(a[i]);

        while(!s.empty() && *(--s.end()) - *s.begin() > m){

            if(uk){
                s.erase(s.find(a[uk]));
                if(f[uk - 1])dpp.erase(dpp.find(dp[uk - 1]));
            }

            uk++;

        }

        if(dpp.size())dp[i] = *dpp.begin() + 1;

    }

    if(dp[n] == 1e18)dp[n] = -1;

    cout << dp[n] << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}