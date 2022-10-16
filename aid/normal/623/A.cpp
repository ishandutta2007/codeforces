#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int MAXN = 505;
char s[MAXN], gg[MAXN][MAXN];
vector<int> g[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
        gg[v][u] = true;
        gg[u][v] = true;
    }
    for(int i = 0; i < n; i++)
        s[i] = 'c';
    for(int i = 0; i < n; i++)
        if((int)g[i].size() == n - 1)
            s[i] = 'b';
    for(int i = 0; i < n; i++)
        if((int)g[i].size() != n - 1) {
            s[i] = 'a';
            for(size_t j = 0; j < g[i].size(); j++)
                if(s[g[i][j]] != 'b')
                    s[g[i][j]] = 'a';
            break;
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(j == i)
                continue;
            if(gg[i][j]) {
                if(abs((int)s[i] - (int)s[j]) > 1) {
                    cout << "No\n";
                    return 0;
                }
            }
            else {
                if(abs((int)s[i] - (int)s[j]) <= 1) {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    cout << "Yes\n";
    for(int i = 0; i < n; i++)
        cout << s[i];
    cout << '\n';
    return 0;
}