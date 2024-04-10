#include <iostream>

using namespace std;

int vis[105];

int main()
{
    int n, m;
    cin >> m >> n;

    for (int i = 1; i <= m; ++ i) {
        int sz = 0;
        cin >> sz;

        while (sz --) {
            int aux = 0;
            cin >> aux;

            vis[aux] = 1;
        }
    }

    int i;
    for (i = 1; i <= n; ++ i)
        if (!vis[i])
            break;

    if (i == n + 1)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}