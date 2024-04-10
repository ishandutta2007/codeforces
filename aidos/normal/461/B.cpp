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
const int mod = (int) 1e9 + 7;
#define MAXN (int) (1e5) + 10
using namespace std;

int n;
int col[MAXN];
vector < int > g[MAXN];
int binpow(int cur, int k){
    if( k < 0) return 0;
    if( k == 0) return 1;
    if( k & 1) return binpow(cur, k - 1) * 1ll * cur % mod;
    return binpow( cur * 1ll * cur % mod, k/2);
}
pii dfs(int x){
    vector < pii > cur;
    for(int i = 0; i < g[x].size(); i++){
        int to = g[x][i];
        cur.pb(dfs(to));
    }
    //cout << x << " " << cur.size() << endl;
    //cerr << x << endl;
    

        pii ans = mp(0, 0);
        if( col[x] ) ans.f = 1;
        else ans.s = 1;
        int d = cur.size();
        for(int i = 0; i < d; i++){
            int tmp;
            tmp = ((ll)ans.s * 1ll * cur[i].f % mod + (ll)ans.f * 1ll * cur[i].f % mod) % mod + ans.f * 1ll * cur[i].s % mod;
            tmp %= mod;
            ans.s = ans.s * 1ll*cur[i].f % mod + cur[i].s * 1ll * ans.s % mod;
            ans.f = tmp;
            ans.s  %= mod;
        }
        return ans;
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i = 1; i<n; i++){
        int x;
        scanf("%d", &x);
        g[x].pb(i);
    }
    for(int i =0; i < n; i++) scanf("%d", &col[i]);
    pii t = dfs(0);
    cout << t.f ;//<< " " << t.s << endl; 
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}