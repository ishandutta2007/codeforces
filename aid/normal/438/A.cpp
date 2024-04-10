#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1005;
int cost[MAXN];
char used[MAXN];
vector<int> g[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> cost[i];
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int maxv = -1;
        for(int j = 0; j < n; j++)
            if(!used[j] && (maxv == -1 || cost[j] > cost[maxv]))
                maxv = j;
        for(size_t j = 0; j < g[maxv].size(); j++)
            ans += cost[g[maxv][j]];
        used[maxv] = true;
        for(int j = 0; j < n; j++)
            for(int k = 0; k < (int)g[j].size(); k++)
                if(g[j][k] == maxv) {
                    swap(g[j][k], g[j].back());
                    g[j].pop_back();
                    k--;
                }
    }
    cout << ans << '\n';
    return 0;
}