#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1E6 + 15;

vector <int> graph[NMAX];
int ansRoot;
int minIndex[NMAX];

void dfs(int node, int father) {
    for (auto it: graph[node])
        if (it != father) {
            minIndex[it] = min(minIndex[node], it);
            dfs(it, node);
        }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i < N; ++ i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int t, z;
    cin >> t >> z;
    int root = z % N + 1;

    ansRoot = root;
    minIndex[root] = root;
    dfs(root, 0);
    int last = 0;

    while (-- Q) {
        cin >> t >> z;
        z = (z + last) % N + 1;

        if (t == 2) {
            last = min(ansRoot, minIndex[z]);
            cout << last << '\n';
        }
        else
            ansRoot = min(ansRoot, minIndex[z]);
    }
    return 0;
}