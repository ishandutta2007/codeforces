#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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
#define delete _delete

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e6;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    ll mx = 0;

    mx = *max_element(all(a));

    ll pos = 0;

    for(int i = 1; i <= n; i++)if(a[i] == mx)pos = i;

    ll l = pos - 1, r = pos + 1, last = mx;

    while(l > 0 || r <= n){
        if(!l){
            if(last <= a[r])vout("NO");
            last = a[r];
            r++;
        }else if(r > n){
            if(last <= a[l])vout("NO");
            last = a[l];
            l--;
        }else{
            if(a[l] > a[r]){
                if(last <= a[l])vout("NO");
                last = a[l];
                l--;
            }else{
                if(last <= a[r])vout("NO");
                last = a[r];
                r++;
            }
        }
    }

    vout("YES");

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}