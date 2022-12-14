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
const ll N = 2e6;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

map <ll, ll> mp;
map <ll, ll> mp1;

vector <ll> c;

bool check(){
    for(auto i : mp1)if(i.se < mp[i.fi])return 0;
    return 1;
}

void add(ll x){
    for(auto i : c){
        while(x % i == 0){
            mp1[i]++;
            x /= i;
        }
    }
}

void delete(ll x){
    for(auto i : c){
        while(x % i == 0){
            mp1[i]--;
            x /= i;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    vector <ll> a(n + 1);

    for(int i = 2; i * i <= k; i++)if(k % i == 0){
        while(k % i == 0){
            mp[i]++;
            k /= i;
        }
    }

    if(k > 1)mp[k]++;

    for(auto i : mp){
        c.p_b(i.fi);
        mp1[i.fi] = 0;
    }

    ll r = 1, ans = 0;

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i <= n; i++){
        if(r == i){
            add(a[i]);
            r++;
        }

        while(!check() && r <= n){
            add(a[r]);
            r++;
        }
        if(!check())break;
        ans += n - r + 2;
        delete(a[i]);
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}