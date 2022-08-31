#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1024;
int tmp[N];
int go[N];

inline int f(int x)
{
    return x / 2 + (x % 2);
}

inline int kek(int x)
{
    if (x == 0)
    {
        return 0;
    }
    return x % 2;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n, k, x;
    scanf("%d%d%d", &n, &k, &x);
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        tmp[a[i]]++;
    }
    for (int i = 0; i < k; i++)
    {
        for (int i = 0; i < N; i++)
        {
            go[i] = 0;
        }
        int add = 0;
        for (int i = 0; i < N; i++)
        {
            if (!tmp[i])
            {
                continue;
            }
            if (!add)
            {
                go[i ^ x] += f(tmp[i]);
                go[i] += tmp[i] - f(tmp[i]);
                add = kek(tmp[i]);
            }
            else
            {
                go[i ^ x] += f(tmp[i] - 1);
                go[i] += tmp[i] - f(tmp[i] - 1);
                add = kek(tmp[i] - 1);
            }
        }
        for (int i = 0; i < N; i++)
        {
            tmp[i] = go[i];
        }
    }
    int ans = 1e9;
    int res = -1e9;
    for (int i = 0; i < N; i++)
    {
        if (tmp[i])
        {
            ans = min(ans, i);
            res = max(res, i);
        }
    }
    printf("%d %d\n", res, ans);
}