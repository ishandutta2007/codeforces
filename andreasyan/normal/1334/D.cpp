#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;

int n;
long long l, r;

void solv()
{
    scanf("%d%I64d%I64d", &n, &l, &r);
    int u = 1;
    long long ll = 1, rr = (n - 1) * 2;
    while (1)
    {
        if (!(rr < l || r < ll))
        {
            bool z = true;
            int i = u;
            for (long long j = ll; j <= rr; ++j)
            {
                if (z)
                {
                    if (l <= j && j <= r)
                        printf("%d ", u);
                    ++i;
                }
                else
                {
                    if (l <= j && j <= r)
                        printf("%d ", i);
                }
                z ^= true;
            }
        }
        ++u;
        if (u == n + 1)
        {
            if ((l <= (rr + 1) && (rr + 1) <= r))
                printf("1 ");
            break;
        }
        ll = rr + 1;
        rr = ll + (n - u) * 2 - 1;
    }
    printf("\n");
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}