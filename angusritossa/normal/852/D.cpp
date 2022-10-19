/*
We binary search for the answer

f(T) is true if answer <= T
To check this, we make a flow graph similar to the last problem
We have edges from the super-source to all nodes with capacity = number of people who start at that node
We have edges from all nodes to the super-sink with capacity 1
We have "middle" edges between all pairs of nodes that are within distance T of each other (capacity 1)
we just check if maxflow >= k

TO find shortest paths, we use floyd-warshall (N^3 all pairs shortest path)
*/
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 610
#define MAXE 610*610*2
int adj[MAXN][MAXN], v, edges, n, k;
int s[MAXE], e[MAXE], capacity[MAXE], firstEdge[2*MAXN], numEdges, nx[MAXE], starting[MAXN];
void addEdge(int x, int y, int c) {
    s[numEdges] = x;
    e[numEdges] = y;
    capacity[numEdges] = c;
    numEdges++;
    s[numEdges] = y;
    e[numEdges] = x;
    capacity[numEdges] = 0;
    numEdges++;
}
int dis[2*MAXN];
void bfs(int source) {
    fill_n(dis, 2*MAXN, 1e9);
    dis[source] = 0;
    queue<int> q;
    q.push(source);
    while (q.size()) {
        int i = q.front();
        q.pop();
        int j = firstEdge[i];
        while (j != -1) {
            int endOfEdge = e[j];
            if (dis[endOfEdge] == 1e9 && capacity[j] > 0) {
                dis[endOfEdge] = dis[i]+1;
                q.push(endOfEdge);
            }
            j = nx[j];
        }
    }
}
int seen[2*MAXN], upto, dinitzFirstEdge[2*MAXN];
int aug(int i, int target, int weight) {
   // fprintf(stderr, "at %d, target %d, weight %d\n", i, target, weight);
    if (i == target) {
        return weight;
    }
    if (seen[i] == upto) {
        return 0;
    }
    seen[i] = upto; // mark node as seen
    int j = dinitzFirstEdge[i];
    while (j != -1) {
        int newWeight = min(weight, capacity[j]);
        // ignore all edges not on the bfs tree
       // printf("adj edge %d %d\n", s[j], e[j]);
        if (dis[s[j]] != dis[e[j]]+1 && capacity[j] > 0) {
            int res = aug(e[j], target, newWeight);
            if (res > 0) {
                // augment
                capacity[j] -= res;
                capacity[j^1] += res;
                return res;
            }
        }
        j = nx[j];
        dinitzFirstEdge[i] = j;
    }
    return 0;
}
int maxFlow(int source, int sink) {
    int flow = 0;
    while (1) {
        bfs(source);
        
        if (dis[sink] == 1e9) break;
       /// fprintf(stderr, "bfs dis from source to sink %d\n", dis[sink]);
        for (int i = 0; i < 2*MAXN; i++) dinitzFirstEdge[i] = firstEdge[i];
        while (1) {
            upto++; // reset seen array
            int res = aug(source, sink, 1e9);
         //   printf("res %d\n", res);
            if (!res) break;
            flow += res;
        }
    }
    return flow;
}
int f(int T) {
    // returns true if its possible in distance T
    // First: construct max flow graph
    numEdges = 0;
    for (int i = 1; i <= v; i++) {
        addEdge(0, 2*i, starting[i]);
        addEdge(2*i+1, 1, 1);
    }
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (adj[i][j] <= T) {
                addEdge(2*i, 2*j+1, 1);
            }
        }
    }
    // make the edge data structure linked-list
    fill_n(firstEdge, 2*MAXN, -1);
    for (int i = numEdges-1; i >= 0; i--) {
        nx[i] = firstEdge[s[i]];
        firstEdge[s[i]] = i;
    }
    // Second: check if max flow >= k (can we finish in at least k different cities)
    return maxFlow(0, 1) >= k;
}
int main() {
    scanf("%d%d%d%d", &v, &edges, &n, &k);
    for (int i = 1; i <= v; i++) {
        fill_n(adj[i], v+2, 1e9);
        adj[i][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        starting[a]++;
    }
    for (int i = 0; i < edges; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a][b] = min(adj[a][b], c);
        adj[b][a] = min(adj[b][a], c);
    }
    // floyd warshall
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    int s = 0;
    int e = 1731311+1; // inclusive range [s, e]
    while (s != e) {
        int mid = (s+e)/2;
        if (f(mid)) {
            e = mid;
        } else {
            s = mid+1;
        }
    }
    if (s == 1731311+1) printf("-1\n");
    else {
        printf("%d\n", s);
    }
}