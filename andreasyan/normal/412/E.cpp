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
const int N = 1000006, M = 1000000007;

int n;
char a[N];

int u[N];

int pa[N];
int p1[N];
int p_[N];

int sum(int p[], int l, int r)
{
    if (l == 0)
        return p[r];
    return p[r] - p[l - 1];
}

void solv()
{
    scanf(" %s", a);
    n = strlen(a);
    for (int i = 0; i < n; ++i)
    {
        if ('a' <= a[i] && a[i] <= 'z')
            a[i] = 'a';
        if ('0' <= a[i] && a[i] <= '9')
            a[i] = '1';
    }
    u[n] = n;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] == '.')
            u[i] = i;
        else
            u[i] = u[i + 1];
    }
    for (int i = 0; i < n; ++i)
    {
        if (i)
        {
            pa[i] = pa[i - 1];
            p1[i] = p1[i - 1];
            p_[i] = p_[i - 1];
        }
        if (a[i] == 'a')
            ++pa[i];
        else if (a[i] == '1')
            ++p1[i];
        else if (a[i] == '_')
            ++p_[i];
    }
    ll yans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '@')
        {
            int j = u[i];
            if (j == i + 1)
                continue;
            if (sum(p1, i + 1, j - 1) + sum(pa, i + 1, j - 1) != j - i - 1)
                continue;
            if (j == n)
                break;
            int l = 0, r = i;
            int ans1;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (sum(pa, m, i) + sum(p1, m, i) + sum(p_, m, i) == (i - m))
                {
                    ans1 = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            l = j, r = n - 1;
            int ans2;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (sum(pa, j, m) == (m - j))
                {
                    ans2 = m;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            yans += sum(pa, ans1, i) * 1LL * (ans2 - j);
        }
    }
    printf("%lld\n", yans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}