#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005, MX = 1E6 + 5;

int n, x = 0, a[N];
bool vis[MX];
vector<int> basis, vec, ans;

void add(int u)
{
    int tmp = u;
    for (int &v : basis)
        u = min(u, u ^ v);
    if (u > 0)
    {
        basis.push_back(u);
        vec.push_back(tmp);
        for (int i = basis.size() - 1; i > 0; i--)
            if (basis[i] > basis[i - 1])
                swap(basis[i], basis[i - 1]);
            else
                break;
    }
}

void DFS(int u, int it = 0)
{
    ans.push_back(u);
    vis[u] = true;
    if (it == (1 << x) - 1)
        return;
    for (int &v : vec)
        if (!vis[u ^ v])
        {
            DFS(u ^ v, it + 1);
            return;
        }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    int pt = 0;
    for (int i = 1; i < 20; i++)
    {
        for (; pt < n && a[pt] < (1 << i); pt++)
            add(a[pt]);
        if (basis.size() == i)
            x = i;
    }
    basis.clear();
    vec.clear();
    for (int i = 0; i < n && a[i] < (1 << x); i++)
        add(a[i]);
    printf("%d\n", x);
    DFS(0);
    for (int &v : ans)
        printf("%d ", v);
}