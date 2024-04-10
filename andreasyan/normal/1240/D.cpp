#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n;
int a[N];

long long ans;

int z;
map<int, int> t[N];
int p[N];
int q[N];

void rec(int l, int r)
{
    if (l == r)
        return;
    int m = (l + r) / 2;
    rec(l, m);
    rec(m + 1, r);

    for (int i = 0; i <= z; ++i)
    {
        t[i].clear();
        q[i] = 0;
        p[i] = 0;
    }
    z = 0;

    stack<int> s;
    int pos = 0;
    for (int i = m + 1; i <= r; ++i)
    {
        if (s.empty() || a[i] != s.top())
        {
            if (t[pos].find(a[i]) == t[pos].end())
            {
                t[pos][a[i]] = ++z;
                p[z] = pos;
            }
            pos = t[pos][a[i]];
            q[pos]++;
            s.push(a[i]);
        }
        else
        {
            pos = p[pos];
            q[pos]++;
            s.pop();
        }
    }
    while (!s.empty())
        s.pop();
    pos = 0;
    for (int i = m; i >= l; --i)
    {
        if (s.empty() || a[i] != s.top())
        {
            if (t[pos].find(a[i]) == t[pos].end())
            {
                t[pos][a[i]] = ++z;
                p[z] = pos;
            }
            pos = t[pos][a[i]];
            ans += q[pos];
            s.push(a[i]);
        }
        else
        {
            pos = p[pos];
            ans += q[pos];
            s.pop();
        }
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    ans = 0;
    rec(1, n);
    printf("%lld\n", ans);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}