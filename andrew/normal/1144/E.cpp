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

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

vector <ll> a1, b1, c1, d1;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    string a, b, c;
    cin >> a >> b;
    a1.resize(n);
    b1.resize(n);
    c1.resize(n);
    for(int i = 0; i < n; i++){
        a1[i] = a[i] - 'a' + 1;
        b1[i] = b[i] - 'a' + 1;
    }

    bool fl = 0;

    for(int i = 0; i < n; i++)c += "0";

    for(int i = n - 1; i >= 0; i--){
        ll val = b1[i] - a1[i];
        if(fl)val--;
        fl = 0;
        if(val < 0){
            fl = 1;
            val += 26;
        }
        c1[i] = val;
    }
    ll val = 0;

    for(int i = 0; i < n; i++){
        val *= 26;
        val += c1[i];
        c1[i] = val / 2;
        val %= 2;
    }

    val = 0;

    for(int i = n - 1; i >= 0; i--){
        val += c1[i] + a1[i];
        if(val > 26){
            c[i] = char('a' + val - 27);
        }else c[i] = char('a' + val % 27 - 1);
        val /= 27;
    }

    cout << c << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}