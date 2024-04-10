#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
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

ll a[1001][1091], b[1001][1001];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)cin >> a[i][j];

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        cin >> b[i][j];
        if(a[i][j] < b[i][j])swap(a[i][j], b[i][j]);
    }

    for(int i = n; i > 0; i--)
    for(int j = m; j > 0; j--){
        ll val = 1e18;
        if(j != m)val = min(val, a[i][j + 1]);
        if(i != n)val = min(val, a[i + 1][j]);
        if(a[i][j] >= val)swap(a[i][j], b[i][j]);
        val = 1e18;
        if(j != m)val = min(val, b[i][j + 1]);
        if(i != n)val = min(val, b[i + 1][j]);
        if(b[i][j] >= val)swap(b[i][j], a[i][j]);
        if(b[i][j] >= val)vout("Impossible");
        val = 1e18;
        if(j != m)val = min(val, a[i][j + 1]);
        if(i != n)val = min(val, a[i + 1][j]);
        if(a[i][j] >= val)vout("Impossible");    }



    vout("Possible");

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}