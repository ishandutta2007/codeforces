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

int n;
int a[N];

int uu[N];
int u[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != a[i - 1])
            v.push_back(a[i]);
    }

    int ans = sz(v);

    for (int i = 1; i <= n; ++i)
        uu[i] = n + 1;
    for (int i = sz(v) - 1; i >= 0; --i)
    {
        u[i] = uu[v[i]];
        uu[v[i]] = i;
    }

    int x = 0, y = 0;
    int ux = n + 1, uy = n + 1;
    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i] == x)
        {
            --ans;
            x = v[i];
            ux = u[i];
        }
        else if (v[i] == y)
        {
            --ans;
            y = v[i];
            uy = u[i];
        }
        else
        {
            if (uy < ux)
            {
                x = v[i];
                ux = u[i];
            }
            else
            {
                y = v[i];
                uy = u[i];
            }
        }
    }

    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}