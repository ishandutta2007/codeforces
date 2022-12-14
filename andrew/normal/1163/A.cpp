#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;

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

    ll n, m;
    cin >> n >> m;
    if(m == 0)vout(1);
    vector <ll> a(n + 1);
    for(int i = 1; i <= n; i++)a[i] = 1;
    for(int i = 1; i <= n; i += 2)if(m > 0){
        m--;
        a[i] = 0;
    }

    for(int i = 1; i <= n; i++)if(a[i] && m > 0){
        a[i] = 0;
        m--;
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++)if(a[i] == 1 && a[i - 1] == 0)ans++;

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}