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

    ll n, m;

    vector <ll> a(2), b(2);

    cin >> n >> m;

    while(n--){
        ll x;
        cin >> x;
        x %= 2;
        a[x]++;
    }

    while(m--){
        ll x;
        cin >> x;
        x %= 2;
        b[x]++;
    }

    ll ans = 0;
    for(int i = 0; i < 2; i++)ans += min(a[i], b[1 - i]);
    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}