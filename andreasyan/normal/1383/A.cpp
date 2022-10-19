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
char a[N], b[N];

void solv()
{
    scanf("%d", &n);
    scanf(" %s %s", (a + 1), (b + 1));

    bool z = true;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > b[i])
        {
            z = false;
            break;
        }
    }
    if (!z)
    {
        printf("-1\n");
        return;
    }

    int ans = 0;
    while (1)
    {
        bool z = true;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] != b[i])
            {
                z = false;
                break;
            }
        }
        if (z)
            break;
        ++ans;

        char minu = 'z';
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] != b[i])
            {
                minu = min(minu, a[i]);
            }
        }

        char minuu = 'z';
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] != b[i])
            {
                if (a[i] == minu)
                {
                    minuu = min(minuu, b[i]);
                }
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            if (a[i] != b[i])
            {
                if (a[i] == minu)
                {
                    a[i] = minuu;
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}