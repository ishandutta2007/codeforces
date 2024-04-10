#include <bits/stdc++.h>

using namespace std;

int n, y[2][7000], deg[2][7000];
vector<int> x[2];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int j = 0; j < 2; j++) {
        int sz; cin >> sz;
        x[j].resize(sz);
        for(int i = 0; i < sz; i++)
            cin >> x[j][i];
        for(int i = 0; i < n; i++) deg[j][i] = sz;
    }
    memset(y, -1, sizeof y);
    y[0][0] = y[1][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    q.push({1, 0});
    while(!q.empty()) {
        int a = q.front().first, b = q.front().second;
        q.pop();
        for(int k : x[!a]) {
            int bb = (b - k + n) % n;
            deg[!a][bb]--;
            if(y[!a][bb] != -1) continue;
            if(y[a][b] == 0) {
                y[!a][bb] = 1;
                q.push({!a, bb});
            } else if(deg[!a][bb] == 0) {
                y[!a][bb] = 0;
                q.push({!a, bb});
            }
        }
    }
    for(int i = 0; i < 2; i++, cout << '\n')
        for(int j = 1; j < n; j++)
            cout << (y[i][j] == 0 ? "Lose" : y[i][j] == 1 ? "Win" : "Loop") << ' ';
}