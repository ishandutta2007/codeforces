#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int NMAX = (1 << 10);

int d, n;
char s[11];
int cnt[NMAX];

vector <int> a;
vector <int> sol;

struct Edge
{
    int x;
	int y;
	int cap;
	int cost;
};

struct Network
{
    vector <Edge> edges;
    vector <vector <int> > adj;

    vector <int> dist;

    int n, S, D;

	Network(int n, int S, int D) : n(n), S(S), D(D), adj(n + 1), dist(n + 1, INF) {}

	void add_edge(int x, int y, int c, int z)
    {
        adj[x].emplace_back(edges.size());
        edges.emplace_back(Edge{x, y, c, z});

        adj[y].emplace_back(edges.size());
        edges.emplace_back(Edge{y, x, 0, -z});
    }

    void bellman_ford()
    {
        vector <bool> inQ(n + 1, false);
        queue <int> q;

        q.push(S);
        inQ[S] = true;

        dist[S] = 0;

        while(!q.empty())
		{
            int nod = q.front();
            q.pop();

            inQ[nod] = false;

            for(auto i : adj[nod])
			{
                if(edges[i].cap && dist[edges[i].y] > dist[nod] + edges[i].cost)
				{
                    dist[edges[i].y] = dist[nod] + edges[i].cost;

                    if(!inQ[edges[i].y])
					{
                        inQ[edges[i].y] = true;
                        q.push(edges[i].y);
                    }
                }
            }
        }
    }

    bool dijkstra(vector <int>& dad)
    {
        dad = vector <int> (n + 1, -1);
        vector <int> cost(n + 1, INF);

        priority_queue <pair <int, int> > pq;

        cost[S] = 0;

        pq.push({0, S});

        while(!pq.empty())
		{
            int nod = pq.top().second;
			int val = pq.top().first;

			pq.pop();

            if(val != -cost[nod])
			{
                continue;
            }

            for(auto i : adj[nod])
			{
                if(edges[i].cap && cost[edges[i].y] > cost[nod] + dist[nod] - dist[edges[i].y] + edges[i].cost)
				{
                    cost[edges[i].y] = cost[nod] + dist[nod] - dist[edges[i].y] + edges[i].cost;

                    pq.push({-cost[edges[i].y], edges[i].y});
                    dad[edges[i].y] = i;
                }
            }
        }

        for(int i = 1; i <= n; i++)
		{
            dist[i] += cost[i];
		}

        return (dad[D] != -1);
    }

	int get_cost()
    {
        bellman_ford();

        int cost = 0;

        vector <int> dad;

        while(dijkstra(dad))
		{
            int cat = INF;

			vector <int> aux;
            for(int i = dad[D]; i != -1; i = dad[edges[i].x]) {
                cat = min(cat, edges[i].cap);
			}

            for (int i = dad[D]; i != -1; i = dad[edges[i].x])
			{
                cost += cat * edges[i].cost;
                edges[i].cap -= cat;
                edges[i ^ 1].cap += cat;
            }
        }

        return cost;
    }

    void afis(int m) {
        for (int bit = 0; bit < d ; ++bit)
            if (((1 << bit) & m)) printf("%d ", bit);
    }

    void dfs(int nod, int N, int mask = 0) {
        if (nod == S) {
            bool bef = false;
            while (!adj[nod].empty()) {
                auto i = adj[nod].back();
                auto it = edges[i];
                adj[nod].pop_back();
                if (i % 2) continue ;
                if (it.cap == 1) continue ;

                if (it.y > N) {
                    if (bef) printf("R ");
                    bef = true;
                    afis(mask ^ a[it.y - N - 1]);
                    dfs(it.y - N, N, a[it.y - N - 1]);
                }
            }
        } else {
            while (!adj[nod].empty()) {
                auto i = adj[nod].back();
                auto it = edges[i];
                adj[nod].pop_back();
                if (i % 2) continue ;
                if (it.cap == 1) continue ;

                afis(mask ^ a[it.y - N - 1]);
                dfs(it.y - N, N, a[it.y - N - 1]);
                break ;
            }
        }
    }

    void reconst() {
        int N = (::n);
        dfs(0, N);
    }
};

int main() {
//    freopen("1.in", "r", stdin);

	scanf("%d%d", &d, &n);
	Network graf(2 * n + 2, 0, 2 * n + 1);
	for (int i = 1; i <= n ; ++i) {
		scanf("%s", s);
		int x = 0, nr = 0;
		for (int bit = 0; bit < d ; ++bit)
			if (s[bit] == '1') ++nr, x = x | (1 << bit);
		cnt[x] = nr;
		a.push_back(x);
	}

	for (int i = 0; i < (int)a.size() ; ++i) {
		graf.add_edge(0, i + 1, 1, 0);
		graf.add_edge(0, n + i + 1, 1, 1 + cnt[a[i]]);
		graf.add_edge(n + i + 1, 2 * n + 1, 1, 0);

		for (int j = 0; j < (int)a.size() ; ++j) {
			if (a[i] != a[j] && (a[i] & a[j]) == a[i])
				graf.add_edge(i + 1, n + j + 1, 1, cnt[a[j]] - cnt[a[i]]);
		}
	}

	printf("%d\n", graf.get_cost() - 1);
    graf.reconst();

	return 0;
}