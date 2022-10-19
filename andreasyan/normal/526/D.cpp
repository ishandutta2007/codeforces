#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1000006;

int n, k;
char a[N];

int z[N];

int q[N];

char ans[N];

int main()
{
    scanf("%d%d", &n, &k);
    scanf(" %s", a);
    int r = 0, j = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - j]);
        while (a[z[i]] == a[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            j = i;
        }
    }
    for (int d = 1; d <= (n / k); ++d)
    {
        if (z[d] >= (k - 1) * d)
        {
            q[d * k - 1]++;
            q[d * k + min(d, z[d * k])]--;
        }
    }
    int qq = 0;
    for (int i = 0; i < n; ++i)
    {
        qq += q[i];
        if (qq)
            ans[i] = '1';
        else
            ans[i] = '0';
    }
    printf("%s\n", ans);
    return 0;
}