#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, m;
vector<int> a[N];
int s[N];

long long ans;

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ++s[x];
        ++s[y];
        if (x < y)
            a[x].push_back(y);
        else
            a[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        ans += ((long long)a[i].size() * (s[i] - a[i].size()));
    }
    printf("%lld\n", ans);
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int x;
        scanf("%d", &x);
        ans -= ((long long)a[x].size() * (s[x] - a[x].size()));
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i];
            ans -= ((long long)a[y].size() * (s[y] - a[y].size()));
            a[y].push_back(x);
            ans += ((long long)a[y].size() * (s[y] - a[y].size()));
        }
        a[x].clear();
        printf("%lld\n", ans);
    }
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