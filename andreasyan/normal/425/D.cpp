#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;
int x[N], y[N];
vector<int> xx[N], yy[N];

vector<int> v[N];
int q[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &x[i], &y[i]);
        yy[x[i]].push_back(y[i]);
        xx[y[i]].push_back(x[i]);
    }
    for (int i = 0; i < N; ++i)
    {
        sort(xx[i].begin(), xx[i].end());
        sort(yy[i].begin(), yy[i].end());
    }
    for (int i = 1; i <= n; ++i)
    {
        int ux = lower_bound(xx[y[i]].begin(), xx[y[i]].end(), x[i]) - xx[y[i]].begin() + 1;
        int uy = lower_bound(yy[x[i]].begin(), yy[x[i]].end(), y[i]) - yy[x[i]].begin() + 1;
        while (ux < xx[y[i]].size() && uy < yy[x[i]].size())
        {
            if (xx[y[i]][ux] - x[i] == yy[x[i]][uy] - y[i])
            {
                v[xx[y[i]][ux]].push_back(yy[x[i]][uy]);
                ++ux;
                ++uy;
            }
            else if (xx[y[i]][ux] - x[i] < yy[x[i]][uy] - y[i])
                ++ux;
            else
                ++uy;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
            q[v[i][j]]++;
        for (int j = 0; j < yy[i].size(); ++j)
            ans += q[yy[i][j]];
        for (int j = 0; j < v[i].size(); ++j)
            q[v[i][j]]--;
    }
    printf("%d\n", ans);
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