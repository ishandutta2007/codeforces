#include <bits/stdc++.h>

using namespace std;

const int MAXN = 220000;

int p1[MAXN], p2[MAXN];
int n, q;

int root1(int a)
{
    if (p1[a] != a)
        p1[a] = root1(p1[a]);
    return p1[a];
}

void merge1(int a, int b)
{
    p1[root1(a)] = root1(b);
}

int root2(int a)
{
    if (p2[a] != a)
        p2[a] = root2(p2[a]);
    return p2[a];
}

void merge2(int a, int b)
{
    p2[root2(a)] = root2(b);
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
        p1[i] = i;
    for (int i = 0; i < n; i++)
        p2[i] = i;
    for (int i = 0; i < q; i++)
    {
        int c;
        scanf("%d", &c);
        if (c == 1)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            a--;
            b--;
            merge1(a, b);
        }
        if (c == 2)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            l--;
            r--;
            root2(l);
            l = p2[l];
            while (l < r)
            {
                merge1(l, l + 1);
                merge2(l, l + 1);
                l = p2[l + 1];
            }
        }
        if (c == 3)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            a--;
            b--;
            root1(a);
            root1(b);
            if (p1[a] == p1[b])
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}