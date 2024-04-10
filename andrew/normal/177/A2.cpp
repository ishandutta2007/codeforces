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

ll a[1001][1001];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    set <pll> s;
    ll n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)cin >> a[i][j];
    if(n % 2){
        for(int i = 1; i <= n; i++)s.insert({i, n / 2 + 1});
        for(int i = 1; i <= n; i++)s.insert({n / 2 + 1, i});
    }else {
        for(int i = 1; i <= n; i++)s.insert({i, n / 2 + 1});
        for(int i = 1; i <= n; i++)s.insert({i, n / 2 - 1});
        for(int i = 1; i <= n; i++)s.insert({n / 2 + 1, i});
        for(int i = 1; i <= n; i++)s.insert({n / 2 - 1, i});
    }

    for(int i = n; i >= 1; i--)s.insert({i, i});

    for(int i = 1; i <= n; i++)s.insert({i, n - i + 1});

    ll ans = 0;
    for(auto i : s)ans += a[i.fi][i.se];
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}