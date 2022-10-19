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
const int INF = 1000000009;

int n;
int x[N], v[N];

bool stg(double t)
{
    double maxu = -INF;
    for (int i = 1; i <= n; ++i)
    {
        if (v[i] < 0)
        {
            if (maxu != -INF && x[i] + t * v[i] <= maxu)
                return true;
        }
        else
            maxu = max(maxu, x[i] + t * v[i]);
    }
    return false;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &v[i]);
    double l = 0, r = 2 * INF;
    if (!stg(r))
    {
        printf("-1\n");
        return;
    }
    for (int ii = 0; ii < 100; ++ii)
    {
        double m = (l + r) / 2;
        if (stg(m))
            r = m;
        else
            l = m;
    }
    printf("%.15f\n", r);
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