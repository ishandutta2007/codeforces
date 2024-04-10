/*
 * Construct a flow graph, with 2n+2 vertices (source = 0, sink = 1). for vertex i, the first copy can be 2*i, 2*i+1
 * Edges from source to source vertices with capacity a[i]
 * Edges from sinks to the main sink with capacity b[i]
 * Edges between the sources and the sinks when there is an edge in the graph
 * Answer is yes if the total flow = sum of b[i]
 */

/*
 * edge list representation
 */

#include <cstdio>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;

const int V = 500;
const int E = 2000;
const int INF = 1000000;
// the index of the first outgoing edge for each vertex, initialised to -1
int start[V];
// if e is an outgoing edge from u, succ[e] is another one, or -1
// cap[e] is the capacity/weight of the e
// to[e] is the destination vertex of e
int succ[E], cap[E], to[E];

int edge_counter = 0;
void add_edge(int u, int v, int c) {
  // set the properties of the new edge
  cap[edge_counter] = c, to[edge_counter] = v;
  // insert this edge at the start of u's linked list of edges
  succ[edge_counter] = start[u];
  start[u] = edge_counter;
  ++edge_counter;
}


/*
 * dinitz 1
 */

// assumes the residual graph is constructed as in the previous section
// n = #nodes, s = source, t = sink
int n, s, t;
// stores dist from s.
int lvl[V];
// stores first non-useless child.
int nextchld[V];

// constructs the BFS tree.
// Returns if the sink is still reachable.
bool bfs() {
  for (int i = 0; i < n; i++) lvl[i] = -1;
  queue<int> q;
  q.push(s); lvl[s] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    nextchld[u] = start[u]; // reset nextchld
    for (int e = start[u]; ~e; e = succ[e]) {
      if (cap[e] > 0) {
        int nxt = to[e];
        if (lvl[nxt] != -1) continue; // already seen
        lvl[nxt] = lvl[u] + 1;
        q.push(nxt);
      }
    }
  }
  return lvl[t] != -1;
}

/*
 * dinitz 2
 */

// Finds an augmenting path with up to cflow flow.
int aug(int u, int cflow) {
  if (u == t) return cflow; // base case.
  // Note the reference here! We will keep decreasing nextchld[u]
  // Till we find a child that we can flow through.
  for (int &i = nextchld[u]; i >= 0; i = succ[i]) {
    if (cap[i] > 0) {
      int nxt = to[i];
      // Ignore edges not in the BFS tree.
      if (lvl[nxt] != lvl[u] + 1) continue;
      int rf = aug(nxt, min(cflow, cap[i]));
      // Found a child we can flow through!
      if (rf > 0) {
        cap[i] -= rf;
        cap[i^1] += rf;
        return rf;
      }
    }
  }
  lvl[u]=-1;
  return 0;
}

int mf() {
  int tot = 0;
  while (bfs())
    for (int x = aug(s,INF); x; x = aug(s,INF)) tot+=x;
  return tot;
}

int N, m, a[V], b[V];
int ansGrid[V][V];
int u[V], v[V];

int main() {
    fill(start, start + V, -1);

    scanf("%d%d", &N, &m);
    for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= N; i++) scanf("%d", &b[i]);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        u[i] = a;
        v[i] = b;
        add_edge(2*a, 2*b+1, 1000);
        add_edge(2*b+1, 2*a, 0);

        add_edge(2*b, 2*a+1, 1000);
        add_edge(2*a+1, 2*b, 0);
    }

    for (int i = 1; i <= N; i++) {
        add_edge(2*i, 2*i+1, 1000);
        add_edge(2*i+1, 2*i, 0);

        add_edge(0, 2*i, a[i]);
        add_edge(2*i, 0, 0);

        add_edge(2*i+1, 1, b[i]);
        add_edge(1, 2*i+1, 0);
    }

    s = 0;
    t = 1;
    n = 2*N+2;

    int flow = mf();

    if (flow == accumulate(b+1, b+n+1, 0) && flow == accumulate(a+1, a+n+1, 0)) {
        printf("YES\n");

        for (int i = 0; i < m; i++) {
            ansGrid[u[i]][v[i]] = cap[4*i+1];
            ansGrid[v[i]][u[i]] = cap[4*i+3];
        }
        for (int i = 1; i <= N; i++) {
            ansGrid[i][i] = cap[4*m+6*(i-1)+1];
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                printf("%d ", ansGrid[i][j]);
            }
            printf("\n");
        }

    } else {
        printf("NO\n");
    }
}