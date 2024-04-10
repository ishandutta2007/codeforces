#include <bits/stdc++.h>
using namespace std;
const int N = 400005;

int n;
int a[N];

int p[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    vector<int> v;
    v.push_back(0);
    int q = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == a[i - 1])
        {
            ++q;
        }
        else
        {
            v.push_back(q);
            q = 1;
        }
    }
    v.push_back(q);
    for (int i = 1; i < v.size(); ++i)
        p[i] = p[i - 1] + v[i];
    int ansg = 0, anss = 0, ansb = 0;
    for (int i = 1; i < v.size(); ++i)
    {
        int g = p[i];
        int j;
        int s = -1;
        int l = i + 1, r = v.size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (p[m] - p[i] > g)
            {
                s = p[m] - p[i];
                j = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        if (s == -1)
            continue;
        int k = -1;
        int b = -1;
        l = j + 1, r = v.size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (p[m] - p[j] > g)
            {
                b = p[m] - p[j];
                k = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        if (b == -1)
            continue;
        int bb = -1;
        l = k, r = v.size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (g + s + b + p[m] - p[k] <= n / 2)
            {
                bb = p[m] - p[k];
                l = m + 1;
            }
            else
                r = m - 1;
        }
        if (bb == -1)
            continue;
        b += bb;
        if (g + s + b > ansg + anss + ansb)
        {
            ansg = g;
            anss = s;
            ansb = b;
        }
    }
    printf("%d %d %d\n", ansg, anss, ansb);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}