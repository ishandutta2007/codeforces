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
const int N = 503;

int n;
pair<int, int> a[N];

vector<int> ans;
void gor(int i)
{
    ans.push_back(i);
    swap(a[i], a[i + 1]);
    swap(a[i], a[i + 2]);
}

void solv()
{
    ans.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i].fi);
        a[i].se = i;
    }
    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[i] > a[j])
                ++q;
        }
    }
    if (q % 2 == 1)
    {
        bool z = false;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (a[i].fi == a[j].fi)
                {
                    swap(a[i], a[j]);
                    z = true;
                    break;
                }
            }
            if (z)
                break;
        }
        if (!z)
        {
            printf("-1\n");
            return;
        }
    }
    for (int i = n; i >= 3; --i)
    {
        pair<int, int> maxu = m_p(0, 0);
        int maxj;
        for (int j = 1; j <= i; ++j)
        {
            if (a[j] >= maxu)
            {
                maxu = a[j];
                maxj = j;
            }
        }
        while (maxj < i)
        {
            if (maxj == 1)
            {
                gor(maxj);
            }
            else
            {
                gor(maxj - 1);
            }
            ++maxj;
        }
    }
    assert(ans.size() <= n * n);
    for (int i = 2; i <= n; ++i)
    {
        assert(a[i - 1].fi <= a[i].fi);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
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
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}