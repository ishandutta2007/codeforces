#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define ull unsigned long long

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

ll f(ll &a, ll b){
    a = (a + b) % MOD;
    return a;
}

ll dp[4001];
ll a, b, c;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n >> a >> b >> c;
    for(int i = 1; i <= n; i++)dp[i] = -1e18;
    for(int i = 1; i <= n; i++){
        if(i >= a)dp[i] = max(dp[i], dp[i - a] + 1);
        if(i >= b)dp[i] = max(dp[i], dp[i - b] + 1);
        if(i >= c)dp[i] = max(dp[i], dp[i - c] + 1);
    }
    vout(dp[n]);
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}