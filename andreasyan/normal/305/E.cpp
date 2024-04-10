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
char a[N];

int dp[N];
bool c[N];

void solv()
{
    scanf(" %s", (a + 1));
    for (n = 1; a[n]; ++n){}
    --n;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        memset(c, false, sizeof c);
        for (int j = 1; j <= i; ++j)
        {
            int u = (dp[max(0, j - 2)] ^ dp[max(0, i - j - 1)]);
            if (u < N)
                c[u] = true;
        }
        for (int j = 0; ; ++j)
        {
            if (!c[j])
            {
                dp[i] = j;
                break;
            }
        }
    }
    int ans = 0;
    vector<int> v;
    vector<vector<int> > vv;
    for (int i = 1; i <= n; ++i)
    {
        if (i > 1 && i < n && a[i - 1] == a[i + 1])
        {
            v.push_back(i);
        }
        else
        {
            vv.push_back(v);
            ans ^= dp[v.size()];
            v.clear();
        }
    }
    if (ans)
    {
        printf("First\n");
        for (int i = 0; i < vv.size(); ++i)
        {
            ans ^= dp[vv[i].size()];
            for (int j = 1; j <= vv[i].size(); ++j)
            {
                if ((ans ^ dp[max(0, sz(vv[i]) - j - 1)] ^ dp[max(0, j - 2)]) == 0)
                {
                    printf("%d\n", vv[i][j - 1]);
                    return;
                }
            }
            ans ^= dp[vv[i].size()];
        }
    }
    else
        printf("Second\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}