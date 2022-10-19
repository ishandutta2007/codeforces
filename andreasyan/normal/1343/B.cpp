#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n;

void solv()
{
    scanf("%d", &n);
    if ((n / 2) % 2 == 1)
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    int x = 2;
    for (int i = 1; i <= n / 2; ++i)
    {
        printf("%d ", x);
        if (i % 2 == 1)
            x += 2;
        else
            x += 4;
    }
    x = 1;
    for (int i = 1; i <= n / 2; ++i)
    {
        printf("%d ", x);
        if (i % 2 == 1)
            x += 4;
        else
            x += 2;
    }
    printf("\n");
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