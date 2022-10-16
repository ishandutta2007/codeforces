#include <iostream>
#include <algorithm>
#include <vector>

#define lint long long int
using namespace std;

const int NMAX = 200005;

int n, K;
int sz[NMAX];
vector <int> graph[NMAX];

lint ans;
void dfs(int node, int father) {
    for (auto it: graph[node])
        if (it != father) {
            dfs(it, node);
            sz[node] += sz[it];
        }

    ans += min(sz[node], K - sz[node]);
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n >> K;

    K *= 2;
    int k = K;
    int node;
    while (k --) {
        cin >> node;
        ++ sz[node];
    }

    int a, b;
    for (int i = 1; i < n; ++ i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    cout << ans << '\n';
    return 0;
}