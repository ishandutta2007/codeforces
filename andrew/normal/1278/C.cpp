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
const ll N = 1e5;
const ll inf = 3e18;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll solve(){
    ll n;
    cin >> n;
    vector <ll> a(2 * n + 1);
    for(int i = 1; i <= 2 * n; i++)cin >> a[i];

    map <ll, ll> mp;
    ll S = 0, ans = inf;
    mp[0] = n;
    for(int i = 1; i <= n; i++){
        if(a[i] == 1)S++;
        else S--;
        mp[S] = n - i;
    }
    ans = mp[0] + n;
    S = 0;
    for(int i = 2 * n; i > n; i--){
        if(a[i] == 2)S++;
        else S--;
        if(mp.find(S) != mp.end()){
            ans = min(ans, i - n - 1 + mp[S]);
        }
    }
    return ans;
}

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
        cout << solve() << "\n";
    }

    return 0;
}