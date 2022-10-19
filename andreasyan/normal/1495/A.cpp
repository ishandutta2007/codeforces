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

int n;

void solv()
{
    scanf("%d", &n);
    vector<int> x, y;
    for (int i = 0; i < n * 2; ++i)
    {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        if (xx == 0)
            y.push_back(yy);
        if (yy == 0)
            x.push_back(xx);
    }

    for (int i = 0; i < n; ++i)
    {
        if (x[i] < 0)
            x[i] *= -1;
    }
    for (int i = 0; i < n; ++i)
    {
        if (y[i] < 0)
            y[i] *= -1;
    }

    sort(all(x));
    sort(all(y));

    double ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += sqrt(x[i] * 1LL * x[i] + y[i] * 1LL * y[i]);
    }
    printf("%.15f\n", ans);
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