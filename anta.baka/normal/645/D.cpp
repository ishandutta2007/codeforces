#include <stdio.h>
#include <vector>
using namespace std;
const int N = 1e5;
vector<pair<int,int>> gr[N];
int n, m, as, pw[N];
vector<int> dp;

void dfs(int v, int x) {
    bool any = false;
    for(int i = 0, sz = (int)gr[v].size(); i < sz; i++)
        if(gr[v][i].second <= x) {
            if(dp[gr[v][i].first] == 0)
                dfs(gr[v][i].first, x);
            dp[v] = max(dp[v], dp[gr[v][i].first] + 1);
            any = true;
        }
    if(any == false)
        dp[v] = 1;
}

bool ok(int x) {
    dp.assign(n, 0);
    dfs(as, x);
    return (dp[as] == n);
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0, u, v; i < m; i++) {
        scanf("%d%d", &u, &v);
        gr[u-1].push_back(make_pair(v-1, i));
        pw[v-1]++;
    }
    for(int i = 0; i < n; i++)
        if(pw[i] == 0)
            as = i;
    int bl = 0, br = m;
    while(bl < br) {
        int bm = (bl + br) >> 1;
        (ok(bm) ? br=bm : bl=bm+1);
    }
    printf("%d",(bl == m ? -1 : bl+1));
    return 0;
}