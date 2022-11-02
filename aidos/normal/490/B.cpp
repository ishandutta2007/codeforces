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
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;

using namespace std;

int n;
int a[1000100], b[1000100], used[1000100];
vector < int > v[1000100], g[1000100];


void dfs(int pos, vector < int > &ans){
    if( pos == 0) return;
    ans.pb(pos);
    forit(v[pos]) dfs(*it, ans);
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n;
    for(int i = 0, x, y; i < n ; ++i){
        cin >> x >> y;
        v[x].pb( y );
        g[y].pb( x );
        a[i] = x;
        b[i] = y;
    }
    vector < int > vv[3], ans;
    forit(v[0])
        dfs(*it,  vv[1]);
    for(int i = 0; i<n; i++){
        if( g[a[i]].size() == 0) {
            dfs(a[i], vv[0]);    
        }
    }
    int cur = 0, pos = 0;

    while( vv[cur].size() > pos){
        ans.pb( vv[cur][pos]);
        cur = 1-cur;
        if( !cur ) pos++;
    }
    forit(ans) cout << (*it) << " ";

    




    



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}