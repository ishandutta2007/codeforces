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
typedef int ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

map <ll, ll> mp;

ll gcd(ll a, ll b){
    while(a && b)if(a > b)a %= b; else b %= a;
    return a + b;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("output.txt", "w", stdout);
    ll q;



    cin >> q;

    mp[1] = 0;
    mp[3] = 1;
    mp[7] = 1;
    mp[15] = 5;
    mp[31] = 1;
    mp[63] = 21;
    mp[127] = 1;
    mp[255] = 85;
    mp[511] = 73;
    mp[1023] = 341;
    mp[2047] = 89;
    mp[4095] = 1365;
    mp[8191] = 1;
    mp[16383] = 5461;
    mp[32767] = 4681;
    mp[65535] = 21845;
    mp[131071] = 1;
    mp[262143] = 87381;
    mp[524287] = 1;
    mp[1048575] = 349525;
    mp[2097151] = 299593;
    mp[4194303] = 1398101;
    mp[8388607] = 178481;
    mp[16777215] = 5592405;
    mp[33554431] = 1082401;

    while(q--){
        ll x;
        cin >> x;

        vector <ll> d;

        for(int i = 0; i < 32; i++)if((1ll << i) < x && !((1ll << i) & x)){
            d.p_b(i);
        }

        ll ans = 0;

        if(d.empty()){
            ans = mp[x];
        }else{
            for(auto i : d)ans += 1ll << i;
        }
        cout << __gcd(ans & x, ans ^ x)  << "\n";

    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}