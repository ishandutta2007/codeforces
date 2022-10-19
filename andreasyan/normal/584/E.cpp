#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 2003;

int n;
int a[N], b[N], ub[N];

int maxu[N], maxi[N];

int solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &b[i]);
        ub[b[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
        a[i] = ub[a[i]];
    int yans = 0;
    vector<pair<int, int> > ans;
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 1; i <= n; ++i)
        {
            maxu[i] = maxu[i - 1];
            maxi[i] = maxi[i - 1];
            if (a[i] > maxu[i])
            {
                maxu[i] = a[i];
                maxi[i] = i;
            }
        }
        int u;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == x)
            {
                u = i;
                break;
            }
        }
        while (u != x)
        {
            ans.push_back(m_p(u, maxi[u - 1]));
            swap(a[u], a[maxi[u - 1]]);
            u = maxi[u - 1];
        }
    }
    for (int i = 0; i < ans.size(); ++i)
        yans += abs(ans[i].first - ans[i].second);
    printf("%d\n", yans);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}