#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector <ll> a(n + 1);
        ll l, r;
        l = -1, r = -1;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(i > 1 && max(a[i], a[i - 1]) - min(a[i], a[i - 1]) >= 2)l = i - 1, r = i;
        }
        if(l == -1)cout << "NO\n";
        else cout << "YES\n" << l << " " << r << "\n";
    }

    return 0;
}