#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <map>
#include <set>

using namespace std;
map <int, set <int>> all;
vector <map <int, bool>> ans;
vector <set <int>> flex;

void dfs(int v, int col) {
    ans[v][col] = true;
    all[col].erase(v);
    flex[v].erase(col);
    int next_v = *all[col].begin();
    all[col].erase(next_v);
    flex[next_v].erase(col);
    if (flex[next_v].empty()) return;
    int new_col = *flex[next_v].begin();
    dfs(next_v, new_col);
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int n;
    cin >> n;
    vector <vector <int>> a(n);
    vector <map <int, int>> d(n);
    flex.resize(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        a[i].resize(m);
        for (int& j : a[i]) {
            cin >> j;
            ++d[i][j];
        }
        for (auto& j : d[i]) {
            if (j.second & 1) {
                all[j.first].insert(i);
                flex[i].insert(j.first);
            }
        }
    }
    ans.resize(n);
    for (auto& i : all) {
        if ((int)i.second.size() % 2 == 1) {
            cout << "NO";
            return 0;
        }
    }
    for (auto& i : all) {
        while (!i.second.empty()) {
            dfs(*i.second.begin(), i.first);
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        map <int, int> now;
        for (int j : a[i]) {
            if (d[i][j] & 1) {
                if (now[j] * 2 < d[i][j] - 1) cout << "L";
                else if (now[j] * 2 == d[i][j] - 1 && ans[i][j]) cout << "L";
                else cout << "R";
            } else {
                if (now[j] * 2 < d[i][j]) cout << "L";
                else cout << "R";
            }
            ++now[j];
        }
        cout << "\n";
    }
}

/*

 */