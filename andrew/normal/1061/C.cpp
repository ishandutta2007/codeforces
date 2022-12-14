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

const ll MOD = 1e9 + 7;

ll dp[MAXN];



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));

    ll n;
    cin >> n;

    ll ans = 0;

    dp[0] = 1;

    for(int i = 0; i < n; i++){
        vector <ll> b;
        ll x;
        cin >> x;
        for(int j = 1; j * j <= x; j++)if(x % j == 0){
            b.p_b(j);
            if(x / j != j)b.p_b(x / j);
        }

        sort(all(b));

        for(int j = b.size(); j > 0; ){
            j--;
            ll x = b[j];
            dp[x] = (dp[x] + dp[x - 1]) % MOD;
        }

    }

    for(int i = 1; i <= n; i++)ans = (ans + dp[i]) % MOD;

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}