#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    edge* p = nullptr;
    int x, used = 0;

    edge(int x) : x(x) {}
};

vector <vector <edge*>> g;
vector <int> st;
vector <bool> used;

void dfs(int v) {
    st.push_back(v);
    if (used[v]) return;
    used[v] = true;
    for (auto i : g[v]) {
        if (i->used) continue;
        i->used = 1;
        i->p->used = 1;
        dfs(i->x);
        st.push_back(v);
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    g.resize(2 * n);
    used.resize(2 * n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        edge* tmp1 = new edge(y);
        edge* tmp2 = new edge(x);
        tmp1->p = tmp2;
        tmp2->p = tmp1;
        g[x].push_back(tmp1);
        g[y].push_back(tmp2);
    }
    vector <vector <int>> grid(2);
    vector <vector <char>> ans1(2), ans2(2);
    for (int i = 0; i < 2 * n; ++i) {
        st.clear();
        if (!used[i]) {
            dfs(i);
            if ((int)st.size() == 1) continue;
            if ((int)st.size() == 3) {
                cout << -1;
                return 0;
            }
            int l = (int)st.size() - 1;
            for (int j = 0; j < l / 2; ++j) {
                grid[0].push_back(st[j] + 1);
            }
            for (int j = l - 1; (int)grid[0].size() != (int)grid[1].size(); --j) {
                grid[1].push_back(st[j] + 1);
            }
            if (l % 4 == 0) {
                for (int j = 0; j < l; j += 4) {
                    ans1[0].push_back('L');
                    ans1[0].push_back('R');
                    ans1[1].push_back('L');
                    ans1[1].push_back('R');
                }
                ans2[0].push_back('U');
                ans2[1].push_back('D');
                for (int j = 4; j < l; j += 4) {
                    ans2[0].push_back('L');
                    ans2[0].push_back('R');
                    ans2[1].push_back('L');
                    ans2[1].push_back('R');
                }
                ans2[0].push_back('U');
                ans2[1].push_back('D');
            } else {
                ans1[0].push_back('U');
                ans1[1].push_back('D');
                for (int j = 2; j < l; j += 4) {
                    ans1[0].push_back('L');
                    ans1[0].push_back('R');
                    ans1[1].push_back('L');
                    ans1[1].push_back('R');
                }
                for (int j = 2; j < l; j += 4) {
                    ans2[0].push_back('L');
                    ans2[0].push_back('R');
                    ans2[1].push_back('L');
                    ans2[1].push_back('R');
                }
                ans2[0].push_back('U');
                ans2[1].push_back('D');
            }
        }
    }
    cout << 2 << " " << (int)ans1[0].size() << "\n";
    for (int i = 0; i < 2; ++i) {
        for (int j : grid[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < 2; ++i) {
        for (char j : ans1[i]) {
            cout << j;
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < 2; ++i) {
        for (char j : ans2[i]) {
            cout << j;
        }
        cout << "\n";
    }
}