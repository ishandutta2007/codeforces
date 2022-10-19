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
const int N = 500005;

int n, t;
char a[N];

int qs, qh;

bool stg(int q)
{
    int tt = 0;
    int hh = 0;
    int b = 0;
    int l = 0;
    int m;
    int qq = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'S')
            ++qq;
        if (qq == qh)
        {
            m = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] == 'H')
        {
            m = max(m, i);
            break;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'H')
        {
            if (q > 0)
            {
                --q;
                ++hh;
                if (hh == qh)
                    break;
            }
            else
            {
                if (b == 0)
                    l = i;
                ++b;
            }
        }
        else if (a[i] == 'S')
        {
            ++q;
            if (q == b)
            {
                hh += b;
                b = 0;
                q = 0;
                tt += (i - l);
                if (hh == qh)
                    break;
                tt += (i - l);
            }
        }
        if (b)
        {
            if (tt + (m - i) + (m - l) <= t)
                return true;
        }
        ++tt;
    }
    return (tt <= t);
}

void solv()
{
    scanf("%d%d", &n, &t);
    scanf(" %s", (a + 1));
    a[0] = '.';
    ++n;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'H')
            ++qh;
        else if (a[i] == 'S')
            ++qs;
    }
    int l = max(0, qh - qs), r = n;
    int ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}