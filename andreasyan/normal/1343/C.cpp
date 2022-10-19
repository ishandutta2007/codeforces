#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;
const long long INF = 200005000000009;

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    long long maxu[2] = {0, 0};
    int e[2] = {0, 0};
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] < 0)
        {
            if (e[1] + 1 > e[0])
            {
                e[0] = e[1] + 1;
                maxu[0] = maxu[1] + a[i];
            }
            else if (e[1] + 1 == e[0])
            {
                maxu[0] = max(maxu[0], maxu[1] + a[i]);
            }
        }
        else
        {
            if (e[0] + 1 > e[1])
            {
                e[1] = e[0] + 1;
                maxu[1] = maxu[0] + a[i];
            }
            else if (e[0] + 1 == e[1])
            {
                maxu[1] = max(maxu[1], maxu[0] + a[i]);
            }
        }
    }
    if (e[0] < e[1])
        printf("%I64d\n", maxu[1]);
    else if (e[0] > e[1])
        printf("%I64d\n", maxu[0]);
    else
        printf("%I64d\n", max(maxu[1], maxu[0]));
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}