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

int n, k;
int a[N];

bool solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= n; ++i)
    {
        char s[10];
        scanf(" %s", s);
        int m = strlen(s);
        if (s[0] == '?')
        {
            a[i] = N;
            continue;
        }
        for (int j = 0; j < m; ++j)
        {
            if ('0' <= s[j] && s[j] <= '9')
                a[i] = a[i] * 10 + (s[j] - '0');
        }
        if (s[0] == '-')
            a[i] *= -1;
    }
    int q = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (a[i] == N)
            ++q;
    }
    if (k == 0)
    {
        if (q == 0)
        {
            return (a[0] == 0);
        }
        if (a[0] == 0)
            return true;
        if (a[0] != N)
            return false;
        return (((n + 1) - q) % 2) == 1;
    }
    if (q)
    {
        return ((n + 1) % 2) == 0;
    }
    for (int i = 0; i <= n; ++i)
    {
        a[i + 1] += a[i] / k;
        a[i] %= k;
    }
    for (int i = 0; i <= n + 1; ++i)
    {
        if (a[i])
            return false;
    }
    return true;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    if (solv())
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}