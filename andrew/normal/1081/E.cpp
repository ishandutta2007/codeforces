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

bool check(ll x){
    ll k = sqrt(x);
    while(k * k < x)k++;
    while(k * k > x)k--;
    if(k * k == x)return 1;
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    ll sc = 0;

    ll uk = 1;

    vector <ll> a;


    for(int i = 1; i <= n / 2; i++){
        ll x;
        cin >> x;
        while(sc >= uk * uk || !check(uk * uk + x)){
                uk++;
                if(uk * uk > 1e13)vout("No");
        }
        a.p_b(uk * uk - sc);
        sc = uk * uk;
        a.p_b(x);
        sc += x;
        uk++;
    }
    cout << "Yes\n";

    for(auto i : a)cout << i << " ";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}