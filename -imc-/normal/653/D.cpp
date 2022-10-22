#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxN = 505;

struct edge
{
	int to;
	int c, f;
};

int n;
vector<int> adj[maxN];
vector<edge> edges;
vector<int> level;

int source, sink;

void bfs()
{
	deque<int> bfsQueue;
	bfsQueue.push_back(source);
	level.assign(n, -1);
	level[source] = 0;
	
	while (!bfsQueue.empty())
	{
		int v = bfsQueue.front();
		bfsQueue.pop_front();
		
		for (int idx: adj[v])
		{
			edge& e = edges[idx];
			if (e.c - e.f <= 0) continue;
			if (level[e.to] == -1)
			{
				level[e.to] = level[v] + 1;
				bfsQueue.push_back(e.to);
			}
		}
	}
}

vector<int> edgePos;

int dfs(int v, int flowLimit)
{
	if (v == sink) return flowLimit;
	if (flowLimit == 0) return 0;
	
	for (; edgePos[v] < (int)adj[v].size(); edgePos[v]++)
	{
		int idx = adj[v][edgePos[v]];
		edge& e = edges[idx];
		
		if (e.c - e.f <= 0) continue;
		if (level[e.to] != level[v] + 1) continue;
		
		int can = dfs(e.to, min(flowLimit, e.c - e.f));
		if (can > 0)
		{
			edges[idx].f += can;
			edges[idx ^ 1].f -= can;
			return can;
		}
	}
	
	return 0;
}

ll findFlowDinits()
{
	ll answer = 0;
	while (true)
	{
		bfs();
		ll totalAdd = 0;
		edgePos.assign(n, 0);
		while (true)
		{
			int add = dfs(source, (int)1e9);
			if (add == 0) break;
			answer += add;
			totalAdd += add;
		}
		
		if (totalAdd == 0) break;
	}
	
	return answer;
}

typedef long double ftype;

vector<tuple<int, int, int>> origEdges;

ll getIf(ftype w)
{
    source = 0;
	sink = n - 1;
    
    edges.clear();
    for (int i = 0; i < n; i++)
        adj[i].clear();
	
    for (auto e: origEdges)
	{
        int u = get<0>(e), v = get<1>(e);
        //printf("%d %d %d\n", u, v, get<2>(e));
        ftype f = get<2>(e) / w;
        if (f > 1e5 + 500)
            f = 1e5 + 500;
        int c = f;
		
		adj[u].push_back(edges.size());
		edges.push_back(edge { v, c, 0 });
		adj[v].push_back(edges.size());
		edges.push_back(edge { u, 0, 0 });
        
        //printf("edge %d -> %d %d (%Lf)\n", u, v, c, f);
	}
	
	ll flow = findFlowDinits();
    //printf("weight %Lf -> %lld\n", w, flow);
    return flow;
}

int main()
{
    int m, x;
    scanf("%d %d %d", &n, &m, &x);
    
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        u--; v--;
        
        origEdges.emplace_back(u, v, c);
    }
    
    ftype low = 1e-16, high = 1e10;
    for (int t = 0; t < 300; t++)
    {
        ftype m = (low + high) / 2;
        
        if (getIf(m) >= x)
            low = m;
        else
            high = m;
    }
    
    ftype answer = (low + high) / 2 * x;
    cout << fixed << setprecision(20) << answer << endl;
    
    return 0;
}