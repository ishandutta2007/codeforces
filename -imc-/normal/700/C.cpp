#include <bits/stdc++.h>

using namespace std;

const int maxN = 1005;

typedef long long ll;

struct edge
{
    int u, v;
    int cost;
    bool closed;
    
    int other(int x)
    {
        assert(x == u || x == v);
        return x == u ? v : u;
    }
};

vector<int> adj[maxN];
vector<edge> edges;

vector<char> used;

vector<int> dfsStack;

int S, T;

bool dfs(int v)
{
    if (v == T)
        return true;
    
    used[v] = true;
    
    for (int eIndex: adj[v])
    {
        edge& e = edges[eIndex];
        int u = e.other(v);
        
        dfsStack.push_back(eIndex);
        
        if (!used[u])
        {
            if (dfs(u))
                return true;
        }
        
        dfsStack.pop_back();
    }
    
    return false;
}

int dfsCounter;
vector<int> bridges;

int inTime[maxN], minInTime[maxN];

vector<int> pathStack;
vector<char> onPath;

void bridgeDfs(int v, int pEdge = -1)
{
    used[v] = true;
    //printf("At %d\n", v + 1);
    
    inTime[v] = minInTime[v] = dfsCounter++;
    
    if (v == T)
    {
        for (int x: pathStack)
            onPath[x] = true;
    }
    
    for (int eIndex: adj[v])
    {
        edge& e = edges[eIndex];
        if (e.closed) continue;
        
        int u = e.other(v);
        
        if (eIndex == pEdge) continue;
        
        if (used[u])
        {
            //printf("look %d -> %d\n", v + 1, u + 1);
            minInTime[v] = min(minInTime[v], inTime[u]);
        }
        else
        {
            pathStack.push_back(eIndex);
            bridgeDfs(u, eIndex);
            pathStack.pop_back();
            minInTime[v] = min(minInTime[v], minInTime[u]);
            if (minInTime[u] > inTime[v])
            {
                //printf("got bridge %d -> %d (%d %d)\n", v + 1, u + 1, minInTime[v], minInTime[u]);
                bridges.push_back(eIndex);
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    scanf("%d %d", &S, &T);
    S--; T--;
    
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        
        u--; v--;
        adj[u].push_back(edges.size());
        adj[v].push_back(edges.size());
        edges.push_back(edge { u, v, w, false });
    }
    
    used.assign(n, false);
    
    if (!dfs(S))
    {
        printf("0\n0\n");
        return 0;
    }
    
    int bestCan = -1;
    vector<int> best;
    
    for (int eIndex: dfsStack)
    {
        edges[eIndex].closed = true;
        
        bridges.clear();
        pathStack.clear();
        dfsCounter = 0;
        used.assign(n, false);
        onPath.assign(m, false);
        //printf("DFS\n");
        bridgeDfs(S);
        
        edges[eIndex].closed = false;
        
        
        if (!used[T])
        {
            int can = edges[eIndex].cost;
            //fprintf(stderr, "can single %d\n", can);
            if (bestCan == -1 || can < bestCan)
            {
                bestCan = can;
                best = vector<int> { eIndex };
                continue;
            }
        }
        
        //fprintf(stderr, "close %d - %d: bridges ", edges[eIndex].u + 1, edges[eIndex].v + 1);
        //for (int x: bridges) fprintf(stderr, "(%d %d) ", edges[x].u + 1, edges[x].v + 1);
        //fprintf(stderr, "\n");
        
        for (int other: bridges)
        {
            if (!onPath[other]) continue;
            if (other == eIndex) continue;
            
            int can = edges[eIndex].cost + edges[other].cost;
            //printf("can %d\n", can);
            if (bestCan == -1 || can < bestCan)
            {
                bestCan = can;
                best = vector<int> { eIndex, other };
            }
        }
    }
    
    if (bestCan == -1)
    {
        printf("-1\n");
        return 0;
    }
    
    printf("%d\n", bestCan);
    printf("%d\n", (int)best.size());
    for (int x: best)
        printf("%d ", x + 1);
    printf("\n");
    
    return 0;
}