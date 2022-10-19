#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
long long gcd(long long x, long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

long long hat(long long l1, long long r1, long long l2, long long r2)
{
    if (max(l1, l2) > min(r1, r2))
        return 0;
    return min(r1, r2) - max(l1, l2) + 1;
}

long long solv0(long long a, long long b, long long l, long long r)
{
    if (a > b)
        swap(a, b);
    long long d = a * b / gcd(a, b);
    long long x = (l - b + 1) / d;
    x = max(x, 0LL);
    if (!(x * d + b - 1 >= l))
        ++x;
    long long y = r / d;
    long long ans = 0;
    if (x <= y)
    {
        ans += hat(l, r, x * d, x * d + b - 1);
        ++x;
    }
    if (x <= y)
    {
        ans += hat(l, r, y * d, y * d + b - 1);
        --y;
    }
    if (x <= y)
    {
        ans += (y - x + 1) * b;
    }
    ans = (r - l + 1) - ans;
    return ans;
}

void por()
{
    int aa, bb;
    for (int a = 1; a <= 200; ++a)
    {
        for (int b = 1; b <= 200; ++b)
        {
            //printf("%d %d\n", a, b);
            int q = 0;
            for (int x = 4; x <= 10; ++x)
            {
                if (((x % a) % b) != ((x % b) % a))
                {
                    ++q;
                    if (a == 1 && b == 3)
                        printf("%d ", x);
                }
            }
            if (solv0(a, b, 4, 10) != q)
            {
                printf("WA\n");
                printf("%d %d\n", a, b);
                printf("%lld\n", solv0(a, b, 4, 10));
                return;
            }
            //printf("\n");
        }
    }
}

void solv()
{
    long long a, b, q;
    scanf("%lld%lld%lld", &a, &b, &q);
    while (q--)
    {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        printf("%lld ", solv0(a, b, l, r));
    }
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //por();
    //return 0;
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}