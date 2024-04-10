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
const int N = 12;

int n, m;
char a[N][N];

char b[N];

bool stg()
{
    for (int i = 0; i < n; ++i)
    {
        int q = 0;
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] != b[j])
                ++q;
        }
        if (q > 1)
            return false;
    }
    return true;
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf(" %s", a[i]);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            b[j] = a[i][j];
        b[m] = 0;
        for (int j = 0; j < m; ++j)
        {
            for (char k = 'a'; k <= 'z'; ++k)
            {
                b[j] = k;
                if (stg())
                {
                    printf("%s\n", b);
                    return;
                }
            }
            b[j] = a[i][j];
        }
    }
    printf("-1\n");
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