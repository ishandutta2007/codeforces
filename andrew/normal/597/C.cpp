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

const ll N = 1e5 + 1;
ull dp[12][100101];

void update(ll xe, ll x, ll val){
    for(int i = x; i <= N; i += i & -i)dp[xe][i] += val;
}

ull get(ll xe, ll x){
    ull res = 0;
    for(int i = x; i > 0; i -= i & -i)res += dp[xe][i];
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, k;
    cin >> n >> k;
    vector <ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]++;
    }
    update(0, 1, 1);
    for(int i = 1; i <= n; i++){
        ll val = a[i - 1];
        for(int j = 1; j <= k + 1; j++){
            ull kol = get(j - 1, val - 1);
            update(j, val, kol);
        }
    }

    cout << get(k + 1, N) << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}