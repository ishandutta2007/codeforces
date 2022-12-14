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

    ll n;
    cin >> n;

    string s;
    cin >> s;
    s = "*" + s;

    vector <ll> pref(n + 1), mx(n + 1);

    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1];
        if(s[i] == '(')pref[i]++; else pref[i]--;
    }

    for(int i = n; i >= 1; i--){
        mx[i] = 1e18;
        if(i < n)mx[i] = mx[i + 1];
        mx[i] = min(mx[i], pref[i]);
    }

    ll mn = 1e18, ans = 0;

    for(int i = 1; i <= n; i++){
        if(mn < 0)break;
        ll last = 1;
        ll x = -1;
        if(s[i] == ')')x = 1, last = -1;
        ll sum = pref[i - 1];

        bool fl = 1;

        if(mx[i] - last + x < 0)fl = 0;


        if(pref[n] - last + x != 0)fl = 0;

        if(fl)ans++;
        mn = min(mn, pref[i]);

    }
    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}