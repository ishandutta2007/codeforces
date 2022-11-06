#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 509;
set<int> adj[(int) MxN + 9];
char str[(int) MxN + 9];

void dfs(const int u, const char ch) {
    str[u] = ch;
    for (int v : adj[u])
        if (!str[v])
            dfs(v, ch);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int i = 1; i <= n; ++i)
        if (adj[i].size() == n - 1)
            str[i] = 'b';

    for (int i = 1; i <= n; ++i)
        if (str[i] == 'b') {
            for (int x : adj[i])
                adj[x].erase(i);
            adj[i].clear();
        }


    auto no = []() {
        cout << "No";
        return 0;
    };

    {
        char ch = 'a';
        for (int i = 1; i <= n; ++i)
            if (!str[i]) {
                if (ch > 'c')
                    return no();
                dfs(i, ch);
                ch += 2;
            }
    }

    auto C2 = [](int x){
        return x*(x-1)/2;
    };

    const int cntA = count(str, str + n + 1, 'a');
    const int cntB = count(str, str + n + 1, 'b');
    const int cntC = count(str, str + n + 1, 'c');

    if(m != C2(cntA) + C2(cntB) + C2(cntC) + cntB * (cntA + cntC))
        return no();

    cout << "Yes\n" << str + 1;

    return 0;
}