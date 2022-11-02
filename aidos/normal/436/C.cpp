#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;
string c[1111];
int n, m, k, w, d[1111][1111];
int p[1111];
int get(int l, int r){
    int x = 0;
    for(int i = 0; i < n; i++){
        if( c[l][i] != c[r][i]) x++;
    }
    return x;
}

 
int find_set (int v) {
    if (v == p[v])
        return v;
    return find_set (p[v]);
}
bool used[1111];
vector < pii > ans;
vector < int > v[1111];
int ans1 = 0;
void dfs(int x, int l){
    if( l == -1) {
        ans1 += n;
    }
    else ans1 += d[x][l];
    used[x] = 1;
    ans.pb(mp(x+1, l+1));
    for(int i = 0; i < v[x].size(); i++){
        int to = v[x][i];
        if( used[to] == 0) dfs(to, x);
    }
}
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n >> m >> k >> w;
    for(int i = 0; i < k; i++){
        p[i] = i;
    }
    for(int i = 0; i < k; i++){
        string a;
        for(int j = 0; j < n; j++){
            cin >> a;
            c[i] += a;
        }
    }
    set < pair < int, pii > > S;
    n *= m;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < i; j++){
            d[i][j] = d[j][i] = get(i, j) * w;
            S.insert( mp( d[i][j], mp(i, j)));
        }
    }
    for( set < pair < int, pii > > :: iterator it = S.begin(); it != S.end(); it++){
        if( it->f > n ){
            break;
        }
        int i = it->s.f, j = it->s.s;
    int a = find_set (i);
    int b = find_set (j);
    if (a != b){
        p[b] = a;
        v[i].pb(j);
        v[j].pb(i);
    }

    }
    for(int i = 0; i < k; i++){
        if(used[i] == 0){
            dfs(i, -1);
        }
    }
    cout << ans1 << endl;
    for(int i=0; i < ans.size(); i++) cout << ans[i].f << " " << ans[i].s << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}