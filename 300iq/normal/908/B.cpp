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
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

char c[50][50];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int sx = 0, sy = 0;
    int tx = 0, ty = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == 'S') sx = i, sy = j;
            if (c[i][j] == 'E') tx = i, ty = j;
        }
    }
    string s;
    cin >> s;
    for (auto &x : s) x -= '0';
    vector <int> a(4);
    for (int i = 0; i < 4; i++)
    {
        a[i] = i;
    }
    int ans = 0;
    do
    {
        int x = sx, y = sy;
        bool bad = false;
        bool good = false;
        for (auto &t : s)
        {
            x += dx[a[t]];
            y += dy[a[t]];
            if (x < 0 || y < 0 || x >= n || y >= m || c[x][y] == '#') 
            {
                bad = true;
                break;
            }
            if (x == tx && y == ty)
            {
                good = true;
                break;
            }
        }
        if (good)
        {
            ans++;
        }
    }
    while (next_permutation(a.begin(), a.end()));
    cout << ans << '\n';
}