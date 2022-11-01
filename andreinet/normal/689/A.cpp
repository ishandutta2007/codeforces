#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<int, int>> coord = {
        {3, 1},
        {0, 0},
        {0, 1},
        {0, 2},
        {1, 0},
        {1, 1},
        {1, 2},
        {2, 0},
        {2, 1},
        {2, 2}
    };

    int xmin = 10, xmax = -10;
    int ymin = 10, ymax = -10;
   
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> mat(10, vector<int>(10, -1));
    for (const auto& p: coord) {
        mat[p.first + 1][p.second + 1] = 0;
    }
    for (char c: s) {
        int x = c - '0';
        mat[coord[x].first + 1][coord[x].second + 1] = 1;
    }
    int dx[] = {0, -1, 0, 1};
    int dy[] = {1, 0, -1, 0};
    bool ans = true;
    for (int k = 0; k < 4; ++k) {
        bool ok = true;
        for (char c: s) {
            int x = c - '0';
            ok &= mat[coord[x].first + 1 + dx[k]][coord[x].second + 1 + dy[k]] != -1;
        }
        ans &= !ok;
    }

    cout << (ans ? "YES\n": "NO\n");
}