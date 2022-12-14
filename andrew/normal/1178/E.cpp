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
#define delete _delete

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e9 + 5;
const ll mod = 998244353;
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

    ll l = 0, r = n - 1;

    string c;

    while(r - l + 1 > 3){
        if(s[l] == s[r]){
            c += s[l];
            l++;
            r--;
            continue;
        }
        if(s[l + 1] == s[r - 1]){
            c += s[l + 1];
            l += 2;
            r -= 2;
            continue;
        }
        if(s[l + 1] == s[r]){
            c += s[l + 1];
            l += 2;
            r--;
            continue;
        }

        if(s[l] == s[r - 1]){
            c += s[l];
            l++;
            r -= 2;
            continue;
        }
        l += 2;
        r -= 2;

    }

    cout << c;
    if(l <= r)cout << s[l];
    reverse(all(c));
    cout << c << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}