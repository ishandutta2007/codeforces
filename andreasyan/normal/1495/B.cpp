#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;
int a[N];

int p[N], s[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > a[i - 1])
            p[i] = p[i - 1] + 1;
        else
            p[i] = 1;
    }
    for (int i = n; i >= 1; --i)
    {
        if (a[i] > a[i + 1])
            s[i] = s[i + 1] + 1;
        else
            s[i] = 1;
    }

    int maxp = 0;
    for (int i = 1; i <= n; ++i)
        maxp = max(maxp, p[i]);
    int maxq = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (p[i] == maxp)
            ++maxq;
    }
    if (maxq > 1)
    {
        printf("0\n");
        return;
    }
    int maxs = 0;
    for (int i = 1; i <= n; ++i)
        maxs = max(maxs, s[i]);
    maxq = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == maxs)
            ++maxq;
    }
    if (maxq > 1)
    {
        printf("0\n");
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (p[i] == maxp && s[i] == maxs && maxp == maxs && p[i] % 2 == 1)
        {
            printf("1\n");
            return;
        }
    }
    printf("0\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}