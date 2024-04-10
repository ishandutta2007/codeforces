#include <bits/stdc++.h>
 
using namespace std;

#define int int64_t

int gg(int x, int n, int r) {
    return max(min(n, x + r) - max(x, r - 1), (int)0);
}

int cnt(int x, int y, int n, int m, int r) {
    return gg(x, n, r) * gg(y, m, r);
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, r, k;
    cin >> n >> m >> r >> k;
    int ix = n / 2, iy = m / 2;
    vector<pair<int, int>> ans;
    set<tuple<int, int, int>, greater<tuple<int, int, int>>> que = {{cnt(ix, iy, n, m, r), ix, iy}};
    map<int, map<int, int>> used;
    used[ix][iy] = true;
    while(!que.empty() && k) {
        auto it = *que.begin();
        que.erase(it);
        int x = get<1>(it), y = get<2>(it);
        k--;
        ans.push_back({x, y});
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(0 <= x && x < n && 0 <= y && y < m) {
                if(!used[nx][ny]) {
                    used[nx][ny] = 1;
                    que.insert({cnt(nx, ny, n, m, r), nx, ny});
                }
            }
        }
    }
    int sum = 0;
    for(auto it: ans) {
        sum += cnt(it.first, it.second, n, m, r);
    }
    cout << fixed << setprecision(12);
    cout << 1. * sum / (n - r + 1) / (m - r + 1) << endl;
    return 0;
}