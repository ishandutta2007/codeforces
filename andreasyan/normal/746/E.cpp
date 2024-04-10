#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 300005;

int n, m;
int a[N];
bool c[N];

int ans;
set<int> s;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        if (s.find(a[i]) != s.end())
        {
            c[i] = true;
        }
        s.insert(a[i]);
    }
    int qz = 0, qk = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;
        if (a[i] % 2 == 0)
            qz++;
        else
            qk++;
    }
    int uz = 2, uk = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
        {
            if (qz < qk)
            {
                ++ans;
                ++qz;
                while (s.find(uz) != s.end())
                {
                    uz += 2;
                }
                a[i] = uz;
                s.insert(a[i]);
                if (a[i] > m)
                {
                    printf("-1\n");
                    return 0;
                }
            }
            else
            {
                ++ans;
                ++qk;
                while (s.find(uk) != s.end())
                {
                    uk += 2;
                }
                a[i] = uk;
                s.insert(a[i]);
                if (a[i] > m)
                {
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % 2 == 0)
        {
            if (qk < qz)
            {
                ++ans;
                ++qk;
                --qz;
                while (s.find(uk) != s.end())
                {
                    uk += 2;
                }
                a[i] = uk;
                s.insert(a[i]);
                if (a[i] > m)
                {
                    printf("-1\n");
                    return 0;
                }
            }
        }
        else
        {
            if (qz < qk)
            {
                ++ans;
                ++qz;
                --qk;
                while (s.find(uz) != s.end())
                {
                    uz += 2;
                }
                a[i] = uz;
                if (a[i] > m)
                {
                    printf("-1\n");
                    return 0;
                }
                s.insert(a[i]);
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}