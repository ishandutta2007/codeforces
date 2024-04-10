#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;

vector<string> s;
vector<vector<int>> vis;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, m;

bool inBoard(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
        if (inBoard(x + dx[i], y + dy[i]) && s[x + dx[i]][y + dy[i]] == '#' &&
                                                vis[x + dx[i]][y + dy[i]] == 0)
            dfs(x + dx[i], y + dy[i]);
}

int main() {
    cin >> n >> m;
    s.resize(n);
    vis.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        vis[i].resize(m);
    }
    int ans = 2;
    int t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '#')
                continue;
            t++;
            s[i][j] = '.';
            int k = 0;
            for (int x = 0; x < n; x++)
                for (int y = 0; y < m; y++)
                    vis[x][y] = 0;
            for (int x = 0; x < n; x++)
                for (int y = 0; y < m; y++)
                    if (s[x][y] == '#' && vis[x][y] == 0) {
                        k++;
                        dfs(x, y);
                    }
            if (k >= 2)
                ans = 1;
            s[i][j] = '#';
        }
    }
    if (t < 3)
        cout << -1;
    else
        cout << ans;
    return 0;
}