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
const int N = 300005;

int n;
int a[N];
int q[N];

char ans[N];

void ka()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
}

void solv()
{
    for (int i = 1; i <= n; ++i)
        q[i] = 0;

    for (int i = 1; i <= n; ++i)
        ++q[a[i]];

    for (int k = 1; k <= n; ++k)
        ans[k] = '0';

    int l = 1, r = n;
    while (l < r)
    {
        int u = (l - 1) + (n - r) + 1;
        if (q[u] == 0)
            break;
        ans[n - u + 1] = '1';
        if (q[u] > 1)
        {
            break;
        }
        if (a[l] == u)
            ++l;
        else if (a[r] == u)
            --r;
        else
            break;
    }

    bool z = true;
    for (int i = 1; i <= n; ++i)
        if (q[i] != 1)
            z = false;
    if (z)
        ans[1] = '1';

    for (int k = 1; k <= n; ++k)
        putchar(ans[k]);
    putchar('\n');
}

char ans0[N];
void solv0()
{
    for (int k = 1; k <= n; ++k)
    {
        ans0[k] = '0';
        set<int> s;
        for (int l = 1; l <= n - k + 1; ++l)
        {
            int r = l + k - 1;
            int minu = n;
            for (int i = l; i <= r; ++i)
            {
                minu = min(minu, a[i]);
            }
            s.insert(minu);
        }
        if (sz(s) == n - k + 1)
        {
            bool z = true;
            for (int i = 1; i <= n - k + 1; ++i)
            {
                if (s.find(i) == s.end())
                {
                    z = false;
                    break;
                }
            }
            if (z)
                ans0[k] = '1';
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    /*while (1)
    {
        n = 5;
        for (int i = 1; i <= n; ++i)
            a[i] = rnf() % n + 1;
        solv();
        solv0();
        for (int i = 1; i <= n; ++i)
        {
            if (ans[i] != ans0[i])
            {
                printf("WA\n");
                return 0;
            }
        }
    }*/

    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        ka();
        solv();
    }
    return 0;
}