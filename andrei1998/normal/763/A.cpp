#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int NMAX = 100000 + 5;

int N;
int c[NMAX];
int deg[NMAX];
vector <int> graph[NMAX];

bool erased[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    if (N == 1) {
        cout << "YES\n";
        cout << "1\n";
        return 0;
    }

    for (int i = 1; i < N; ++ i) {
        int a, b;
        cin >> a >> b;

        deg[a] ++;
        deg[b] ++;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; ++ i)
        cin >> c[i];

    queue <int> q;
    for (int i = 1; i <= N; ++ i)
        if (deg[i] == 1)
            q.push(i);

    int nodes = N;
    while (!q.empty()) {
        int node = q.front();
        if (nodes == 1)
            break;

        q.pop();

        int vec;
        for (auto it: graph[node])
            if (!erased[it]) {
                vec = it;
                break;
            }

        if (c[node] == c[vec]) {
            erased[node] = true;
            -- deg[vec];
            -- nodes;

            if (deg[vec] == 1)
                q.push(vec);
        }
    }

    int cnt = 0;
    int node = 0;
    for (int i = 1; i <= N; ++ i)
        if (!erased[i] && deg[i] > 1) {
            ++ cnt;
            node = i;
        }

    if (cnt > 1) {
        cout << "NO\n";
        return 0;
    }

    if (cnt == 1) {
        cout << "YES\n";
        cout << node << '\n';
        return 0;
    }

    for (int i = 1; i <= N; ++ i)
        if (!erased[i])
            node = i;

    cout << "YES\n";
    cout << node << '\n';
    return 0;
}