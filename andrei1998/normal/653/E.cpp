#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>

#define lint long long int
using namespace std;

const int NMAX = 300005;

unordered_set <lint> edges;

int comp[NMAX];

int sz;
int neviz[NMAX];

queue <int> coada;

void bfs(int node, int culoare) {
    coada.push(node);

    while (!coada.empty()) {
        node = coada.front();
        coada.pop();

        comp[node] = culoare;

        for (int i = 1; i <= sz; ++ i)
            if (!edges.count(1000000LL * node + neviz[i])) {
                coada.push(neviz[i]);
                swap(neviz[i --], neviz[sz --]);
            }
    }

}

bool vis[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    int a, b;
    while (m --) {
        cin >> a >> b;

        edges.insert(1000000LL * a + b);
        edges.insert(1000000LL * b + a);
    }

    for (int i = 2; i <= n; ++ i)
        neviz[++ sz] = i;

    int culori = 0;
    int node;
    while (sz) {
        node = neviz[1];
        swap(neviz[1], neviz[sz --]);

        bfs(node, ++ culori);
    }

    int _count = 0;
    int muchii = 0;
    for (int i = 2; i <= n; ++ i)
        if (!edges.count(1000000LL + i)) {
            ++ muchii;
            if (!vis[comp[i]]) {
                _count ++;
                vis[comp[i]] = true;
            }
        }

    if (_count != culori) {
        cout << "impossible\n";
        return 0;
    }

    if (_count <= k && muchii >= k)
        cout << "possible\n";
    else
        cout << "impossible\n";

    return 0;
}