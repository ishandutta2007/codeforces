#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>

using namespace std;

const int NMAX = 1005;
int v[NMAX];

set <pair <int, int> > tried;
unordered_map <int, int> Map;

int dfs(int a, int b) {
    if (!Map.count(a + b) || !Map[a + b])
        return 2;
    else {
        -- Map[a + b];
        int aux = 1 + dfs(b, a + b);
        ++ Map[a + b];
        return aux;
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    Map.reserve(n);

    for (int i = 1; i <= n; ++ i) {
        cin >> v[i];
        ++ Map[v[i]];
    }

    int best = 2;
    int aux = 0;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            if (i != j) {
                if (!tried.count(make_pair(v[i], v[j]))) {
                    -- Map[v[i]];
                    -- Map[v[j]];

                    tried.insert(make_pair(v[i], v[j]));

                    aux = dfs(v[i], v[j]);
                    if (aux > best)
                        best = aux;

                    ++ Map[v[i]];
                    ++ Map[v[j]];
                }
            }

    cout << best << '\n';
    return 0;
}