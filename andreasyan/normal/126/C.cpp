#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 2002;

int n;
char a[N][N];

int s1[N], t1[N], s2[N], t2[N];

void solv()
{
    scanf(" %d", &n);
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (a[i] + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            a[i][j] -= '0';
        }
    }
    int ans = 0;
    for (int i = n; i >= 1; --i)
    {
        for (int j = 1; j < i; ++j)
        {
            if ((t1[i] ^ s1[j]) != a[i][j])
            {
                ++ans;
                t1[i] ^= 1;
                s1[j] ^= 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = n; j > i; --j)
        {
            if ((t2[i] ^ s2[j]) != a[i][j])
            {
                ++ans;
                t2[i] ^= 1;
                s2[j] ^= 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if ((s1[i] ^ s2[i] ^ t1[i] ^ t2[i]) != a[i][i])
        {
            ++ans;
        }
    }
    printf("%d\n", ans);
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