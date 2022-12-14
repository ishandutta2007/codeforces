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


const ll MOD = 1e9 + 7;
const ll N = 1e5;

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)(res *= a) %= MOD;
        (a *= a) %= MOD;
        n >>= 1;
    }
    return res;
}



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string t;
    cin >> t;
    ll kol = 0;
    for(auto i : t)if(i != 'a')kol++;
    if(kol % 2)vout(":(");
    string s = t, ans, c, d;
    ll n = s.size();
    vector <bool> f(n);
    kol /= 2;
    ll tk = kol;
    for(int i = n - 1; i >= 0; i--)if(kol){
        if(s[i] == 'a')vout(":(");
        kol--;
    }
    kol = tk;
    if(kol)s.erase(n - kol);
    n = s.size();
    ans = s;
    for(int i = s.size() - 1; i >= 0; i--)if(s[i] != 'a'){
        f[i] = 1;
    }
    for(int i = 0; i < n; i++){
        if(!f[i])c += s[i];else d += s[i];
    }
    s = ans;
    ans += d;
    if(ans == t)vout(s);
    vout(":(");
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}