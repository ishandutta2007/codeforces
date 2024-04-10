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

int n, L;
int x[N], b[N];

double s[N * N];

double dp[N];
int p[N];
bool stg(double T)
{
    for (int i = 1; i <= n; ++i)
    {
        p[i] = 0;
        dp[i] = s[x[i]] - T * b[i];
        for (int j = 1; j < i; ++j)
        {
            if (dp[j] + s[x[i] - x[j]] - T * b[i] < dp[i])
            {
                dp[i] = dp[j] + s[x[i] - x[j]] - T * b[i];
                p[i] = j;
            }
        }
    }
    return dp[n] <= 0;
}

void solv()
{
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &b[i]);
    for (int i = 0; i < N * N; ++i)
        s[i] = sqrt(abs(L - i));
    double l = 0, r = N * N;
    for (int ii = 0; ii < 50; ++ii)
    {
        double m = (l + r) / 2;
        if (stg(m))
            r = m;
        else
            l = m;
    }
    stg(r);
    vector<int> ans;
    for (int x = n; x; x = p[x])
        ans.push_back(x);
    reverse(ans.begin(), ans.end());
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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}