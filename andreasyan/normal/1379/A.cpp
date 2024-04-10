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
const int N = 55;

const int m = 7;
const char u[10] = "abacaba";

int n;
char a[N];

void solv()
{
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    for (int l = 1; l <= n - m + 1; ++l)
    {
        int r = l + m - 1;

        char b[N];
        for (int i = 1; i <= n; ++i)
            b[i] = a[i];

        bool z = true;
        for (int i = l; i <= r; ++i)
        {
            if (b[i] == '?')
                continue;
            if (b[i] != u[i - l])
            {
                z = false;
                break;
            }
        }

        if (z)
        {
            for (int i = l; i <= r; ++i)
            {
                b[i] = u[i - l];
            }
            for (int i = 1; i <= n; ++i)
            {
                if (b[i] == '?')
                    b[i] = 'z';
            }
            bool z = false;
            int l0 = l;
            for (int l = 1; l <= n - m + 1; ++l)
            {
                if (l == l0)
                    continue;
                int r = l + m - 1;
                bool zz = true;
                for (int i = l; i <= r; ++i)
                {
                    if (b[i] != u[i - l])
                    {
                        zz = false;
                        break;
                    }
                }
                if (zz)
                {
                    z = true;
                    break;
                }
            }
            if (!z)
            {
                printf("Yes\n");
                for (int i = 1; i <= n; ++i)
                    printf("%c", b[i]);
                printf("\n");
                return;
            }
        }
    }
    printf("No\n");
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
    {
        solv();
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}