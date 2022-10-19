#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        a[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    int q = 0;
    int maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        maxu = max(maxu, a[i]);
        if (a[i])
            ++q;
    }
    printf("%d\n", max(min(q - 1, maxu), min(q, maxu - 1)));
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