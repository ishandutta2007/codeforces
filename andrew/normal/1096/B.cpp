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

ll pref[MAXN][26];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("fence.in","r",stdin);
    //freopen("fence.out","w",stdout);

    ll n;
    cin >> n;

    string a;
    cin >> a;
    a = "*" + a;

    ll MOD = 998244353, ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 26; j++)pref[i][j] = pref[i - 1][j];
        pref[i][a[i] - 'a']++;
    }

    set <ll> s;

    for(int i = 1; i <= n; i++){
        if(s.size() > 1)continue;
        ll l = i, r = n;
        while(l < r){
            ll c = (l + r) >> 1;
            ll kol = 0;
            for(int i1 = 0; i1 < 26; i1++){
                if(pref[i - 1][i1] || pref[n][i1] - pref[c][i1])kol++;
            }

            if(kol > 1)l = c + 1; else r = c;

        }

        ans += n - l + 1;
        ans %= MOD;
        s.insert(a[i]);
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}