#include <bits/stdc++.h>


#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return;}
#define ifn(x) if(!(x))

using namespace std;
typedef long long ll;
typedef long double ld;
const ll N = 2e5 + 100;
const ll MAXN = 1123456;
const ll inf = 1e18;
const ll M = 59051;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll res[1001], cnt[1001];

ll bp(ll a, ll n, ll m){
    ll res = 1;
    while(n){
        if(n & 1)(res *= a) %= m;
        (a *= a) %= m;
        n >>= 1;
    }
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, m;
    cin >> n >> m;

    vector <ll> a(n + 1);
    ll ans = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i] % m]++;
        if(cnt[a[i] % m] > 1)vout(0);
    }

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++)(ans *= abs(a[i] - a[j])) %= m;
    }

    cout << ans << "\n";

    return 0;

}