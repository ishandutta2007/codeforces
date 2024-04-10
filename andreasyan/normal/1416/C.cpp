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

const int m = 30;

int z;
int t[N * m][2];
int q[N * m][2];
ll ans0[m][2];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i)
    {
        int pos = 0;
        for (int j = m - 1; j >= 0; --j)
        {
            if (j == 3)
                printf("");
            int u = 0;
            if ((a[i] & (1 << j)))
                u = 1;
            if (!t[pos][u])
                t[pos][u] = ++z;
            if (u == 0)
            {
                ans0[j][0] += q[pos][1];
            }
            else
            {
                ans0[j][1] += q[pos][0];
            }
            q[pos][u]++;
            pos = t[pos][u];
        }
    }

    ll yans = 0;
    int x = 0;
    for (int j = m - 1; j >= 0; --j)
    {
        yans += min(ans0[j][0], ans0[j][1]);
        if (ans0[j][0] > ans0[j][1])
        {
            x += (1 << j);
        }
    }

    printf("%lld %d\n", yans, x);
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