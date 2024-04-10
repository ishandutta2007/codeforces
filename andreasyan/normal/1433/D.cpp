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
const int N = 5003;

int n;
int a[N];

vector<int> u[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    bool z = false;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != a[1])
        {
            z = true;
            break;
        }
    }
    if (!z)
    {
        printf("NO\n");
        return;
    }

    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(a[i]);
    sort(all(v));
    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;

    for (int i = 1; i <= n; ++i)
        u[i].clear();
    for (int i = 1; i <= n; ++i)
        u[a[i]].push_back(i);

    printf("YES\n");
    vector<int> t;
    z = false;
    for (int i = 1; i <= n; ++i)
    {
        if (u[i].empty())
            continue;
        if (t.empty())
        {
            t = u[i];
            continue;
        }
        for (int j = 0; j < u[i].size(); ++j)
        {
            printf("%d %d\n", t[0], u[i][j]);
        }
        if (!z)
        {
            for (int j = 1; j < t.size(); ++j)
            {
                printf("%d %d\n", t[j], u[i][0]);
            }
            z = true;
        }
        for (int j = 0; j < u[i].size(); ++j)
            t.push_back(u[i][j]);
    }
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