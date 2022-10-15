#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 55;

int n, w, m;
double a[MAXN];
double s[MAXN];
int c[MAXN];
vector < pair <int, double> > ans[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    scanf("%d %d %d", &n, &w, &m);
    for (int i = 0; i < n; i++)
        a[i] = w;

    for (int i = 0; i < m; i++)
        s[i] = n * w * 1.0 / m;

    int l, r;
    l = 0;
    r = m - 1;

    for (int i = 0; i < n; i++)
    {
        while (l < r && (s[r] < a[i] || fabs(s[r] - a[i])  < 1e-9))
        {
            ans[r].push_back(make_pair(i + 1, s[r]));
//            printf("%d %d %lf\n", i, r, s[r]);
            a[i] -= s[r];
            s[r] = 0;
            r--;
        }
        while (1e-9 < fabs(a[i]))
        {
            double v = min(s[l], a[i]);
            ans[l].push_back(make_pair(i + 1, v));
//            printf("%d %d %lf\n", i, l, v);
            a[i] -= v;
            s[l] -= v;
            if (fabs(s[l]) < 1e-9) l++;
        }
    }


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            c[ans[i][j].first]++;
    }

    for (int i = 1; i <= n; i++)
        if (c[i] > 2)
        {
            printf("NO\n");
            return 0;
        }

    printf("YES\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d %.10lf", ans[i][0].first, ans[i][0].second);
        for (int j = 1; j < (int)ans[i].size(); j++)
            printf(" %d %.10lf", ans[i][j].first, ans[i][j].second);
        printf("\n");
    }
    return 0;
}