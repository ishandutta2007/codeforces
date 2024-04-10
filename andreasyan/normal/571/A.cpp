#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int a, b, c, l;

void solv()
{
    scanf("%d%d%d%d", &a, &b, &c, &l);
    long long ans = 0;
    for (int da = 0; da <= l; ++da)
    {
        int x = min(a + da - b - c, l - da);
        if (x < 0)
            continue;
        ans += ((x + 2) * 1LL * (x + 1)) / 2;
    }
    swap(a, b);
    for (int da = 0; da <= l; ++da)
    {
        int x = min(a + da - b - c, l - da);
        if (x < 0)
            continue;
        ans += ((x + 2) * 1LL * (x + 1)) / 2;
    }
    swap(a, c);
    for (int da = 0; da <= l; ++da)
    {
        int x = min(a + da - b - c, l - da);
        if (x < 0)
            continue;
        ans += ((x + 2) * 1LL * (x + 1)) / 2;
    }
    ans = ((l + 3) * 1LL * (l + 2) * (l + 1)) / 6 - ans;
    printf("%I64d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}