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


ll a[MAXN], ans;
ll to[MAXN];
vector <ll> v;

ll f[MAXN];

void dfs(ll x){
    if(f[x] == 2)return;
    if(f[x] == 1){
        ll k = v.size() - 1;
        ll mn = 1e18;
        while(1){
            mn = min(mn, a[v[k]]);
            if(v[k] == x)break;
            k--;
        }
        ans += mn;
        return;
    }
    v.p_b(x);
    f[x] = 1;
    dfs(to[x]);
    f[x] = 2;
    v.pop_back();
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)cin >> to[i];

    for(int i = 1; i <= n; i++)dfs(i);

    cout << ans << "\n";
    return 0;
}