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

int n, m;
vector <int> g[maxn];
ll d[maxn];
int a[maxn], b[maxn], c[maxn];
int x;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        g[a[i]].pb(i);
        g[b[i]].pb(i);
    }
    for(int i = 1; i<=n; i++)
        d[i] = (1ll << 50);
    scanf("%d", &x);
    priority_queue < pll > pq;
    d[x] = 0;
    pq.push(mp (0, x));
    while(pq.size() > 0){
        pll cur = pq.top();
        pq.pop();
        cur.f *= -1;
        if(d[cur.s] < cur.f) continue;
        for(int i = 0; i<g[cur.s].size(); i++){
            int id = g[cur.s][i], to = (a[id] == cur.s) ? b[id]:a[id];
            if(d[to] > cur.f + c[id]){
                d[to] = cur.f + c[id];
                pq.push(mp(-d[to], to));
            }
        }
    }
    vector < pll > v;
    for(int i = 1; i <= n; i++){
        v.pb(mp(d[i], i));
    }
    sort(all(v));
    vector < int > ans;
    ll sum = 0;
    for(int i = 1; i < v.size(); i++){
        int vv = v[i].s;
        int cur = -1;
        for(int j = 0; j < g[vv].size(); j++){
            int id = g[vv][j];
            int to = (a[id] == vv) ? b[id] : a[id];
            if(d[to] + c[id] == d[vv]){
                if(cur == -1 || c[cur] > c[id] ) cur = id;
            }
        }
        sum += c[cur];
        ans.pb(cur);
    }
    printf("%I64d\n", sum);
    for(int i = 0; i < ans.size(); i++){
        printf("%d ", ans[i]);
    }
    




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}