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
const ll mod = 1e9 + 7;
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

    vector <ll> pref(n);

    for(int i = 0; i < n; i++){
        pref[i] = 1e18;
        if(i)pref[i] = pref[i - 1];
        pref[i] = min(pref[i], ll(s[i] - 'a'));
    }

    cout << "Mike\n";

    for(int i = 1; i < n; i++){
        if(s[i] - 'a' > pref[i - 1])cout << "Ann\n";
        else cout << "Mike\n";
    }

    return 0;
}