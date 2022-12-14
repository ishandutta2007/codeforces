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

    ll q;

    cin >> q;

    while(q--){
        ll n, k, d;
        cin >> n >> k >> d;

        ll kol = 0;
        map <ll, ll> mp;

        vector <ll> a(n + 1);

        for(int i = 1; i <= n; i++)cin >> a[i];

        for(int i = 1; i <= d; i++){
            if(!mp[a[i]])kol++;
            mp[a[i]]++;
        }

        ll res = kol;

        for(int i = 2; i <= n - d + 1; i++){
            mp[a[i - 1]]--;
            if(!mp[a[i - 1]])kol--;

            if(!mp[a[i + d - 1]])kol++;
            mp[a[i + d - 1]]++;

            res = min(res, kol);
        }

        cout << res << "\n";

    }

    return 0;
}