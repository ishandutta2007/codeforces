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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
T sqr(T x){
    return x * x;
}

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
    ll n, k;
    cin >> n >> k;

    ll ans = 0;

    vector <ll> a(n + 1), b;

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i <= n; i++){
        ll sc = 0;
        b = a;
        ll s = 0, e = 0;
        for(int j = -n; j <= n; j++)if(i + j * k > 0 && i + j * k <= n)b[i + j * k] = 0;
        for(int j = 1; j <= n; j++){
            if(b[j] == -1)s++;
            if(b[j] == 1)e++;
        }
        ans = max(ans, abs(e - s));
    }
    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}