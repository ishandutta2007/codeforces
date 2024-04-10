#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;
char a[N];

int q1[10], q2[10];

int stg()
{
    int ans = 0;
    for (int i = 0; i < 10; ++i)
    {
        ans += min(q1[i], q2[9 - i]);
    }
    return ans;
}

int m;
char ans1[N], ans2[N];

void solv()
{
    scanf(" %s", a);
    n = strlen(a);
    m = n;
    for (int i = 0; i < n; ++i)
    {
        q1[a[i] - '0']++;
        q2[a[i] - '0']++;
    }
    while (q1[0] > q1[9])
    {
        --q1[0];
        --q2[0];
        --m;
        ans1[m] = '0';
        ans2[m] = '0';
    }
    int maxu = -1;
    for (int i = 1; i <= 5; ++i)
    {
        if (q1[i] && q2[10 - i])
        {
            --q1[i];
            --q2[10 - i];
            maxu = max(maxu, stg() + 1);
            ++q1[i];
            ++q2[10 - i];
        }
    }
    ////////////////////////////////////////
    for (int i = 1; i <= 5; ++i)
    {
        if (q1[i] && q2[10 - i])
        {
            --q1[i];
            --q2[10 - i];
            if (maxu == stg() + 1)
            {
                --m;
                ans1[m] = i + '0';
                ans2[m] = (10 - i) + '0';
                for (int i = 0; i < 10; ++i)
                {
                    int minu = min(q1[i], q2[9 - i]);
                    for (int j = 0; j < minu; ++j)
                    {
                        --m;
                        ans1[m] = i + '0';
                        ans2[m] = (9 - i) + '0';
                    }
                    q1[i] -= minu;
                    q2[9 - i] -= minu;
                }
                int m1 = m;
                for (int i = 0; i < 10; ++i)
                {
                    while (q1[i]--)
                    {
                        --m1;
                        ans1[m1] = i + '0';
                    }
                }
                int m2 = m;
                for (int i = 0; i < 10; ++i)
                {
                    while (q2[i]--)
                    {
                        --m2;
                        ans2[m2] = i + '0';
                    }
                }
                printf("%s\n%s\n", ans1, ans2);
                return;
            }
            ++q1[i];
            ++q2[10 - i];
        }
    }
    while (q1[0])
    {
        --q1[0];
        --q2[0];
        --m;
        ans1[m] = '0';
        ans2[m] = '0';
    }
    int m1 = m;
    for (int i = 0; i < 10; ++i)
    {
        while (q1[i]--)
        {
            --m1;
            ans1[m1] = i + '0';
        }
    }
    int m2 = m;
    for (int i = 0; i < 10; ++i)
    {
        while (q2[i]--)
        {
            --m2;
            ans2[m2] = i + '0';
        }
    }
    printf("%s\n%s\n", ans1, ans2);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}