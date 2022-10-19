#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n;
int a[N], b[N];
int c[N];

int t[N];
void ubd(int x, int y)
{
    while (x <= n)
    {
        t[x] += y;
        x += (x & (-x));
    }
}

int qry(int x)
{
    int ans = 0;
    while (x)
    {
        ans += t[x];
        x -= (x & (-x));
    }
    return ans;
}

int aa[N], bb[N];

int cc[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        ++a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &b[i]);
        ++b[i];
    }
    for (int i = 1; i <= n; ++i)
        ubd(i, 1);
    for (int i = 1; i <= n; ++i)
    {
        ubd(a[i], -1);
        aa[i] = qry(a[i]);
    }
    for (int i = 1; i <= n; ++i)
        ubd(i, 1);
    for (int i = 1; i <= n; ++i)
    {
        ubd(b[i], -1);
        bb[i] = qry(b[i]);
    }
    for (int i = n; i >= 1; --i)
    {
        int u = (cc[i] + aa[i] + bb[i]);
        cc[i] = u % (n - i + 1);
        cc[i - 1] = (cc[i - 1] + u / (n - i + 1));
    }
    for (int i = 1; i <= n; ++i)
        ubd(i, 1);
    for (int i = 1; i <= n; ++i)
    {
        if (cc[i] > (n - i))
        {
            cc[i + 1] += (cc[i] - (n - i)) * 1LL * (n - i - 1);
        }
        int l = 1, r = n;
        int ans;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (qry(m) - 1 >= cc[i])
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        c[i] = ans;
        ubd(c[i], -1);
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", c[i] - 1);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}