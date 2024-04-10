#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

struct node {
    int x, y;
    node() {}
    node(int _1, int _2) {x = _1, y = _2;}
};

int n, m, r, c, x, y;

char ch[2010][2010];

bool vis[2010][2010];

int Dis[2010][2010];

int main() {
    scanf("%d%d%d%d%d%d", &n, &m, &r, &c, &x, &y);
    for(int i = 1; i <= n; i++) scanf("%s", ch[i] + 1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(ch[i][j] == '.') vis[i][j] = 1;
    vector <node> V0, V1;
    V1.clear();
    V0.push_back(node(r, c));
    // practice 0/1 bfs?
    memset(Dis, 63, sizeof Dis);
    Dis[r][c] = 0;
    for(; !V0.empty();) {
        for(int i = 0; i < V0.size(); i++) {
            node tmp = V0[i];
            if(!vis[tmp.x][tmp.y]) {
                Dis[tmp.x][tmp.y] = 1 << 30;
                continue;
            }
            int v = Dis[tmp.x][tmp.y];
            if(tmp.y != 1 && Dis[tmp.x][tmp.y - 1] > v + 1) {
                Dis[tmp.x][tmp.y - 1] = v + 1;
                V1.push_back(node(tmp.x, tmp.y - 1));
            }
            if(tmp.y != m && Dis[tmp.x][tmp.y + 1] > v) {
                Dis[tmp.x][tmp.y + 1] = v;
                V0.push_back(node(tmp.x, tmp.y + 1));
            }
            if(tmp.x != 1 && Dis[tmp.x - 1][tmp.y] > v) {
                Dis[tmp.x - 1][tmp.y] = v;
                V0.push_back(node(tmp.x - 1, tmp.y));
            }
            if(tmp.x != n && Dis[tmp.x + 1][tmp.y] > v) { //!!!
                Dis[tmp.x + 1][tmp.y] = v;
                V0.push_back(node(tmp.x + 1, tmp.y));
            }
        }
        V0 = V1;
        V1.clear();
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            int a = Dis[i][j], b = a - (c - j);
            assert(b >= 0 && a >= 0);
            if(a <= x && b <= y) ans++;
        }
    printf("%d\n", ans);
    return 0;
}