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
const int N = 1003;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int qry(int h, int w, int i1, int j1, int i2, int j2)
{
    if (h == 0 || w == 0)
        return 1;
    printf("? %d %d %d %d %d %d\n", h, w, i1, j1, i2, j2);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}

int c[N];
void dfs(int x)
{
    for (int i = 1; i <= 1000; ++i)
    {
        if (c[i] != -1)
        {
            int h = gcd(i, x);
            if (c[h] == -1)
            {
                c[h] = (c[x] & c[i]);
                dfs(h);
            }
        }
    }
}

void solv()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= 1000; ++i)
        c[i] = -1;
    c[n] = 1;
    for (int i = n; i >= 1; --i)
    {
        if (n % i != 0)
            continue;
        if (c[i] != -1)
            continue;
        if ((n % (i * 2)) == 0)
        {
            c[i] = (qry(i, m, 1, 1, i + 1, 1) & c[i * 2]);
        }
        else
        {
            if ((n / i) % 2 == 1)
                c[i] = ((qry(i * (n / i / 2), m, 1, 1, i * (n / i / 2 + 1) + 1, 1) &
                                qry(i * (n / i / 2), m, i + 1, 1, i * (n / i / 2 + 1) + 1, 1)));
            else
                c[i] = ((qry(i * (n / i / 2), m, 1, 1, i * (n / i / 2) + 1, 1) &
                                qry(i * (n / i / 2 - 1), m, i + 1, 1, i * (n / i / 2) + 1, 1)));
        }
        dfs(i);
    }
    int qn = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (n % i != 0)
            continue;
        qn += c[i];
    }

    for (int i = 1; i <= 1000; ++i)
        c[i] = -1;
    c[m] = 1;
    for (int i = m; i >= 1; --i)
    {
        if (m % i != 0)
            continue;
        if (c[i] != -1)
            continue;
        if ((m % (i * 2)) == 0)
        {
            c[i] = (qry(n, i, 1, 1, 1, i + 1) & c[i * 2]);
        }
        else
        {
            if ((m / i) % 2 == 1)
                c[i] = (qry(n, i * (m / i / 2), 1, 1, 1, i * (m / i / 2 + 1) + 1) &
                                qry(n, i * (m / i / 2), 1, i + 1, 1, i * (m / i / 2 + 1) + 1));
            else
                c[i] = (qry(n, i * (m / i / 2), 1, 1, 1, i * (m / i / 2) + 1) &
                                qry(n, i * (m / i / 2 - 1), 1, i + 1, 1, i * (m / i / 2) + 1));
        }
        dfs(i);
    }
    int qm = 0;
    for (int i = 1; i <= m; ++i)
    {
        if (m % i != 0)
            continue;
        qm += c[i];
    }

    printf("! %d\n", qn * qm);
    fflush(stdout);
}

bool cc[1003];
void dfsp(int x)
{
    if (cc[x])
        return;
    cc[x] = true;
    for (int i = 1; i <= 1000; ++i)
    {
        if (cc[i])
            dfsp(gcd(x, i));
    }
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    /*int q[1003] = {};
    for (int n = 1; n <= 1000; ++n)
    {
        memset(cc, false, sizeof cc);
        cc[n] = true;
        if (n == 512)
            printf("");
        for (int i = n; i >= 1; --i)
        {
            if (n % i != 0)
                continue;
            if (cc[i])
                continue;
            dfsp(i);
            q[n] += 2;
            if (n % (i * 2) == 0)
                --q[n];
        }
    }
    int minu = 100;
    for (int n = 1; n <= 1000; ++n)
    {
        for (int m = 1; m <= 1000; ++m)
        {
            int l = 0;
            while ((1 << (l + 1)) <= n + m)
                ++l;
            minu = min(minu, 3 * l - q[n] - q[m]);
        }
    }
    for (int n = 1; n <= 1000; ++n)
    {
        for (int m = 1; m <= 1000; ++m)
        {
            int l = 0;
            while ((1 << (l + 1)) <= n + m)
                ++l;
            if (3 * l - q[n] - q[m] == minu)
            {
                printf("%d %d\n", n, m);
            }
        }
    }
    printf("%d\n", minu);
    return 0;*/

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}