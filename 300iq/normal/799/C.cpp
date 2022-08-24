/*

 
$












 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n, c, d;
    scanf("%d%d%d", &n, &c, &d);
    vector <pair <int, int> > C;
    vector <pair <int, int> > D;
    for (int i = 0; i < n; i++)
    {
        int b, p;
        char c;
        scanf("%d %d %c", &b, &p, &c);
        if (c == 'C')
        {
            C.push_back({p, b});
        }
        else
        {
            D.push_back({p, b});
        }
    }
    sort(C.begin(), C.end());
    sort(D.begin(), D.end());
    int res = 0;
    int a = -1e9, b = -1e9;
    for (auto e : C)
    {
        if (e.first <= c)
        {
            a = max(a, e.second);
        }
    }
    for (auto e : D)
    {
        if (e.first <= d)
        {
            b = max(b, e.second);
        }
    }
    res = max(res, a + b);
    n = C.size();
    int m = D.size();
    int j = -1;
    int cur = -1e9;
    int mx_a = -1e9, mx_b = -1e9;
    for (int i = n - 1; i >= 0; i--)
    {
        while (j + 1 < n && C[j + 1].first + C[i].first <= c)
        {
            j++;
            int x = C[j].second;
            if (x > mx_a)
            {
                swap(x, mx_a);
            }
            if (x > mx_b)
            {
                swap(x, mx_b);
            }
        }
        if (mx_a != C[i].second)
        {
            res = max(res, C[i].second + mx_a);
        }
        else
        {
            res = max(res, C[i].second + mx_b);
        }
    }
    j = -1;
    cur = -1e9;
    mx_a = -1e9, mx_b = -1e9;
    for (int i = m - 1; i >= 0; i--)
    {
        while (j + 1 < m && D[j + 1].first + D[i].first <= d)
        {
            j++;
            int x = D[j].second;
            if (x > mx_a)
            {
                swap(x, mx_a);
            }
            if (x > mx_b)
            {
                swap(x, mx_b);
            }
        }
        if (mx_a != D[i].second)
        {
            res = max(res, D[i].second + mx_a);
        }
        else
        {
            res = max(res, D[i].second + mx_b);
        }
    }
    printf("%d\n", res);
}