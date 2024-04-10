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

int n;
int q[N];

int ans[N][N];

void solv()
{
    scanf("%d", &n);

    memset(ans, 0, sizeof ans);
    memset(q, 0, sizeof q);

    if (n % 2 == 1)
    {
        for (int i = 1; i <= n; ++i)
            q[i] = (n - 1) / 2;
        for (int i = 1; i <= n; ++i)
        {
            vector<pair<int, int> > v;
            for (int j = i + 1; j <= n; ++j)
            {
                v.push_back(m_p(q[j], j));
            }
            sort(all(v));
            for (int j = 0; j < q[i]; ++j)
            {
                ans[i][v[j].se] = 1;
            }
            for (int j = q[i]; j < sz(v); ++j)
            {
                ans[i][v[j].se] = -1;
                q[v[j].se]--;
                assert(q[v[j].se] >= 0);
            }
            q[i] = 0;
        }
    }
    else
    {
        for (int i = 1; i <= n; ++i)
            q[i] = (n - 2) / 2;
        for (int i = 1; i <= n; ++i)
        {
            if (i % 2 == 1)
            {
                vector<pair<int, int> > v;
                for (int j = i + 2; j <= n; ++j)
                {
                    v.push_back(m_p(q[j], j));
                }
                sort(all(v));
                for (int j = 0; j < q[i]; ++j)
                {
                    ans[i][v[j].se] = 1;
                }
                for (int j = q[i]; j < sz(v); ++j)
                {
                    ans[i][v[j].se] = -1;
                    q[v[j].se]--;
                    assert(q[v[j].se] >= 0);
                }
                q[i] = 0;
            }
            else
            {
                vector<pair<int, int> > v;
                for (int j = i + 1; j <= n; ++j)
                {
                    v.push_back(m_p(q[j], j));
                }
                sort(all(v));
                for (int j = 0; j < q[i]; ++j)
                {
                    ans[i][v[j].se] = 1;
                }
                for (int j = q[i]; j < sz(v); ++j)
                {
                    ans[i][v[j].se] = -1;
                    q[v[j].se]--;
                    assert(q[v[j].se] >= 0);
                }
                q[i] = 0;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            printf("%d ", ans[i][j]);
        }
    }
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    /*for (int a = 1; a <= 200; ++a)
    {
        for (int b = a; b <= 200; ++b)
        {
            for (int c = b; c <= 200; ++c)
            {
                if (a * a + b * b == c * c && c == a * a - b)
                {
                    printf("%d %d %d\n", a, b, c);
                }
            }
        }
    }*/

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}