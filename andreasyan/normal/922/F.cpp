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

int n, k;
int d[N];

bool c[N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + i; j <= n; j += i)
            d[j]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        k -= d[i];
        if (k <= 0)
        {
            printf("Yes\n");
            k *= -1;
            while (k)
            {
                int maxu = 0;
                for (int j = i / 2 + 1; j <= i; ++j)
                {
                    if (c[j])
                        continue;
                    if (d[j] <= k)
                        maxu = max(maxu, d[j]);
                }
                for (int j = i / 2 + 1; j <= i; ++j)
                {
                    if (c[j])
                        continue;
                    if (d[j] == maxu)
                    {
                        c[j] = true;
                        k -= d[j];
                        break;
                    }
                }
            }
            int q = 0;
            for (int j = 1; j <= i; ++j)
            {
                if (!c[j])
                    ++q;
            }
            printf("%d\n", q);
            for (int j = 1; j <= i; ++j)
            {
                if (!c[j])
                    printf("%d ", j);
            }
            printf("\n");
            return;
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
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}