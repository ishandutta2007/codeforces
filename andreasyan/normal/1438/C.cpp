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
const int N = 102;

int n, m;
int a[N][N];
bool c[N][N];

void solv()
{
    scanf("%d%d", &n, &m);
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &a[i][j]);
            c[i][j] = false;
            v.push_back(a[i][j]);
        }
    }

    sort(all(v));
    vector<int> vv;
    for (int i = 0; i < sz(v); ++i)
    {
        if (!i || v[i] != v[i - 1])
            vv.push_back(v[i]);
    }
    v = vv;

    for (int k = 0; k < sz(v); ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (c[i][j])
                    continue;
                if (a[i][j] == v[k])
                    c[i][j] = true;
                if (a[i][j] == v[k] && (i + j) % 2 == k % 2)
                    ++a[i][j];
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
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