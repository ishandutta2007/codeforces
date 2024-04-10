#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
const int MAXN = 1e5;
struct f
{
    int x, next;
};
f a[MAXN + 2];
int head[MAXN];
int uk = 0;
bool use[MAXN];
int res[MAXN];

void add(int x, int y)
{
    a[uk].x = y;
    a[uk].next = head[x];
    head[x] = uk++;
}
void dfs(int v)
{
    int d;
    use[v] = true;
    d = head[v];
    while (d != -1)
    {
        if (! use[a[d].x])
            dfs(a[d].x);
        res[a[d].x] = v;
        d = a[d].next;
    }

}

int main()
{
    int n, s, f, i, x;
    cin >> n >> s >> f;
    s--;
    f--;
    memset(head, -1, sizeof head);
    for (i = 0; i < s; i++)
    {
        cin >> x;
        x--;
        add(i, x);
        add(x, i);
    }
    for (i = s + 1; i < n; i++)
    {
        cin >> x;
        x--;
        add(i, x);
        add(x, i);
    }
    dfs(f);

    for (i = 0; i < f; i++)
        cout << res[i] + 1 << " ";
    for (i = f + 1; i < n; i++)
        cout << res[i] + 1 << " ";

    return 0;
}