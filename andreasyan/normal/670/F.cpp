#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006;

int n;
char a[N];
int q[10], qq[10];
int m;
char b[N];

int k;
char ans[N];

void solv()
{
    scanf(" %s", a);
    scanf(" %s", b);
    n = strlen(a);
    m = strlen(b);
    for (int i = 0; i < n; ++i)
    {
        q[a[i] - '0']++;
    }
    for (int i = 0; i < m; ++i)
    {
        q[b[i] - '0']--;
    }
    for (int tq = 1; tq <= n; ++tq)
    {
        int x = tq;
        int tqq = 0;
        while (x)
        {
            ++tqq;
            q[x % 10]--;
            x /= 10;
        }
        bool tqb = false;
        for (int i = 0; i < 10; ++i)
        {
            if (q[i] < 0)
            {
                tqb = true;
                break;
            }
        }
        if (!tqb && n - tqq == tq)
        {
            memcpy(qq, q, sizeof q);
            k = 0;
            memset(ans, 0, sizeof ans);
            int j = m;
            for (int i = 0; i < m; ++i)
            {
                if (b[i] != b[0])
                {
                    j = i;
                    break;
                }
            }
            int q0 = 0;
            for (int i = 1; i < m; ++i)
            {
                if (b[i] != '0')
                    break;
                ++q0;
            }
            bool z = false;
            while (k < tq)
            {
                bool zz = false;
                if (k == 0)
                {
                    for (int i = 1; i < 10; ++i)
                    {
                        if (q[i])
                        {
                            zz = true;
                            if (i < b[0] - '0' || b[0] == '0')
                            {
                                ans[k++] = i + '0';
                                --q[i];
                            }
                            else if (i == b[0] - '0')
                            {
                                if (b[j] < b[0] && (q0 >= q[0]) || (q0 == m - 1))
                                {
                                    z = true;
                                    for (int i = 0; i < m; ++i)
                                        ans[k++] = b[i];
                                }
                                else
                                {
                                    ans[k++] = i + '0';
                                    --q[i];
                                }
                            }
                            else
                            {
                                z = true;
                                for (int i = 0; i < m; ++i)
                                    ans[k++] = b[i];
                            }
                            break;
                        }
                    }
                }
                else
                {
                    if (z)
                    {
                        for (int i = 0; i < 10; ++i)
                        {
                            if (q[i])
                            {
                                zz = true;
                                ans[k++] = i + '0';
                                --q[i];
                                break;
                            }
                        }
                    }
                    else
                    {
                        for (int i = 0; i < 10; ++i)
                        {
                            if (q[i])
                            {
                                zz = true;
                                if (i < b[0] - '0')
                                {
                                    ans[k++] = i + '0';
                                    --q[i];
                                }
                                else if (i == b[0] - '0')
                                {
                                    if (b[j] < b[0])
                                    {
                                        z = true;
                                        for (int i = 0; i < m; ++i)
                                        ans[k++] = b[i];
                                    }
                                    else
                                    {
                                        ans[k++] = i + '0';
                                        --q[i];
                                    }
                                }
                                else
                                {
                                    z = true;
                                    for (int i = 0; i < m; ++i)
                                        ans[k++] = b[i];
                                }
                                break;
                            }
                        }
                    }
                }
                if (!zz)
                {
                    z = true;
                    for (int i = 0; i < m; ++i)
                        ans[k++] = b[i];
                }
            }
            if (ans[0] != '0' || (ans[0] == '0' && tq == 1))
            {
                printf("%s\n", ans);
            }
            memcpy(q, qq, sizeof qq);
            return;
        }
        x = tq;
        while (x)
        {
            q[x % 10]++;
            x /= 10;
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}