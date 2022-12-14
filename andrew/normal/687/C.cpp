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

bitset <501> f[501];

int main() {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, k;
    cin >> n >> k;

    vector <ll> a(n + 1);

    ll sum = 0;

    for(int i = 1; i <= n; sum += a[i], i++)cin >> a[i];

    f[0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = k; j >= a[i]; j--){
            f[j] |= (f[j - a[i]] << a[i]) | f[j - a[i]];
        }
    }

    vector <ll> ans;

    for(int i = 0; i <= k; i++)if(f[k][i])ans.p_b(i);

    cout << sz(ans) << "\n";
    for(auto i : ans)cout << i << " ";
    cout << "\n";

    return 0;
}