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

int n, m;
int a[N], b[N], c[N];

vector<int> v[N];
int ans[N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &c[i]);

    for (int i = 1; i <= n; ++i)
        v[i].clear();
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != b[i])
            v[b[i]].push_back(i);
    }

    if (!v[c[m]].empty())
    {
        ans[m] = v[c[m]].back();
        v[c[m]].pop_back();
    }
    else
    {
        bool z = false;
        for (int i = 1; i <= n; ++i)
        {
            if (b[i] == c[m])
            {
                ans[m] = i;
                z = true;
                break;
            }
        }
        if (!z)
        {
            printf("NO\n");
            return;
        }
    }

    for (int i = 1; i < m; ++i)
    {
        if (!v[c[i]].empty())
        {
            ans[i] = v[c[i]].back();
            v[c[i]].pop_back();
        }
        else
            ans[i] = ans[m];
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!v[i].empty())
        {
            printf("NO\n");
            return;
        }
    }

    printf("YES\n");
    for (int i = 1; i <= m; ++i)
        printf("%d ", ans[i]);
    printf("\n");
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