#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
#pragma GCC optimize("unroll-loops")

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


char c[1001][1001];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    map <ll, ll> mpx, mpy;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c[i][j];
            if(c[i][j] == '*'){
                mpy[i]++;
                mpx[j]++;
            }
        }
    }

    set <ll> sx, sy;

    for(auto i : mpx)if(i.se > 1)sx.insert(i.fi);
    for(auto i : mpy)if(i.se > 1)sy.insert(i.fi);

    if(sx.size() != 1 || sy.size() != 1)vout("NO");

    ll x = *sx.begin(), y = *sy.begin();
    if(c[y][x] == '.')vout("NO");

    for(int j = x - 1; j >= 0; j--){
        if(j == 0 || c[y][j] == '.'){
            if(j == x - 1)vout("NO");
            break;
        }
        c[y][j] = '.';
    }

    for(int j = x + 1; j <= m + 1; j++){
        if(m + 1 == j || c[y][j] == '.'){
            if(j == x + 1)vout("NO");
            break;
        }
        c[y][j] = '.';
    }

    for(int i = y - 1; i >= 0; i--){
        if(i == 0 || c[i][x] == '.'){
            if(i == y - 1)vout("NO");
            break;
        }
        c[i][x] = '.';
    }

    for(int i = y + 1; i <= n + 1; i++){
        if(i == n + 1 || c[i][x] == '.'){
            if(i == y + 1)vout("NO");
            break;
        }
        c[i][x] = '.';
    }


    c[y][x] = '.';


    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)if(c[i][j] == '*')vout("NO");

    vout("YES");

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}