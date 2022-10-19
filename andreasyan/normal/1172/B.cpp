#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long M = 998244353;
struct ban
{
    long long x;
    ban()
    {
        x = 0;
    }
    ban(long long x)
    {
        this->x = x % M;
    }
};
ban operator+(const ban& a, const ban& b)
{
    return ban(a.x + b.x);
}
ban operator-(const ban& a, const ban& b)
{
    return ban(a.x - b.x + M);
}
ban operator*(const ban& a, const ban& b)
{
    return ban(a.x * b.x);
}
ban ast(ban x, long long n)
{
    ban res = ban(1);
    while (n)
    {
        if ((n & 1))
            res = res * x;
        x = x * x;
        n /= 2;
    }
    return res;
}
ban operator/(const ban& a, const ban& b)
{
    return a * ast(b, M - 2);
}

int n;
vector<int> a[N];

ban f[N];
void pre()
{
    f[0] = ban(1);
    for (int i = 1; i <= n; ++i)
        f[i] = f[i - 1] * ban(i);
}

ban ans;

int q[N];
void dfs(int x, int p)
{
    if (x != p)
    {
        ans = ans * ban(q[p] + 1);
        q[p]++;
        q[x]++;
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    pre();
    ans = ban(1);
    dfs(1, 1);
    ans = ans * ban(n);
    cout << ans.x << endl;
    return 0;
}