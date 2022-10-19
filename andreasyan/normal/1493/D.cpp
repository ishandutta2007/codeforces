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
const int N = 200005, M = 1000000007;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int u[N];
void pre()
{
    for (int i = 2; i < N; ++i)
    {
        if (u[i])
            continue;
        for (int j = i; j < N; j += i)
        {
            if (!u[j])
                u[j] = i;
        }
    }
}

int n, qq;
int a[N];

map<int, int> s[N];

void solv()
{
    pre();

    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = gcd(ans, a[i]);

    for (int i = 1; i <= n; ++i)
    {
        int x = a[i] / ans;
        int t = u[x];
        int q = 0;
        while (x > 1)
        {
            if (u[x] == t)
                ++q;
            else
            {
                s[t][i] += q;
                t = u[x];
                q = 1;
            }
            x /= u[x];
        }
        s[t][i] += q;
    }

    while (qq--)
    {
        int i, x;
        scanf("%d%d", &i, &x);
        int t = u[x];
        int q = 0;
        while (x > 1)
        {
            if (u[x] == t)
                ++q;
            else
            {
                s[t][i] += q;
                if (sz(s[t]) == n)
                {
                    int minu = s[t][1];
                    for (int i = 1; i <= n; ++i)
                    {
                        minu = min(minu, s[t][i]);
                    }
                    ans = (ans * 1LL * ast(t, minu)) % M;
                    for (int i = 1; i <= n; ++i)
                    {
                        s[t][i] -= minu;
                        if (s[t][i] == 0)
                            s[t].erase(i);
                    }
                }
                t = u[x];
                q = 1;
            }
            x /= u[x];
        }
        s[t][i] += q;
        if (sz(s[t]) == n)
        {
            int minu = s[t][1];
            for (int i = 1; i <= n; ++i)
            {
                minu = min(minu, s[t][i]);
            }
            ans = (ans * 1LL * ast(t, minu)) % M;
            for (int i = 1; i <= n; ++i)
            {
                s[t][i] -= minu;
                if (s[t][i] == 0)
                    s[t].erase(i);
            }
        }
        printf("%d\n", ans);
    }
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