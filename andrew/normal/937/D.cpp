#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
#include <iomanip>
#include <set>
#include <sstream>
#include <ctime>

#define rust(a, b, c, d) sqrt(sqr(a - c) + sqr(b - d))
#define sqr(a) (a)*(a)
#define m_p make_pair
#define fi first
#define se second
#define pb push_back
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)


typedef long long ll;
const int MAXINT=2147483640;
const ll MAXLL=9223372036854775800LL;
const ll MAXN=1000000;
const double pi=3.1415926535897932384626433832795;
using namespace std;
vector <ll> v[MAXN],va;
ll i,j,n,m,k,ans,sc,a[MAXN],b[MAXN],c,x;
bool f[MAXN][2];
ll pr[MAXN][2];
void dfs(ll x,ll ke,ll pe){
    if(f[x][ke])return;
    f[x][ke] = 1;
    pr[x][ke] = pe;
    ke++;
    ke %= 2;
    ll i,nn = v[x].size();
    for(i  = 0; i < nn; i++)dfs(v[x][i],ke,x);
    return;
}
void way(ll x){
    ll gl = 0;
    while(x != 0){
        va.pb(x);
        x = pr[x][gl];
        gl++;
        gl %= 2;
    }
    reverse(va.begin(),va.end());
    cout << "Win" << endl;
    for(i = 0; i < va.size(); i++)cout << va[i] << " ";
    exit(0);
}
void dfs1(ll x){
    if(b[x] == 1){
        cout << "Draw" << endl;
        exit(0);
    }
    if(b[x] == 2)return;
    b[x] = 1;
    ll i,nn=v[x].size();
    for(i =0;i < nn; i++)dfs1(v[x][i]);
    b[x] = 2;
    return;
}
int main()
{
// freopen("1.in", "r", stdin);
// freopen("1.out", "w", stdout);

    fast_io;
    srand(time(0));

    cin >> n >> m;
    for(i = 1; i <= n; i++){
        cin >> m;
        while(m--){
            cin >> x;
            v[i].pb(x);
        }
    }
    cin >> k;
    dfs(k,1ll,0ll);
    for(i = 1; i <= n; i++)if(f[i][0] && v[i].size() == 0)way(i);
    dfs1(k);
    cout << "Lose" << endl;
    return 0;
}
/*
6 6
1 2
2 3 6
1 4
1 5
1 1
0
1
*/