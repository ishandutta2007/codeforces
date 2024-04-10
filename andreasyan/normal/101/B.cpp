#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 1000000007;
struct ban
{
    int l, r;
};
bool operator<(const ban& a, const ban& b)
{
    return a.r < b.r;
}

int n, m;
ban a[N];

map<int, int> t;
void ubd(int i, int x)
{
    ++i;
    while (i < M)
    {
        t[i] = (t[i] + x) % M;
        i += (i & (-i));
    }
}

int qry(int l, int r)
{
    ++l;
    ++r;
    int ans = 0;
    int i = r;
    while (i > 0)
    {
        if (t.find(i) != t.end())
            ans = (ans + t[i]) % M;
        i -= (i & (-i));
    }
    i = l - 1;
    while (i > 0)
    {
        if (t.find(i) != t.end())
            ans = (ans - t[i] + M) % M;
        i -= (i & (-i));
    }
    return ans;
}

int dp[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> a[i].l >> a[i].r;
    sort(a + 1, a + m + 1);
    ubd(0, 1);
    for (int i = 1; i <= m; ++i)
    {
        dp[i] = qry(a[i].l, a[i].r - 1);
        ubd(a[i].r, dp[i]);
    }
    cout << qry(n, n) << endl;
    return 0;
}