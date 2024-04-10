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
const int N = 200005;

int n;
int x[N];

int q[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);

    for (int i = 1; i <= 2 * n + 1; ++i)
        q[i] = 0;
    for (int i = 1; i <= n; ++i)
        ++q[x[i]];

    int ans = 0;
    bool z = true;
    for (int i = 1; i <= 2 * n + 1; ++i)
    {
        if (q[i])
        {
            if (!q[i - 1])
                z = true;
            ++ans;
            if (z && q[i] > 1)
            {
                ++ans;
                z = false;
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
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}