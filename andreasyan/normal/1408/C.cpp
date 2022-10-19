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

int n, d;
int a[N];

double stg1(double u)
{
    double t = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        if (a[i] >= u)
        {
            t += (u - a[i - 1]) / (double)i;
            break;
        }
        else
        {
            t += (a[i] - a[i - 1]) / (double)i;
        }
    }
    return t;
}

double stg2(double u)
{
    double t = 0;
    for (int i = n; i >= 0; --i)
    {
        if (a[i] <= u)
        {
            t += (a[i + 1] - u) / (double)(n + 1 - i);
            break;
        }
        else
        {
            t += (a[i + 1] - a[i]) / (double)(n + 1 - i);
        }
    }
    return t;
}

void solv()
{
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    a[n + 1] = d;
    double l = 0, r = d;
    for (int ii = 0; ii < 110; ++ii)
    {
        double m = (l + r) / 2;
        if (stg1(m) <= stg2(m))
            l = m;
        else
            r = m;
    }
    printf("%.15f\n", stg1(l));
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}