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
int n;
int a[3300];
vector < pii > v[3300];
int p[3300], sz[3300], sum[3300];
int aa = 0;
int cnt = 1;
void dfs(int x, int y, int num){
    for(int i = 0; i < v[x].size(); i++){
        int to = v[x][i].f;
        if( to == y ) continue;
        if( p[to] == p[x] ) dfs( to, x, num );
    }
    p[x] = num;
    sum[num] += a[x];
    sz[num]++;
}
vector < pair < int, pii > > ans;
bool check(){
    for(int i = 0; i < cnt; i++){
        if( sz[i] > aa - sum[i] ) return false;
    }
    return true;
}
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        v[x].pb(mp(y, c));
        v[y].pb(mp(x, c));
        
        ans.pb(mp(c, mp(x, y)));
    }

    for(int i = 0; i<n; i++){ cin >> a[i];aa += a[i];}
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        sz[p[ans[i].s.s]] = 0;
        sum[p[ans[i].s.s]] = 0;
        dfs( ans[i].s.s,ans[i].s.f, p[ans[i].s.s]);
        dfs( ans[i].s.f,ans[i].s.s, cnt);
        cnt++;
        if( check() ) {
            cout << ans[i].f << endl;
            return 0;
        }
        //cout << ans[i].f << endl;
    }
    cout << 0 << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}