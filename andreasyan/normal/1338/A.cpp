#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int ans = 0;
    int maxu = a[1];
    for (int i = 1; i < n; ++i)
    {
        maxu = max(maxu, a[i]);
        if (maxu > a[i + 1])
        {
            for (int j = 30; j >= 0; --j)
            {
                if (((maxu - a[i + 1]) & (1 << j)))
                {
                    ans = max(ans, j + 1);
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}