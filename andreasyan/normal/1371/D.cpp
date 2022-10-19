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
const int N = 303;

int n, k;
int a[N][N];

void solv()
{
    scanf("%d%d", &n, &k);
    memset(a, 0, sizeof a);
    //if (k % n == 0)
    {
        int q = k / n;
        if (k % n == 0)
            printf("0\n");
        else
            printf("2\n");
        int j = 0;
        for (int i = 0; i < n; ++i)
        {
            int q = k / n;
            if (i < k % n)
                ++q;
            for (int k = 0; k < q; ++k)
            {
                a[i][j] = 1;
                j = (j + 1) % n;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                printf("%d", a[i][j]);
            }
            printf("\n");
        }
        return;
    }
    printf("2\n");
    int q = k / n;
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < q; ++k)
        {
            a[i][j] = 1;
            j = (j + 1) % n;
        }
    }
    vector<pair<int, int> > v;
    bool c[N] = {};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] == 1)
                continue;
            if (!c[j])
            {
                c[j] = true;
                v.push_back(m_p(i, j));
                break;
            }
        }
    }
    assert(sz(v) >= k % n);
    for (int i = 0; i < k % n; ++i)
        a[v[i].fi][v[i].se] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d", a[i][j]);
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
    {
        solv();
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}