#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    
    int si, sj, fi, fj;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 'S') {
                si = i;
                sj = j;
                g[i][j] = '.';
            }
            else if (g[i][j] == 'E') {
                fi = i;
                fj = j;
                g[i][j] = '.';
            }
            
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    sort(all(dirs));
    
    string cmds = "";
    cin >> cmds;
    
    auto model = [&]() {
        int i = si, j = sj;
        
        for (char c: cmds) {
            int idx = c - '0';
            i += dirs[idx].first;
            j += dirs[idx].second;
            if (i < 0 || j < 0 || i >= n || j >= m) return false;
            if (g[i][j] == '#') return false;
            if (i == fi && j == fj) return true;
        }
        return false;
    };
    
    int answer = 0;
    do {
        if (model())
            answer++;
    }
    while (next_permutation(all(dirs)));
    
    cout << answer << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //solve(false);
    
    return 0;
}