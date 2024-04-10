#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 1e6 + 10;
const int inf = 1e9;

vector < int > e[maxn];
int h[maxn];
int cnt[maxn];
bool use[maxn];

void dfs(int v, int d) {
    h[d]++;
    use[v] = 1;
    for (int i = 0; i < (int)e[v].size(); i++)
        if (!use[e[v][i]])
            dfs(e[v][i], d + 1);
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int n, p, k, newFree, newMoney, v, u, tmp;
    int ans = 0;
    scanf("%d%d%d", &n, &k, &p);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    dfs(0, 0);
    int cur = 1;
    int free = k;
    int money = 0;
    for (int i = 1; i <= n; i++) {
        /*if (h[i] >= k) {
            ans = k;    
            break;
        }*/
        cnt[i] = h[i];
        money += k - free;
        free -= h[i];
        for (; free < 0 || money > p; ) {
            newFree = free + cnt[cur];
            newMoney = money - cnt[cur] * (i - cur); 
            if (newFree < 0 || newMoney > p) {
                free = newFree;
                money = newMoney;
                cur++;
                continue;
            }
            tmp = -free;
            if (i - cur != 0) {
                tmp = max(tmp, (money - p + (i - cur - 1)) / (i - cur));
            }
            cnt[cur] -= tmp;
            free += tmp;
            money -= (i - cur) * tmp;
            assert (free >= 0 && money <= p);
            break;
        }
        ans = max(ans, k - free);

    }

    printf("%d\n", ans);
    return 0;
}