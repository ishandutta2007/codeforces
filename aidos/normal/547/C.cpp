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
const int maxn = (int) 5e5 + 10;

using namespace std;

vector < int >  g[maxn];
int col[maxn];
bool is_p[maxn];
int a[maxn];
int n, m;
bool was[maxn];
bool ok[maxn];
int d[maxn];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    for(int i = 0; i < 500001; i++)
        ok[i] = 1;
    for(int i = 2; i < 500001; i++){
        if(!is_p[i]){
            for(int j = i; j < 500001; j+=i){
                int cur = j;
                is_p[j] = 1;

                while(cur % i == 0) {
                    cur/=i;
                    col[j]++;
                }
                if(cur * i != j) ok[j] = false;
            }
        }
    }
    for(int i = 2; i < 500001; i++)
        for(int j = i; j < 500001; j+=i)
            g[j].pb(i);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    ll sz = 0;
    ll ans = 0;
    for(int i = 0, x; i < m; i++){
        scanf("%d", &x);
        x--;
        if(was[x]){
            for(int j = 0; j < g[a[x]].size(); j++){
                int to = g[a[x]][j];
                if(!ok[to]) continue;
                d[to]--;    
                if(col[to] & 1) ans -= d[to];
                else ans += d[to];
            }
            sz--;
            was[x] = 0;
        }
        else {
            for(int j = 0; j < g[a[x]].size(); j++){
                int to = g[a[x]][j];
                if(!ok[to]) continue;
                if(col[to] & 1) ans += d[to];
                else ans -= d[to];
                d[to]++;
            }
            
            was[x] = 1;
            sz++;
        }
//      cout << ans << endl;
        printf("%I64d\n", sz * (sz-1)/2 - ans);
    }
    







    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}