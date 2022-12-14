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

ll c[N][3];

void solve(){
    ll n, k;
    cin >> n >> k;
    string ans;
    int cnt = 2;
    for(int i = 0; i < n; i++){
        if(c[n - i - 1][cnt] < k){
            k -= c[n - i - 1][cnt];
            cnt--;
            ans += "b";
        }else ans += "a";
    }
    cout << ans << "\n";
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

    c[0][0] = 1;

    for(int i = 1; i < N; i++){
        c[i][0] = 1;
        for(int j = 1; j <= 2; j++)c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }

    while(t--){
        solve();
    }

    return 0;
}