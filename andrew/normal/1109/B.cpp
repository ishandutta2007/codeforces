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
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    ll n = s.size();

    vector <ll> a(26);

    for(auto i : s)a[i - 'a']++;

    if(*max_element(all(a)) >= n - 1)vout("Impossible");

    for(int i = 2; i <= n; i++){
        string c, t;
        for(int j = i; j <= n; j++)c += s[j - 1];
        for(int j = 1; j < i; j++)c += s[j - 1];
        t = c;
        reverse(all(t));
        if(t == c && c != s)vout(1);
    }

    vout(2);

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}