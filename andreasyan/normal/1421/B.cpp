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
const int N = 202;

int n;
char a[N][N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (a[i] + 1));
    vector<pair<int, int> > ans1, ans2;
    if (a[1][2] == '0')
        ans1.push_back(m_p(1, 2));
    if (a[2][1] == '0')
        ans1.push_back(m_p(2, 1));
    if (a[n][n - 1] == '1')
        ans1.push_back(m_p(n, n - 1));
    if (a[n - 1][n] == '1')
        ans1.push_back(m_p(n - 1, n));

    if (a[1][2] == '1')
        ans2.push_back(m_p(1, 2));
    if (a[2][1] == '1')
        ans2.push_back(m_p(2, 1));
    if (a[n][n - 1] == '0')
        ans2.push_back(m_p(n, n - 1));
    if (a[n - 1][n] == '0')
        ans2.push_back(m_p(n - 1, n));

    assert(min(sz(ans1), sz(ans2)) <= 2);

    if (sz(ans1) < sz(ans2))
    {
        printf("%d\n", sz(ans1));
        for (int i = 0; i < sz(ans1); ++i)
            printf("%d %d\n", ans1[i].fi, ans1[i].se);
    }
    else
    {
        printf("%d\n", sz(ans2));
        for (int i = 0; i < sz(ans2); ++i)
            printf("%d %d\n", ans2[i].fi, ans2[i].se);
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