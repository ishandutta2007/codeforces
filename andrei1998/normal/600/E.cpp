#include <iostream>
#include <vector>

#define lint long long int
using namespace std;

const int NMAX = 100000 + 5;

int n;
int color[NMAX];
vector <int> graph[NMAX];

int frecv[NMAX];
int best;
lint bestSum;
lint ans[NMAX];

void insert(int val) {
    ++ frecv[val];
    if (frecv[val] > best) {
        best = frecv[val];
        bestSum = val;
    }
    else if (frecv[val] == best)
        bestSum += val;
}

int sz[NMAX];
void dfsSz(int node, int father) {
    sz[node] = 1;
    for (auto it: graph[node])
        if (it != father) {
            dfsSz(it, node);
            sz[node] += sz[it];
        }
}

void addDfs(int node, int father) {
    insert(color[node]);
    for (auto it: graph[node])
        if (it != father)
            addDfs(it, node);
}

void removeDfs(int node, int father) {
    frecv[color[node]] = 0;
    for (auto it: graph[node])
        if (it != father)
            removeDfs(it, node);
}

void dfs(int node, int father, bool keep) {
    int mx = -1, maxSon = -1;
    for (auto it: graph[node])
        if (it != father && sz[it] > mx) {
            mx = sz[it];
            maxSon = it;
        }

    for (auto it: graph[node])
        if (it != father && it != maxSon)
            dfs(it, node, false);


    if (maxSon != -1)
        dfs(maxSon, node, true);

    for (auto it: graph[node])
        if (it != father && it != maxSon)
            addDfs(it, node);

    insert(color[node]);
    ans[node] = bestSum;

    if (!keep) {
        best = bestSum = 0;
        removeDfs(node, father);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> color[i];

    for (int i = 1; i < n; ++ i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfsSz(1, 0);
    dfs(1, 0, 0);

    for (int i = 1; i <= n; ++ i)
        cout << ans[i] << '\n';
    return 0;
}