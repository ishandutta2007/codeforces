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
const int N = 1003;

int a[N] = {0, 2, 2, 2, 2, 1};

char qry(const vector<int>& v1, const vector<int>& v2)
{
    /*int g1 = 0;
    int g2 = 0;
    for (int i = 0; i < sz(v1); ++i)
        g1 += a[v1[i]];
    for (int i = 0; i < sz(v2); ++i)
        g2 += a[v2[i]];

    if (g1 > g2)
        return 'F';
    if (g1 < g2)
        return 'S';
    return 'E';*/

    printf("? %d %d\n", sz(v1), sz(v2));
    for (int i = 0; i < sz(v1); ++i)
        printf("%d ", v1[i]);
    printf("\n");
    for (int i = 0; i < sz(v2); ++i)
        printf("%d ", v2[i]);
    printf("\n");
    fflush(stdout);
    char ans[10];
    scanf(" %s", ans);
    return ans[0];
}

int n, k;

void solv()
{
    scanf("%d%d", &n, &k);

    bool z = true;
    for (int ii = 0; ii < 30; ++ii)
    {
        int x = 2 + rnd() % (n - 1);
        if (qry({1}, {x}) == 'S')
        {
            printf("! 1\n");
            fflush(stdout);
            return;
        }
    }

    int u = 1;
    while (1)
    {
        if (u + u > n)
            break;
        vector<int> v1, v2;
        for (int i = 1; i <= u; ++i)
            v1.push_back(i);
        for (int i = u + 1; i <= u + u; ++i)
            v2.push_back(i);
        if (qry(v1, v2) == 'F')
            break;
        u *= 2;
    }

    int l = u + 1, r = min(n, u + u);
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        vector<int> v1, v2;
        for (int i = u + 1; i <= m; ++i)
            v2.push_back(i);
        for (int i = 1; i <= sz(v2); ++i)
            v1.push_back(i);
        if (qry(v1, v2) == 'F')
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    printf("! %d\n", ans);
    fflush(stdout);
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