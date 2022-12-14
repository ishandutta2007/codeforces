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
#define time _time

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e6 + 5;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll bp(ll a, ll n){
    ll res = 1;
    while(n){
        if(n & 1)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

ll last[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("power-sums.in","r",stdin);
    //freopen("power-sums.out","w",stdout);

    ll q;
    cin >> q;

    for(int i = 2; i <= N; i++)if(!last[i]){
        last[i] = i;
        if(ll(i) * ll(i) <= N)for(int j = i * i; j <= N; j += i)last[j] = i;
    }

    while(q--){
        ll n;
        cin >> n;
        vector <ll> a(n + 1);
        map <ll, ll> mp;
        ll ans = 1;
        set <ll> s;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s.insert(a[i]);
        }

        ll kol = 1, mn = 1e18;
        ll l = *s.begin(), r = *(--s.end());
        ans = l * r;

        kol = n;
        bool f = 1;

        for(ll i = 2; i * i <= ans; i++)if(ans % i == 0){
            if(s.find(i) == s.end())f = 0;else kol--;
            if(i * i != ans){
                if(s.find(ans / i) == s.end())f = 0;else kol--;
            }
        }

        if(f && !kol)cout << ans << "\n"; else cout << "-1\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}