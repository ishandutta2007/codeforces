#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 300005;

int n;
long long k;
int a[N];

long long b[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%I64d", &n, &k);
    for (int i = 0; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        b[i] += a[i];
        int j = i;
        while (1)
        {
            if (abs(b[j]) <= 1)
                break;
            b[j + 1] += (b[j] / 2);
            b[j] %= 2;
            ++j;
        }
    }
    int u;
    for (int i = 0; i < N; ++i)
    {
        if (b[i])
        {
            u = i;
            break;
        }
    }
    int ans = 0;
    for (int i = N - 2; i >= 0; --i)
    {
        b[i] = (b[i] + b[i + 1] * 2);
        if (abs(b[i]) > k * 4)
        {
            break;
        }
        if (i <= min(n, u))
        {
            if (i == n)
            {
                if (abs(a[i] - b[i]) <= k && a[i] - b[i] != 0)
                    ++ans;
            }
            else
            {
                if (abs(a[i] - b[i]) <= k)
                    ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}