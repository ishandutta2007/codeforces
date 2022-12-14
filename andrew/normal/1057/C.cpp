#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
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

ll n, s, k;

ll dp[100][2500];
queue <pll> q;

void add(ll x, ll val, ll rust){
    if(val >= 2500)return;
    if(dp[x][val] <= rust)return;
    dp[x][val] = rust;
    q.push({x, val});
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> s >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2500; j++)dp[i][j] = 1e18;
    }
    vector <ll> a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)add(i, a[i], abs(i - s));
    string b;
    cin >> b;
    b = "+" + b;

    while(!q.empty()){
        pll xe = q.front();
        q.pop();
        ll x = xe.fi, vall = xe.se, rust = dp[x][vall];
        for(int i = 1; i <= n; i++)if(a[i] > a[x] && b[x] != b[i])add(i, vall + a[i], rust + abs(i - x));
    }

    ll ans = 1e18;
    for(int i = 1; i <= n; i++){
        for(int j = k; j < 2500; j++)ans = min(ans, dp[i][j]);
    }

    if(ans == 1e18)vout(-1);
    vout(ans);

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}