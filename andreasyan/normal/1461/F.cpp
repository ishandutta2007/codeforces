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

char s[5];
bool c[300];

char ans[N];

ll dp[N];
void solvv(int l, int r)
{
    if (l > r)
        return;
    while (l <= r && a[l] == 1)
    {
        ans[l] = '+';
        ++l;
    }
    if (l > r)
        return;
    while (r >= l && a[r] == 1)
    {
        --r;
        ans[r] = '+';
    }
    if (l > r)
        return;

    ll p = 1;
    for (int i = l; i <= r; ++i)
    {
        p *= a[i];
        if (p > 100000000900000008)
        {
            for (int i = l; i < r; ++i)
                ans[i] = '*';
            return;
        }
    }

    vector<int> v;
    for (int i = l; i <= r; ++i)
    {
        if (a[i] > 1)
            v.push_back(i);
    }

    dp[0] = a[v[0]];
    for (int i = 1; i < sz(v); ++i)
    {
        dp[i] = 0;
        ll p = 1;
        for (int j = i; j >= 0; --j)
        {
            p *= a[v[j]];
            if (j > 0)
                dp[i] = max(dp[i], dp[j - 1] + p + v[j] - v[j - 1] - 1);
            else
                dp[i] = max(dp[i], p);
        }
    }

    int i = sz(v) - 1;
    while (1)
    {
        ll p = 1;
        for (int j = i; j >= 0; --j)
        {
            p *= a[v[j]];
            if (j > 0)
            {
                if (dp[i] == dp[j - 1] + p + v[j] - v[j - 1] - 1)
                {
                    for (int k = v[j]; k < v[i]; ++k)
                        ans[k] = '*';
                    for (int k = v[j - 1]; k < v[j]; ++k)
                        ans[k] = '+';
                    i = j - 1;
                    break;
                }
            }
            else
            {
                assert(dp[i] == p);
                for (int k = v[j]; k < v[i]; ++k)
                    ans[k] = '*';
                i = j - 1;
                break;
            }
        }
        if (i == -1)
            break;
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    scanf(" %s", s);
    for (int i = 0; i < strlen(s); ++i)
        c[s[i]] = true;

    if (strlen(s) == 1)
    {
        for (int i = 1; i < n; ++i)
            ans[i] = s[0];
        return;
    }

    if (!c['*'])
    {
        if (c['+'])
        {
            for (int i = 1; i < n; ++i)
                ans[i] = '+';
        }
        else
        {
            for (int i = 1; i < n; ++i)
                ans[i] = '-';
        }
        return;
    }

    if (!c['+'])
    {
        bool z = false;
        for (int i = 1; i <= n; ++i)
        {
            if (!z && a[i] == 0)
            {
                z = true;
                if (i > 1)
                    ans[i - 1] = '-';
            }
            ans[i] = '*';
        }
        return;
    }

    int u = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
        {
            if (i > 1)
                ans[i - 1] = '+';
            solvv(u, i - 1);
            if (i < n)
                ans[i] = '+';
            u = i + 1;
        }
    }
    solvv(u, n);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    for (int i = 1; i <= n; ++i)
    {
        if (i > 1)
            printf("%c", ans[i - 1]);
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}