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
int x[N], y[N];
bool c[N];

ll dist(int i, int j)
{
    return (x[i] - x[j]) * 1LL * (x[i] - x[j]) + (y[i] - y[j]) * 1LL * (y[i] - y[j]);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);

    vector<int> ans;

    ans.push_back(1);
    c[1] = true;
    for (int ii = 0; ii < n - 1; ++ii)
    {
        ll maxu = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (c[i])
                continue;
            maxu = max(maxu, dist(ans.back(), i));
        }
        for (int i = 1; i <= n; ++i)
        {
            if (c[i])
                continue;
            if (maxu == dist(ans.back(), i))
            {
                ans.push_back(i);
                c[i] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}