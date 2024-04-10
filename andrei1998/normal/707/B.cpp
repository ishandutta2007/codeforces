#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector <pair <pair <int, int>, int> > edges;

const int NMAX = 1e6 + 16;

bool has_supply[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    int a, b, c;
    for (int i = 1; i <= m; ++ i) {
        cin >> a >> b >> c;
        edges.push_back(make_pair(make_pair(a, b), c));
    }

    int node;
    while (k --) {
        cin >> node;
        has_supply[node] = true;
    }

    const int INF = 1e9 + 105;
    int ans = INF;
    for (auto it: edges) {
        int a = it.first.first;
        int b = it.first.second;
        int l = it.second;

        if (!has_supply[a] && !has_supply[b])
            continue;
        if (has_supply[a] && has_supply[b])
            continue;

        if (l < ans)
            ans = l;
    }

    if (ans == INF)
        cout << "-1\n";
    else
        cout << ans << '\n';
    return 0;
}