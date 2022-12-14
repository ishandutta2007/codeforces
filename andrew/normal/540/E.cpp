#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 2e9;
const ll M = 300000;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector <pii> v[MAXN];
bool f[MAXN];
int pr[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n;
    cin >> n;

    map <ll, ll> mp;

    while(n--){
        ll a, b;
        cin >> a >> b;
        if(mp.find(a) == mp.end())mp[a] = a;
        if(mp.find(b) == mp.end())mp[b] = b;
        swap(mp[a], mp[b]);
    }

    ll ans = 0;

    ordered_set <ll> s, st;

    for(auto i : mp){
        st.insert(i.se);
    }

    vector <pll> v;

    for(auto i : mp){
        if(i.se <= i.fi){
            ans += i.fi - i.se + 1 - (st.order_of_key(i.fi + 1) - st.order_of_key(i.se));
        }
        ans += sz(s) - s.order_of_key(i.se);
        s.insert(i.se);
        v.p_b(i);
    }

    reverse(all(v));

    for(auto i : v){
        if(i.fi <= i.se){
            ans += i.se - i.fi + 1 - (st.order_of_key(i.se + 1) - st.order_of_key(i.fi));
        }
    }

    cout << ans << "\n";

    return 0;
}