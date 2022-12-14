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
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e6;
const ll inf = 1e10;
const ll mod = 1e9 + 7;
const ll mod1 = 998244353;
ll mod2;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll a[MAXN], st[MAXN], st1[MAXN], st2[MAXN];

ll ans = 0;

ll last[MAXN], zp, pos[MAXN], c[MAXN];
vector < pair <pii, int > > v[MAXN];
map <pair <pii, int>, int> mp;


void sol(ll l, ll r){
    if(l >= r)return;
    ll m = (l + r) >> 1;
    sol(l, m);
    sol(m + 1, r);
    zp++;
    for(int i = m + 1; i <= r; i++){
        if(last[a[i]] != zp){
            last[a[i]] = zp;
            pos[a[i]] = i;
        }
    }

    for(int i = l; i <= m; i++)c[a[i]] = 0;

    ll hash, hash1, hash2;
    hash = hash1 = hash2 = 0;
    mp.clear();

    ll ri = r + 1;
    for(int i = m; i >= l; i--){
        c[a[i]]++;
        if(c[a[i]] > 3)break;
        hash += st[a[i]];
        if(hash >= mod)hash -= mod;
        hash1 += st1[a[i]];
        if(hash1 >= mod1)hash1 -= mod1;
        hash2 += st2[a[i]];
        if(hash2 >= mod2)hash2 -= mod2;
        if(c[a[i]] == 3){
            hash -= 3 * st[a[i]];
            hash += 3 * mod;
            hash %= mod;
            hash1 -= 3 * st1[a[i]];
            hash1 += 3 * mod1;
            hash1 %= mod1;
            hash2 -= 3 * st2[a[i]];
            hash2 += 3 * mod2;
            hash2 %= mod2;
            if(last[a[i]] == zp){
                ri = min(ri, pos[a[i]]);
            }
        }
        mp[{{hash, hash1}, hash2}]++;
        if(ri != r + 1)v[ri].p_b({{hash, hash1}, hash2});
    }
    for(int i = m + 1; i <= r; i++)c[a[i]] = 0;
    hash = hash1 = hash2 = 0;
    for(int i = m + 1; i <= r; i++){
        for(auto j : v[i])mp[j]--;
        if(c[a[i]] == 0){
            hash += 3 * st[a[i]];
            hash %= mod;
            hash1 += 3 * st1[a[i]];
            hash1 %= mod1;
            hash2 += 3 * st2[a[i]];
            hash2 %= mod2;
        }
        c[a[i]]++;
        if(c[a[i]] > 3)break;
        hash -= st[a[i]];
        if(hash < 0)hash += mod;
        hash1 -= st1[a[i]];
        if(hash1 < 0)hash1 += mod1;
        hash2 -= st2[a[i]];
        if(hash2 < 0)hash2 += mod2;
        ans += mp[{{hash, hash1}, hash2}];
    }
    for(int i = m + 1; i <= r; i++)v[i].clear();
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    mod2 = 1e9 + 10 + rnd() % 100;
    while(1){
        bool ok = 1;
        for(ll i = 2; i * i <= mod2; i++)if(mod2 % i == 0){
            ok = 0;
            break;
        }
        if(ok)break;
        mod2++;
    }
    ll n;
    cin >> n;

    st[0] = st1[0] = 1;

    for(int i = 1; i <= n; i++){
        st[i] = (500009 * st[i - 1]) % mod;
        st1[i] = (500009 * st1[i - 1]) % mod1;
    }

    for(int i = 1; i <= n; i++)cin >> a[i];

    sol(1, n);

    cout << ans << "\n";

    return 0;
}