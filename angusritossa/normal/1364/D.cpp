/*
 * Only keep the first k vertices. Then, run a dfs which does two things
 * 1) Looks for cycles
 * 2) Colours the graph
 * If we find a cycle, then we're finished (just print the cycle)
 * If we don't find a cycle, use the graph colouring to make an independent set
 */

#include <cstdio>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;
#define MAXN 100010
vector<int> adj[MAXN], odd, even;
stack<int> path;
int n, m, k, seen[MAXN];
void dfs(int a, int height, int par) {
    path.push(a);

    seen[a] = true;
    if (height % 2 == 0) even.push_back(a);
    else odd.push_back(a);

    for (int b : adj[a]) {
        if (!seen[b]) {
            dfs(b, height+1, a);
        } else if (b != par) {
            printf("2\n");
            vector<int> cycle;
            while (path.top() != b) {
                cycle.push_back(path.top());
                path.pop();
            }
            cycle.push_back(b);

            printf("%d\n", (int)cycle.size());
            for (int c : cycle) printf("%d ", c);
            printf("\n");

            exit(0); // end our program
        }
    }

    path.pop();
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > k || b > k) {
            continue;
        }
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= k; i++) {
        if (!seen[i]) {
            dfs(i, 0, -1);
        }
    }

    printf("1\n");
    if (even.size() > odd.size()) {
        for (int i = 0; i < (k+1)/2; i++) printf("%d ", even[i]);
    } else {
        for (int i = 0; i < (k+1)/2; i++) printf("%d ", odd[i]);
    }
    printf("\n");
}