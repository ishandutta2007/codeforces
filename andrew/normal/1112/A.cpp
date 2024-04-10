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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;

    vector <ll> p(n + 1), s(n + 1), c(k + 1), v(m + 1);

    for(int i = 1; i <= n; i++)cin >> p[i];
    for(int i = 1; i <= n; i++)cin >> s[i];

    for(int i = 1; i <= n; i++){
        v[s[i]] = max(v[s[i]], p[i]);
    }

    ll ans = 0;
    while(k--){
        ll x;
        cin >> x;
        if(p[x] != v[s[x]])ans++;
    }

    cout << ans << "\n";

    return 0;
}