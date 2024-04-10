#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, m, k;
vector<int> t[N], s[N];

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        t[x].push_back(y);
        s[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        t[i].push_back(0);
        t[i].push_back(m + 1);
    }
    for (int j = 1; j <= m; ++j)
    {
        s[j].push_back(0);
        s[j].push_back(n + 1);
    }
    for (int i = 1; i <= n; ++i)
        sort(t[i].begin(), t[i].end());
    for (int j = 1; j <= m; ++j)
        sort(s[j].begin(), s[j].end());
    int x = 1, y = 1;
    int maxx = n + 1, maxy = m + 1, minx = 0, miny = 0;
    long long q = 1;
    while (1)
    {
        int y1_ = t[x][lower_bound(t[x].begin(), t[x].end(), y) - t[x].begin()] - 1;
        y1_ = min(y1_, maxy - 1);
        if (!(x == 1 && y == 1) && y1_ == y)
            break;
        minx = x;
        q += abs(y1_ - y);
        y = y1_;
        int x1 = s[y][lower_bound(s[y].begin(), s[y].end(), x) - s[y].begin()] - 1;
        x1 = min(x1, maxx - 1);
        if (x1 == x)
            break;
        maxy = y;
        q += abs(x1 - x);
        x = x1;
        y1_ = t[x][lower_bound(t[x].begin(), t[x].end(), y) - t[x].begin() - 1] + 1;
        y1_ = max(y1_, miny + 1);
        if (y1_ == y)
            break;
        maxx = x;
        q += abs(y - y1_);
        y = y1_;
        x1 = s[y][lower_bound(s[y].begin(), s[y].end(), x) - s[y].begin() - 1] + 1;
        x1 = max(x1, minx + 1);
        if (x == x1)
            break;
        miny = y;
        q += abs(x - x1);
        x = x1;
    }
    if (q == n * 1LL * m - k)
        printf("Yes\n");
    else
        printf("No\n");
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