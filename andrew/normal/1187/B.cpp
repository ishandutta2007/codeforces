#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 gen;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


ll v[26];

ll pref[210000][26];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    string s;
    cin >> s;

    for(int i = 0; i < n; i++){
        if(i)for(int j = 0; j < 26; j++)pref[i][j] = pref[i - 1][j];
        pref[i][s[i] - 'a']++;
    }

    ll q;
    cin >> q;

    while(q--){
        string t;
        cin >> t;
        for(int i = 0; i < 36; i++)v[i] = 0;
        for(auto i : t)v[i - 'a']++;
        ll l = 0, r = n - 1;
        while(l < r){
            ll c = (l + r) >> 1;
            bool fl = 1;
            for(int j = 0; j < 26; j++)if(pref[c][j] < v[j])fl = 0;
            if(fl)r = c; else l = c + 1;
        }
        cout << l + 1 << "\n";
     }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}