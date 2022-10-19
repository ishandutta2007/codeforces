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

int n, m;
char s[N], f[N];

int sp[N], fp[N];
int su[N], fu[N];

void solv()
{
    scanf(" %s %s", (s + 1), (f + 1));
    for (n = 1; s[n]; ++n){}
    --n;
    for (m = 1; f[m]; ++m){}
    --m;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == 'A')
        {
            su[i] = su[i - 1] + 1;
            sp[i] = sp[i - 1];
        }
        else
        {
            su[i] = 0;
            sp[i] = sp[i - 1] + 1;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        if (f[i] == 'A')
        {
            fu[i] = fu[i - 1] + 1;
            fp[i] = fp[i - 1];
        }
        else
        {
            fu[i] = 0;
            fp[i] = fp[i - 1] + 1;
        }
    }
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int sl, sr, fl, fr;
        scanf("%d%d%d%d", &sl, &sr, &fl, &fr);
        int sq = sp[sr] - sp[sl - 1];
        int fq = fp[fr] - fp[fl - 1];
        int sv = min(su[sr], sr - sl + 1);
        int fv = min(fu[fr], fr - fl + 1);
        if (sq > fq)
        {
            putchar('0');
            continue;
        }
        if (sv < fv)
        {
            putchar('0');
            continue;
        }
        if ((fq - sq) % 2 == 1)
        {
            putchar('0');
            continue;
        }
        if (sq == fq)
        {
            if ((sv - fv) % 3 == 0)
            {
                putchar('1');
            }
            else
            {
                putchar('0');
            }
            continue;
        }
        if (sq)
        {
            putchar('1');
            continue;
        }
        if (sv != fv)
            putchar('1');
        else
            putchar('0');
    }
    putchar('\n');
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}