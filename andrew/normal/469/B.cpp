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

bool f[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m, l, r;
    cin >> n >> m >> l >> r;

    while(n--){
        ll a, b;
        cin >> a >> b;
        for(int i = a; i <= b; i++)f[i] = 1;
    }

    ll ans = 0;
    vector <pll> a(m);
    for(int i = 0; i < m; i++)cin >> a[i].fi >> a[i].se;

    for(int i = l; i <= r; i++){
        bool fl = 0;
        for(int j = 0; j < m; j++){
            ll le = i + a[j].fi, ri = i + a[j].se;
            for(; le <= ri; le++)if(f[le])fl = 1;
        }
        if(fl)ans++;
    }
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}