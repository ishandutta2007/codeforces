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

ll dp[MAXN], res, kol;

vector <ll> v[MAXN];

vector <ll> a;

void dfs(ll x, ll p){
    for(auto to : v[x])if(to != p){
        dfs(to, x);
        if(dp[to] > 0)dp[x] += dp[to];
    }
    dp[x] += a[x];
    res = max(res, dp[x]);
}

void f(ll x, ll p){
    dp[x] = a[x];
    for(auto to : v[x])if(to != p){
        f(to, x);

        if(dp[to] > 0)dp[x] += dp[to];
    }

    if(dp[x] == res){
        kol++;
        dp[x] = -1e18;
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("advertisement.in","r",stdin);
    //freopen("advertisement.out","w",stdout);

    ll n;
    cin >> n;
    a.resize(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    res = -1e18;

    ll q = n - 1;
    while(q--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }
    dfs(1, 0);
    f(1, 0);
    cout << res * kol << " " << kol << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}