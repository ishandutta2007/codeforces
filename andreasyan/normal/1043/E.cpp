#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
struct ban
{
    int i;
    long long x, y;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x - a.y < b.x - b.y;
}

int n, m;
ban a[N], ca[N];
vector<int> g[N];

long long p[N], s[N];

long long ans[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].x >> a[i].y;
        a[i].i = i;
        ca[i] = a[i];
    }
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i].x;
    for (int i = n; i >= 1; --i)
        s[i] = s[i + 1] + a[i].y;
    for (int i = 1; i <= n; ++i)
    {
        int x = a[i].i;
        ans[x] = p[i - 1] + a[i].y * (i - 1) + s[i + 1] + (n - i) * a[i].x;
        for (int j = 0; j < g[x].size(); ++j)
        {
            int h = g[x][j];
            ans[x] -= (min(a[i].x + ca[h].y, a[i].y + ca[h].x));
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}