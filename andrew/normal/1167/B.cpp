#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    vector <ll> d(6), c(6);
    d[0] = 4;
    d[1] = 8;
    d[2] = 15;
    d[3] = 16;
    d[4] = 23;
    d[5] = 42;

    cout << "? 1 2" << endl;
    ll a, b;
    cin >> a;
    cout << "? 2 3" << endl;
    cin >> b;
    ll x, y, x1, y1;

    for(int i = 0; i < 6; i++)
    for(int j = i + 1; j < 6; j++)if(d[i] * d[j] == a){
        x = d[i], y = d[j];
    }else if(d[i] * d[j] == b){
        x1 = d[i], y1 = d[j];
    }

    ll dd = 0;
    if(x == x1 || x == y1)dd = x; else dd = y;

    if(x != dd){
        c[0] = x;
    }else c[0] = y;

    c[1] = dd;

    if(x1 != dd)c[2] = x1; else c[2] = y1;
    cout << "? 3 4" << endl;
    cin >> x;
    c[3] = x / c[2];
    cout << "? 4 5" << endl;
    cin >> x;
    c[4] = x / c[3];
    ll t = 1;
    for(auto i : d)t *= i;
    for(int i = 0; i < 5; i++)t /= c[i];
    c[5] = t;
    cout << "!";
    for(int i = 0; i < 6; i++)cout << " " << c[i];
    cout << endl;
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}