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
const int u[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

int h, m;
bool stg(int i, int j)
{
    int x[4] = {i / 10, i % 10, j / 10, j % 10};
    for (int k = 0; k < 4; ++k)
    {
        x[k] = u[x[k]];
        if (x[k] == -1)
            return false;
    }
    reverse(x, x + 4);
    i = x[0] * 10 + x[1];
    j = x[2] * 10 + x[3];
    if (i < h && j < m)
        return true;
    return false;
}

void solv()
{
    scanf("%d%d", &h, &m);
    char s[10];
    scanf(" %s", s);

    int h0 = (s[0] - '0') * 10 + (s[1] - '0');
    int m0 = (s[3] - '0') * 10 + (s[4] - '0');

    for (int i = h0; i < h; ++i)
    {
        if (i == h0)
        {
            for (int j = m0; j < m; ++j)
            {
                if (stg(i, j))
                {
                    printf("%d%d:%d%d\n", i / 10, i % 10, j / 10, j % 10);
                    return;
                }
            }
        }
        else
        {
            for (int j = 0; j < m; ++j)
            {
                if (stg(i, j))
                {
                    printf("%d%d:%d%d\n", i / 10, i % 10, j / 10, j % 10);
                    return;
                }
            }
        }
    }
    printf("00:00\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}