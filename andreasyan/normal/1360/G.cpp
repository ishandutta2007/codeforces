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
const int N = 55;

int n, m, a, b;

int q[N];
char ans[N][N];

void solv()
{
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ans[i][j] = '0';
            q[j] = 0;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        vector<pair<int, int> > v;
        for (int j = 0; j < m; ++j)
        {
            if (q[j] < b)
                v.push_back(m_p(q[j], j));
        }
        sort(v.begin(), v.end());
        if (v.size() < a)
        {
            printf("NO\n");
            return;
        }
        for (int j = 0; j < a; ++j)
        {
            ans[i][v[j].se] = '1';
            ++q[v[j].se];
        }
    }
    for (int j = 0; j < m; ++j)
    {
        if (q[j] != b)
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    for (int i = 0; i < n; ++i)
    {
        int qq = 0;
        for (int j = 0; j < m; ++j)
        {
            putchar(ans[i][j]);
        }
        putchar('\n');
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}