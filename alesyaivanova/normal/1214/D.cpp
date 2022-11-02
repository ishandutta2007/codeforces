#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double

int n, m;

bool in_field(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int e = 0; e < m; e++)
        {
            if (s[e] == '.')
                a[i][e] = 1;
            else
                a[i][e] = 0;
        }
    }
    bool kek[n][m] = {};
    kek[n - 1][m - 1] = true;
    queue<pii> q;
    q.emplace(n - 1, m - 1);
    while (!q.empty())
    {
        int x = q.front().ff;
        int y = q.front().ss;
        q.pop();
        if (in_field(x - 1, y) && !kek[x - 1][y] && a[x - 1][y])
        {
            kek[x - 1][y] = true;
            q.emplace(x - 1, y);
        }
        if (in_field(x, y - 1) && !kek[x][y - 1] && a[x][y - 1])
        {
            kek[x][y - 1] = true;
            q.emplace(x, y - 1);
        }
    }
    if (!kek[0][0])
    {
        cout << 0;
        return 0;
    }
    int d[n][m];
    for (int i = 0; i < n; i++)
        for (int e = 0; e < m; e++)
            d[i][e]= -1;
    d[0][0] = 0;
    q.emplace(0, 0);
    while (!q.empty())
    {
        int x = q.front().ff;
        int y = q.front().ss;
        q.pop();
        if (in_field(x + 1, y) && d[x + 1][y] == -1 && kek[x + 1][y])
        {
            d[x + 1][y] = d[x][y] + 1;
            q.emplace(x + 1, y);
        }
        if (in_field(x, y + 1) && d[x][y + 1] == -1 && kek[x][y + 1])
        {
            d[x][y + 1] = d[x][y] + 1;
            q.emplace(x, y + 1);
        }
    }
    int cnt[n * m] = {};
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < m; e++)
        {
            if (d[i][e] != -1)
                cnt[d[i][e]]++;
        }
    }
    for (int i = 1; i < d[n - 1][m - 1]; i++)
    {
        if (cnt[i] == 1)
        {
            cout << 1;
            return 0;
        }
    }
    cout << 2;
}