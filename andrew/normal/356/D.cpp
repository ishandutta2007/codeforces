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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = (int)7e4 + 1;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll Ft[MAXN];

bitset <N> a, b, c;

ll val[MAXN];

vector <ll> ans[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, s;
    cin >> n >> s;
    vector <ll> arr(n + 1);
    vector <bool> us(n + 1);

    for(int i = 1; i <= n; i++)cin >> arr[i];

    ll pos = max_element(arr.begin() + 1, arr.end()) - arr.begin();
    s -= arr[pos];

    if(s < 0)vout(-1);
    a[0] = 1;

    us[pos] = 1;

    for(int i = 1; i <= n; i++)if(i != pos){
        b = (a << arr[i]) | a;
        c = b ^ a;
        a = b;
        while(c.any()){
            ll t = c._Find_first();
            c[t] = 0;
            Ft[t] = i;
        }
    }

    if(!a[s])vout(-1);

    vector <pll> ats;

    ll x = s;
    while(x){
        us[Ft[x]] = 1;
        x -= arr[Ft[x]];
    }

    for(int i = 1; i <= n; i++)if(i != pos){
        if(us[i])val[i] = arr[i];
        else{
            ats.p_b({arr[i], i});
        }
    }

    sort(ats.begin(), ats.end());

    ll last = 0, what = 0;

    for(auto i : ats){
        val[i.se] = i.fi - last;
        last = i.fi;
        if(what)ans[i.se].p_b(what);
        what = i.se;
    }

    if(what)ans[pos].p_b(what);
    val[pos] = arr[pos] - last;

    for(int i = 1; i <= n; i++){
        cout << val[i] << " " << ans[i].size();
        for(auto j : ans[i])cout << " " << j;
        cout << "\n";
    }

    return 0;
}