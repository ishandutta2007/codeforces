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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
int n, k;
vector < int > g[100100];
int a[100100];
int ans = 0;
void go(int v, int p, int cnt){
    if( cnt > k ) return;
    int c = 0;
    if(a[v]) cnt++;
    else cnt = 0;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if( to == p) continue;
        c++;
        go(to, v, cnt);
    }
    if(cnt <= k && c == 0 ) {
        ans++;
    }
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].pb( b );
        g[b].pb( a);
    }

    go( 0, -1, 0);

    cout << ans << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}