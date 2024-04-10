#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
typedef long long ll;
const int N = 200005;

int n, m;
char a[N], b[N];

int p[N], s[N];

void solv()
{
    scanf("%d%d", &n, &m);
    scanf(" %s %s", (a + 1), (b + 1));

    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1];
        if (p[i] != m && a[i] == b[p[i] + 1])
            ++p[i];
    }
    s[n + 1] = m + 1;
    for (int i = n; i >= 1; --i)
    {
        s[i] = s[i + 1];
        if (s[i] != 1 && a[i] == b[s[i] - 1])
            --s[i];
    }

    int ans = 0;
    int nn = n;
    while (s[nn] == m + 1)
        --nn;
    for (int i = 1; i <= n; ++i)
    {
        if (p[i] == 0)
            continue;
        int l = i + 1, r = nn;
        int u = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (p[i] >= s[m] - 1)
            {
                u = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        ans = max(ans, u - i);
    }

    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}