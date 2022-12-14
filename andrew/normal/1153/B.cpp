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
#define hash sosat

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll mod = 1e9 + 7;
const ll mod1 = 998244353;
const ll N = 2e5;

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
        if(n % 2)(res *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return res;
}

ll a[1001][1001];
bool f[1001];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m, h;
    cin >> n >> m >> h;

    for(int j = 1; j <= m; j++){
        ll x;
        cin >> x;
        for(int i = 1; i <= n; i++)a[i][j] = x;
    }

    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        for(int j = 1; j <= m; j++)a[i][j] = min(a[i][j], x);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            bool fl;
            cin >> fl;
            if(!fl)a[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)cout << a[i][j] << " ";
        cout << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}