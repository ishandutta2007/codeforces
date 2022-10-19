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

int n;
int a[N];

vector<int> u[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        u[i].clear();
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        v.push_back(a[i]);
    }
    sort(all(v));
    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(all(v), a[i]) - v.begin();
    for (int i = 1; i <= n; ++i)
    {
        u[a[i]].push_back(i);
    }
    int ans = 0;
    int y = 0;
    int dy = 0;
    for (int x = 0; x < n; ++x)
    {
        if (u[x].empty())
            continue;
        for (int i = 0; i < u[x].size(); ++i)
        {
            if (u[y].back() < u[x][i])
                ans = max(ans, dy + sz(u[x]) - i);
            else
                ans = max(ans, lower_bound(all(u[y]), u[x][i]) - u[y].begin() + sz(u[x]) - i);
        }
        int dx = sz(u[x]);
        if (u[y].back() < u[x][0])
            dx += dy;
        else
            dx += lower_bound(all(u[y]), u[x][0]) - u[y].begin();
        ans = max(ans, dx);
        dy = dx;
        y = x;
    }
    printf("%d\n", n - ans);
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