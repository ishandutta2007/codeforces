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
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

const ll mod = 1e9 + 7;

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)(res *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return res;
}

const ll N = 1e5 + 10;


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        string s;
        cin >> s;
        if(s[0] == '>')cout << "0\n"; else
            if(s[n - 1] == '<')cout << "0\n";
        else {
            ll ans = 1e18;
            for(int i = 0; i < n; i++)if(s[i] == '>')ans = min(ans, ll(i));
            for(int i = n - 1; i >= 0; i--)if(s[i] == '<')ans = min(ans, n - ll(i) - 1);
            cout << ans << "\n";
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}