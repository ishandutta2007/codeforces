#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

    ll n;
    cin >> n;
    vector <pll> a(n + 1);
    ll ans = 0;
    a[0] = {0, 0};
    for(int i = 1; i <= n; i++)cin >> a[i].fi >> a[i].se;

    if(a[n] == a[0])ans = 1;

    ll uk = 0;

    for(int i = 1; i <= n; i++){
        if(a[i] == a[i - 1])continue;
        ll l = a[i - 1].fi, r = a[i].fi;
        ll l1 = a[i - 1].se, r1 = a[i].se;

        ll le = max(max(l, l1), uk), ri = min(r, r1);

        if(le <= ri){
            ans += ri - le + 1;
            uk = ri + 1;
        }
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}