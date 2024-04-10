#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;
struct asd
{
    string s;
    int k;
};
struct node
{
    int x, next;
};
bool operator < (asd a, asd b)
{
    return a.s < b.s;
}
const int MAXN = 202;
const int MAXM = 1e5;
string a[MAXN];
asd b[MAXM];
node c[MAXM];
int head[MAXN];
string d[MAXM];
bool use[MAXN];
int mt[MAXM];
bool use2[MAXN];
string ans[MAXN];
int uk1 = 0;

void add(int x, int y)
{
    c[uk1].x = y;
    c[uk1].next = head[x];
    head[x] = uk1;
    uk1++;
}

bool dfs(int v)
{
    if (use2[v]) return false;
    use2[v] = true;
    int d;
    d = head[v];
    while (d != -1)
    {
        if (mt[c[d].x] == -1 || dfs(mt[c[d].x]))
        {
            mt[c[d].x] = v;
            return true;
        }
        d = c[d].next;
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, uk = 0, i, m, i1, i2, i3, i4, last;
    cin >> n;
    string s;
    memset(head, -1, sizeof head);
    memset(mt, -1, sizeof mt);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        cerr << a[i] << "\n";
        s = a[i];
        m = a[i].length();
        for (i1 = 0; i1 < m; i1++)
            for (i2 = i1 + 1; i2 < m; i2++)
                for (i3 = i2 + 1; i3 < m; i3++)
                    for (i4 = i3 + 1; i4 < m; i4++)
                    {
                        b[uk].k = i;
                        (((b[uk++].s += a[i][i1]) += a[i][i2]) += a[i][i3]) += a[i][i4];
                    }

        for (i1 = 0; i1 < m; i1++)
            for (i2 = i1 + 1; i2 < m; i2++)
                for (i3 = i2 + 1; i3 < m; i3++)
                {
                    b[uk].k = i;
                    ((b[uk++].s += a[i][i1]) += a[i][i2]) += a[i][i3];
                }
        for (i1 = 0; i1 < m; i1++)
            for (i2 = i1 + 1; i2 < m; i2++)
            {
                b[uk].k = i;
                (b[uk++].s += a[i][i1]) += a[i][i2];
            }
        for (i1 = 0; i1 < m; i1++)
        {
            b[uk].k = i;
            b[uk++].s += a[i][i1];
        }
    }
    sort(b, b + uk);
    last = -1;
    for (i = 0; i < uk; i++)
    {
        if (i == 0 || b[i].s != b[i - 1].s)
        {
             d[++last] = b[i].s;
        }
        add(b[i].k, last);
    }
    for (i = 0; i < n; i++)
    {
        memset(use2, false, sizeof use2);
        if (dfs(i))
            use[i] = true;
    }
    for (i = 0; i < n; i++)
        if (! use[i])
        {
            cout << -1;
            return 0;
        }
    for (i = 0; i <= last; i++)
    {
        if (mt[i] != -1)
            ans[mt[i]] = d[i];
    }
    for (i = 0; i < n; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}

/*
  if (m == 3)
        {
            b[uk++] = a[i][0];
            b[uk++] = a[i][1];
            b[uk++] = a[i][2];
            b[uk++] = a[i][0] + a[i][1];
            b[uk++] = a[i][0] + a[i][2];
            b[uk++] = a[i][1] + a[i][2];
            b[uk++] = a[i];
        }
        if (m == 2)
        {
            b[uk++] = a[i][0];
            b[uk++] = a[i][1];
            b[uk++] = a[i];
        }
        if (m == 1)
            b[uk++] = a[i];*/