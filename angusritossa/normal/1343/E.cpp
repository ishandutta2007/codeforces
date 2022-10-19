/*
Initially, we do 3 BFS's starting at a, b and c
We also sort the list of edge weights, and make a prefix sum

Then, for all possible values of D:
- Let X = distance from B to D
- Let Y = distance from A to D
- Let Z = distance from C to D
- Let pathDistance = 2*(smallest X edges) + (next smallest Y+Z) edges
Take the smallest pathDistance across all values of D
*/
#include <cstdio> // scanf/prints
#include <algorithm> // sort, min
#include <vector> // adjacency lists
#include <queue> // queue, used in the bfs
typedef long long ll;
using namespace std;
#define MAXN 200010
vector<int> adj[MAXN];
int n, m, a, b, c, weights[MAXN], disA[MAXN], disB[MAXN], disC[MAXN];
ll pre[MAXN];
void bfs(int s, int* dis) {
    /* 
    Takes in a starting node, and an array dis
    dis[i] will store the shortest path from s to i (unweighted graph)
    */
    fill_n(dis, n+1, 1e9); // initially, distance from s to all nodes is "infinity"
    dis[s] = 0; // distance from s to s is 0
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (int j : adj[i]) {
            if (dis[j] == 1e9) {
                dis[j] = dis[i]+1;
                q.push(j);
            }
        }
    }
}
ll findPrefixSum(int x, int y) {
    ll sum = 0;
    if (y >= 0) sum += pre[y];
    if (x != 0) sum -= pre[x-1];
    // sum of the first y elements minus sum of the first x-1 elements = sum of the xth through yth (inclusive) elements
    return sum;
}
int main() {
    int t;
    scanf("%d", &t);
    for (int CASE = 0; CASE < t; CASE++) {
        scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 0; i < m; i++) scanf("%d", &weights[i]);
        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bfs(a, disA);
        /*for (int i = 1; i <= n; i++) {
            fprintf(stderr, "dis from %d to %d is %d\n", a, i, disA[i]);
        }*/
        bfs(b, disB);
        bfs(c, disC);
        // sort weights, make prefix sum
        sort(weights, weights+m); // sort the first m elements of the array weights
        // make a prefix sum
        // pre[i] is the sum of the first i elements
        // pre[i] = weights[i] + pre[i-1]
        pre[0] = weights[0];
        for (int i = 1; i < m; i++) {
            pre[i] = (ll)weights[i] + pre[i-1];
        }
        /*
        Then, for all possible values of D:
        - Let X = distance from B to D
        - Let Y = distance from A to D
        - Let Z = distance from C to D
        - Let pathDistance = 2*(smallest X edges) + (next smallest Y+Z) edges
        Take the smallest pathDistance across all values of D
        */
        ll ans = 1e18; // answer = infinity
        for (int d = 1; d <= n; d++) {
            int x = disB[d];
            int y = disA[d];
            int z = disC[d];
            if (x+y+z > m) {
                continue;
            }
           // fprintf(stderr, "d is %d - x %d y %d z %d\n", d, x, y, z);
            ll pathDis = 2*findPrefixSum(0, x-1);
            pathDis += findPrefixSum(x, x+y+z-1);
            //fprintf(stderr, "pathdis %lld\n", pathDis);
            ans = min(ans, pathDis);
        }
        printf("%lld\n", ans);
        //fprintf(stderr, "END OF CASE\n\n");
    }
}