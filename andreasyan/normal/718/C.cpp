#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;
const int M = 1000000007;

struct ban
{
    int a[2][2];
    ban()
    {
        memset(a, 0, sizeof a);
    }
};
ban operator*(const ban& a, const ban& b)
{
    ban ans;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                ans.a[i][j] = (ans.a[i][j] + a.a[i][k] * 1LL * b.a[k][j]) % M;
            }
        }
    }
    return ans;
}
ban operator+(const ban& a, const ban& b)
{
    ban ans;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            ans.a[i][j] = (a.a[i][j] + b.a[i][j]) % M;
        }
    }
    return ans;
}
ban ast(ban x, long long n)
{
    ban ans;
    for (int i = 0; i < 2; ++i)
        ans.a[i][i] = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = ans * x;
        x = x * x;
        n /= 2;
    }
    return ans;
}

ban u;

int n;
int a[N];

ban t[N * 4];
ban laz[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ast(u, a[tl]);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
    laz[pos].a[0][0] = laz[pos].a[1][1] = 1;
    laz[pos].a[1][0] = laz[pos].a[0][1] = 0;
}

void shi(int pos)
{
    t[pos * 2] = t[pos * 2] * laz[pos];
    t[pos * 2 + 1] = t[pos * 2 + 1] * laz[pos];
    laz[pos * 2] = (laz[pos * 2] * laz[pos]);
    laz[pos * 2 + 1] = (laz[pos * 2 + 1] * laz[pos]);
    laz[pos].a[0][0] = laz[pos].a[1][1] = 1;
    laz[pos].a[1][0] = laz[pos].a[0][1] = 0;
}

ban b;
void ubd(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos] = t[pos] * b;
        laz[pos] = laz[pos] * b;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return ban();
    if (tl == l && tr == r)
        return t[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int main()
{
    u.a[0][1] = u.a[1][0] = u.a[1][1] = 1;
    int qq;
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    bil(1, n, 1);
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int l, r, y;
            scanf("%d%d%d", &l, &r, &y);
            b = ast(u, y);
            ubd(1, n, l, r, 1);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", qry(1, n, l, r, 1).a[1][0]);
        }
    }
    return 0;
}