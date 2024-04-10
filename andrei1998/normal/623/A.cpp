#include <bits/stdc++.h>

using namespace std;

int n, m;
int graph[505][505];
int grad[505];

bool ok;

char sir[505];
void dfs(int node) {
    for (int i = 1; i <= n; ++ i)
        if (!graph[node][i] && i != node) {
            if (!sir[i]) {
                sir[i] = 'a' + 'c' - sir[node];
                dfs(i);
            }
            else if (sir[node] + sir[i] != 'a' + 'c') {
                ok = false;
            }
        }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    ok = true;
    cin >> n >> m;

    for (int i = 1; i <= n; ++ i)
        grad[i] = n - 1;

    int a, b;
    while (m --) {
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;

        grad[a] --;
        grad[b] --;
    }

    for (int i = 1; i <= n; ++ i)
        if (!grad[i])
            sir[i] = 'b';

    for (int i = 1; i <= n; ++ i)
        if (grad[i] && !sir[i]) {
            sir[i] = 'a';
            dfs(i);
        }

    for (int i = 1; i <= n; ++ i)
        for (int j = i + 1; j <= n; ++ j)
            if (graph[i][j]) {
                if (sir[i] == 'a' && sir[j] == 'c')
                    ok = false;
                if (sir[j] == 'c' && sir[i] == 'a')
                    ok = false;
            }
    if (!ok)
        cout << "No\n";
    else {
        cout << "Yes\n";
        cout << (sir + 1) << '\n';
    }
    return 0;
}