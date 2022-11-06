#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 800100;

struct node
{
    int v;
    LL w;
    bool operator < (const node &b)const
    {
        return w>b.w;

    }
}now,tmp;

const int ooo = 1e9;
const LL oo = (LL) ooo * ooo;
vector<node> g[V];
void add(int u, int v, int w) {
    g[u].PB({v, w});
}
bool vis[V];
LL d[V];
int n;
void dijkstra(int s)
{
    for (int i = 0; i < 4 * n; ++i) d[i] = oo;
    memset(vis,false,sizeof(vis));
    d[s]=0;
    now.v=s;
    now.w=0;
    priority_queue<node>q;
    q.push(now);
    while(!q.empty())
    {
        now=q.top();
        q.pop();
        if(vis[now.v]==true)
        {
            continue;
        }
        vis[now.v]=true;
        int len=g[now.v].size();
        for(int i=0;i<len;i++)
        {
            tmp=g[now.v][i];
            if(d[now.v]+tmp.w<d[tmp.v])
            {
                d[tmp.v]=d[now.v]+tmp.w;
                q.push((node){tmp.v,d[tmp.v]});
            }
        }
    }
}

int m, u, v, w;

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < 4 * n; ++i) g[i].clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            --u, --v;
            for (int j = 0; j < 4; ++j) add(u + j * n, v + j * n, w), add(v + j * n, u + j * n, w);
            for (int j = 0; j < 2; ++j) add(u + j * n, v + (j + 2) * n, 0), add(v + j * n, u + (j + 2) * n, 0);
            for (int j = 0; j <= 2; j += 2) add(u + j * n, v + (j + 1) * n, 2 * w), add(v + j * n, u + (j + 1) * n, 2 * w);
            add(u, v + 3 * n, w);
            add(v, u + 3 * n, w);
        }
        dijkstra(0);
        for (int i = 1; i < n; ++i) printf("%I64d ", d[i + 3 * n]); puts("");
    }
    return 0;
}

/*
5 4
5 3 4
2 1 1
3 2 2
2 4 2

6 8
3 1 1
3 6 2
5 4 2
4 2 2
6 1 1
5 2 1
3 2 3
1 5 4

7 10
7 5 5
2 3 3
4 7 1
5 3 6
2 7 6
6 2 6
3 7 6
4 2 1
3 1 4
1 7 4
*/