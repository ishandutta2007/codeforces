#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 300005;

int n, k;
pair<int, int> b[N];
long long a[N];

long long p[N], p1[N];
long long s[N], s1[N];

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    /*for (n = 1; n <= 10; ++n)
    {
        memset(a, 0, sizeof a);
        for (int d = 1; d <= n; ++d)
        {
            for (int l = 1; l <= n - d + 1; ++l)
            {
                int r = l + d - 1;
                for (int i = l; i <= r; ++i)
                    a[i]++;
            }
        }
        for (int i = 1; i <= n + 1; ++i)
            printf("%d ", -a[i] + a[i - 1]);
        printf("\n");
        k = n;
        long long u = 0;
        for (int i = 1; i <= k; ++i)
        {
            u += (k - (i - 1) * 2);
            printf("%I64d ", u);
        }
        printf("\n");
    }*/
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        b[i].second = i;
        scanf("%d", &b[i].first);
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i)
        a[i] = b[i].first;
    --n;
    for (int i = 1; i <= n; ++i)
        a[i] = a[i + 1] - a[i];
    scanf("%d", &k);
    --k;
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = 1; i <= n; ++i)
        p1[i] = p1[i - 1] + i * a[i];
    for (int i = n; i >= 1; --i)
        s[i] = s[i + 1] + a[i];
    for (int i = n; i >= 1; --i)
        s1[i] = s1[i + 1] + (n - i + 1) * a[i];
    long long yans = 0;
    long long u = 0;
    for (int i = 1; i <= k; ++i)
    {
        u += (k - (i - 1) * 2);
        yans += (u * a[i]);
    }
    long long ans = yans;
    int ll = 1;
    for (int i = k + 1; i <= n; ++i)
    {
        int r = i;
        int l = i - k;
        if (k % 2 == 1)
        {
            long long sum0 = p1[r] - p1[r - (k + 1) / 2] - (r - (k + 1) / 2 + 1) * (p[r] - p[r - (k + 1) / 2]);
            long long sum1 = s1[l] - s1[l + (k + 1) / 2] - (n - (l + (k + 1) / 2) + 1 + 1) * (s[l] - s[l + (k + 1) / 2]);
            yans -= sum1;
            yans += sum0;
            yans -= sum1;
            yans += sum0;
            yans -= (s[l] - s[l + (k + 1) / 2]);
            yans += (p[r] - p[r - (k + 1) / 2]);
        }
        else
        {
            long long sum0 = p1[r] - p1[r - (k + 1) / 2] - (r - (k + 1) / 2) * (p[r] - p[r - (k + 1) / 2]);
            long long sum1 = s1[l] - s1[l + (k + 1) / 2] - (n - (l + (k + 1) / 2) + 1) * (s[l] - s[l + (k + 1) / 2]);
            yans -= sum1;
            yans += sum0;
            yans -= sum1;
            yans += sum0;
        }
        if (yans <= ans)
        {
            ans = yans;
            ll = l + 1;
        }
    }
    //printf("%I64d\n", ans);
    for (int i = ll; i <= ll + k; ++i)
    {
        printf("%d ", b[i].second);
    }
    return 0;
}