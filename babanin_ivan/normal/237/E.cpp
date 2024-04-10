#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

struct edge {
    int x, y;
    int cap;
    int flow;
    int cost;
    int id;
    edge(int x_, int y_, int cap_, int cost_, int id_):x(x_), y(y_), cap(cap_), cost(cost_), id(id_) {
        flow = 0;
    }
};

int need[27];
int s[150][27];
int a[150];
//pair <int, int> alp[150];
vector <edge> g[200];
int n;

int try_push(int v, int id) {
    return g[v][id].cap - g[v][id].flow;
}

int d[200];
pair <int, int> p[200];

int used[200];
int tim = 1;

/*void dfs(int v) {
    used[v] = tim;  
    for (int i = 0; i < g[v].size(); ++i)
        if ((used[g[v][i].y] != tim) && (try_push(v, i) > 0))
            dfs(g[v][i].y);
}*/

bool find_path(int st, int end) {
    d[st] = 0;
    for (int i = st + 1; i <= end; ++i)
        d[i] = inf;

    for (int i = st; i <= end; ++i) {
        bool f = false;
        for (int x = st; x <= end; ++x) {
            if (d[x] != inf) {
                for (int y = 0; y < g[x].size(); ++y)
                    if (try_push(x, y)) {
                        if ((d[x] + g[x][y].cost) < d[g[x][y].y]) {
                            f = true;
                            d[g[x][y].y] = d[x] + g[x][y].cost;
                            p[g[x][y].y] = mp(x, y);
                        }
                    }
            }
        }
        if (!f) {
            break;
        }
    }
    return (d[end] != inf);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int ans;
    string tmp;
    cin >> tmp;
    ans = tmp.size();
    for (int i = 0; i < tmp.size(); ++i) {
        ++need[int(tmp[i] - 'a')];
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        for (int j = 0; j < 26; ++j)
            s[i][j] = 0;
        for (int j = 0; j < tmp.size(); ++j)
            ++s[i][int(tmp[j] - 'a')];
        cin >> a[i];
    }
    int st = 1;
    int maxfree = 2;
    for (int i = 0; i < n; ++i) {
        g[st].pb(edge(st, i + 2, a[i], 0, g[i + 2].size()));
        g[i + 2].pb(edge(i + 2, st, 0, 0, g[st].size() - 1));
        //maxfree = i + 2 + 1;
    }

    maxfree = n + 2;
    for (int i = 0; i < n; ++i) {
        //alp[i] = mp(maxfree, maxfree + 25);
        //maxfree += 26;
        for (int j = 0; j < 26; ++j) {
            if (s[i][j] == 0)
                continue;
            g[i + 2].pb(edge(i + 2, maxfree + j, s[i][j], i + 1, g[maxfree + j].size()));
            g[maxfree + j].pb(edge(maxfree + j, i + 2, 0, -(i + 1), g[i + 2].size() - 1));
        }
    }
    int end = maxfree + 26;
    for (int i = 0; i < 26; ++i) {
        //printf("%c %d\n", char('a' + i), maxfree + i);
        if (need[i] == 0)
            continue;
        g[maxfree + i].pb(edge(maxfree + i, end, need[i], 0, g[end].size()));
        g[end].pb(edge(end, maxfree + i, 0, 0, g[maxfree + i].size() - 1));
    }

    int resflow = 0;
    int ressum = 0;
    /*
    for (int i = 0; i <= end; ++i) {
        printf("Vertex %d\n", i);
        for (int j = 0; j < g[i].size(); ++j) {
            printf("%d %d %d %d %d %d\n", j, g[i][j].x, g[i][j].y, g[i][j].cap, g[i][j].cost, g[i][j].id);
        }
        printf("\n\n");
    }
    //*/
    while (find_path(st, end)) {
    /*while (true) {
        bool f1 = find_path(st,end);
        ++tim;
        dfs(st);
        bool f2;
        if (used[end] == tim) 
            f2 = true;
        else f2 = false;
        
        if (!f1)
            break;*/

        int mincap = inf;
        int curv = end;
        while (curv != st) {
            mincap = min(mincap, try_push(p[curv].first, p[curv].second));
            curv = p[curv].first;
        }
        resflow += mincap;
        ressum += mincap * d[end];

        curv = end;
        while (curv != st) {
            g[p[curv].first][p[curv].second].flow += mincap;
            g[curv][g[p[curv].first][p[curv].second].id].flow -= mincap;
            curv = p[curv].first;
        }
    }
    if (resflow != ans)
        printf("-1\n");
    else printf("%d\n", ressum);
    return 0;
}