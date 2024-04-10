#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>

using namespace std;

typedef long long ll;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2000 + 7;

string s[N];
int dp[N][N];
bool vis[N][N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 1e9;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] += (s[i][j] != 'a');
            if (i + 1 < n)
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            }
            if (j + 1 < n)
            {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            }
        }
    }
    vector <pair <int, int> > cells;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] <= k)
            {
                if (i + j + 1 == ans)
                {
                    cells.push_back({i, j});
                }
                else if (i + j + 1 > ans)
                {
                    cells.clear();
                    ans = i + j + 1;
                    cells.push_back({i, j});
                }
            }
        }
    }
    for (int x = 0; x < ans; x++) cout << 'a';
    vector <pair <int, int> > go;
    if (ans == 0) go.push_back({0, 0});
    for (auto c : cells)
    {
        if (c.first + 1 < n) go.push_back({c.first + 1, c.second});
        if (c.second + 1 < n) go.push_back({c.first, c.second + 1});
    }
    sort(go.begin(), go.end());
    go.resize(unique(go.begin(), go.end()) - go.begin());
    int need = 2 * n - 1 - ans;
    while (need--)
    {
        int mn = 1e9;
        for (auto c : go)
        {
            mn = min(mn, s[c.first][c.second] - 'a');
        }
        cells.clear();
        cout << char(mn + 'a');
        for (auto c : go)
        {
            if (s[c.first][c.second] - 'a' == mn)
            {
                cells.push_back(c);
            }
        }
        go.clear();
        for (auto c : cells)
        {
            if (c.first + 1 < n && !vis[c.first + 1][c.second]) go.push_back({c.first + 1, c.second}), vis[c.first + 1][c.second] = 1;
            if (c.second + 1 < n && !vis[c.first][c.second + 1]) go.push_back({c.first, c.second + 1}), vis[c.first][c.second + 1] = 1;
        }
    }
    cout << '\n';
}