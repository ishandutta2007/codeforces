#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int NMAX = 150000 + 5;

vector <int> graph[NMAX];
pair <int, int> edges[NMAX];

int comp[NMAX];
long long int sz[NMAX];
void dfs(int node, int c) {
    comp[node] = c, ++ sz[c];
    for (auto it: graph[node])
        if (!comp[it])
            dfs(it, c);
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= M; ++ i) {
        int a, b;
        cin >> a >> b;
        edges[i] = make_pair(a, b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int c = 0;
    for (int i = 1; i <= N; ++ i)
        if (!comp[i]) {
            dfs(i, ++ c);
            sz[c] = sz[c] * (sz[c] - 1LL);
        }

    for (int i = 1; i <= M; ++ i) {
        sz[comp[edges[i].first]] --;
        sz[comp[edges[i].second]] --;
    }

    bool ok = true;
    for (int i = 1; i <= c; ++ i)
        if (sz[i]) {
            ok = false;
            break;
        }

    if (!ok)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}