#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair <ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sqr(x) (x) * (x)
#define sset ordered_set

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;

const ll MAXN = 1123456;
const ll N = 2e5;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

ll pref[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vector <ll> a(n + 1), b(k + 1), time(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i <= n; i++){
        ll pos = 1;
        for(int j = 2; j <= k; j++)if(b[pos] > b[j])pos = j;
        b[pos] += a[i];
        time[i] = b[pos] - a[i];
        pref[time[i] + a[i]]++;
    }

    for(int i = 1; i < MAXN; i++){
        pref[i] += pref[i - 1];
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        bool f = 0;
        for(int j = 1; j <= a[i]; j++){
            ll kol = ll(100.0 * (ld(pref[time[i] + j - 1]) / ld(n)) + 0.5);
            if(kol == j) f = 1;
        }

        if(f)ans++;
    }
    cout << ans << "\n";
    return 0;
}