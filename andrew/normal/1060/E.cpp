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

vector <ll> v[MAXN];
ll dp[MAXN], p[MAXN], deep[MAXN];
ll ans, sc;

ll kol[MAXN];
ll kol1[MAXN];
ll keks[MAXN][3];

void dfs(ll x, ll gl, ll pr){
    sc += dp[gl];
    deep[x] = gl;
    p[x] = pr;

    for(auto i : v[x])if(i != pr){
            dfs(i, gl + 1, x);
            for(int j = 0; j < 2; j++)keks[x][j] += keks[i][j];
    }
    kol[deep[x] % 2]++;
    keks[x][deep[x] % 2]++;
}

void rec(ll x, ll s){
    ll chet = deep[x] % 2;
    s -= keks[x][chet];
    s += kol[1 - chet] - keks[x][1 - chet];
    ans += s;

    for(auto i : v[x])if(i != p[x])rec(i, s);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    for(int i = 1; i <= 200000; i++){
        dp[i] = dp[i - 1] + 1;
        if(i > 1)dp[i] = min(dp[i], dp[i - 2] + 1);
    }
    dfs(1, 1, 0);
    rec(1, sc);
    cout << ans / 2 << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}