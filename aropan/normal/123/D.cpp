#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100002;
const int MAXM = 20;

int n, m, k;
char s[MAXN];
int cnt[MAXN];
int A[MAXM][MAXN];
int p[MAXN], _p[MAXN], a[MAXN], _a[MAXN];

int h[MAXN], w[MAXN];
long long f[MAXN];

int sorting(int st, int &k)
{
    for (int i = 0; i < n; i++)
        _p[i] = p[i] - st < 0? p[i] - st + n : p[i] - st;

    for (int i = 0; i < k; i++)
        cnt[i] = 0;

    for (int i = 0; i < n; i++)
        cnt[a[_p[i]]]++;

    for (int i = 1; i < k; i++)
        cnt[i] += cnt[i - 1];

    for (int i = n - 1; i >= 0; i--)
        p[--cnt[a[_p[i]]]] = _p[i];

    for (int i = 0; i < n; i++)
        _p[i] = p[i] + st < n? p[i] + st : p[i] + st - n;

    _a[p[0]] = 0;
    k = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[p[i - 1]] != a[p[i]] || a[_p[i - 1]] != a[_p[i]]) k++;
        _a[p[i]] = k - 1;
    }
    for (int i = 0; i < n; i++) a[i] = _a[i];
    return 0;
}


int lcp(int x, int y)
{
    int res = 0;
    for (int i = m - 1; i >= 0; i--)
        if (A[i][x] == A[i][y])
        {
            x += 1 << i;
            y += 1 << i;
            res += 1 << i;
        }
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    gets(s);
    n = strlen(s);
    long long ans = (long long)n * (n + 1) / 2;

    s[n++] = 0;
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        a[i] = s[i];
    }
    k = 256;

    sorting(0, k);
    for (m = 0; (1 << m) < n; m++)
    {
        int st = 1 << m;
        for (int i = 0; i < n; i++)
            A[m][i] = a[i];

        sorting(st, k);
    }
    for (int i = 0; i < n; i++)
        A[m][i] = a[i];
    m++;

    k = 0;
    for (int i = 2; i < n; i++)
        a[k++] = lcp(p[i - 1], p[i]);

    n = 0;
    h[n] = -1;
    w[n] = 0;
    f[n] = 0;
    n++;

    for (int i = 0; i < k; i++)
    {
        int l = 1;
        while (h[n - 1] >= a[i]) l += w[--n];

        w[n] = l;
        h[n] = a[i];
        f[n] = f[n - 1] + (long long)l * a[i];
        n++;

        ans += f[n - 1];
    }

    printf("%I64d\n", ans);
    return 0;
}