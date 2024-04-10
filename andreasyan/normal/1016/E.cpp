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
const double EPS = 0.000001;

int sy, a, b;
int n;
int l[N], r[N];

int p[N];

double hat(double x1, double y1_, double x2, double y2)
{
    return (sy - y1_) / (y2 - y1_) * (x2 - x1) + x1;
}

void solv()
{
    scanf("%d%d%d", &sy, &a, &b);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &l[i], &r[i]);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + r[i] - l[i];
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int ll = 1, rr = n;
        int ansl = n + 1;
        while (ll <= rr)
        {
            int m = (ll + rr) / 2;
            double u = hat(x, y, r[m], 0);
            if (a <= u + EPS)
            {
                ansl = m;
                rr = m - 1;
            }
            else
                ll = m + 1;
        }
        ll = 1, rr = n;
        int ansr = 0;
        while (ll <= rr)
        {
            int m = (ll + rr) / 2;
            double u = hat(x, y, l[m], 0);
            if (u <= b + EPS)
            {
                ansr = m;
                ll = m + 1;
            }
            else
                rr = m - 1;
        }
        double ans = 0;
        if (ansl <= ansr)
        {
            ans += (double)(p[ansr] - p[ansl - 1]) * (y - sy) / ((double)y);
            if (hat(x, y, l[ansl], 0) < a)
                ans -= (a - hat(x, y, l[ansl], 0));
            if (hat(x, y, r[ansr], 0) > b)
                ans -= (hat(x, y, r[ansr], 0) - b);
        }
        printf("%.12f\n", ans);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}