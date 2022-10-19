#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;
int a[N];

bool c[N];
int u[N];

bool solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        u[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
        c[i] = false;
    c[n + 1] = true;
    for (int i = 1; i <= n; ++i)
    {
        if (i > 1 && !c[u[i - 1] + 1])
        {
            if (u[i] != u[i - 1] + 1)
                return false;
        }
        c[u[i]] = true;
    }
    return true;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (solv())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}