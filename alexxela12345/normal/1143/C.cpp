//                              ___-------___
//                          _-~~             ~~-_
//                       _-~                    /~-_
//    /^\__/^\         /~  \                   /    \
//  /| O ||O |        /      \_______________/        \
// | |___||__|      /       /                \          \
// |          \    /      /                    \          \
// |   (_______) /______/                        \_________ \
// |         / /         \                      /            \
//  \         \^\\         \                  /               \     /
//    \         ||           \______________/      _-_       //\__//
//      \       ||------_-~~-_ ------------- \ --/~   ~\    || __/
//        ~-----||====/~     |==================|       |/~~~~~
//         (_(__/  ./     /                    \_\      \.
//                (_(___/                         \_____)_)
//
#include <bits/stdc++.h>
#define _ << " " <<

using namespace std;

vector<set<int>> children;
vector<int> parent;
vector<int> c1, c2, visited;
vector<int> good;

void dfs(int v) {
    visited[v] = 1;
    for (int u : children[v]) {
        if (!visited[u]) {
            dfs(u);
        }
        c2[v] += c1[u];
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    children.resize(n);
    parent.resize(n);
    c1.resize(n);
    c2.resize(n);
    good.resize(n);
    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;
        if (p != -1) {
            parent[i] = p - 1;
            children[p - 1].insert(i);
        } else {
            parent[i] = p;
        }
        c1[i] = c;
    }
    visited.resize(n);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (c2[i] == children[i].size() && c1[i] == 1) {
            cout << i + 1 << " ";
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << -1;
    }
    cout << endl;
    return 0;
}