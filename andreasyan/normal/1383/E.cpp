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
const int N = 1000006, M = 1000000007;

int n;
char a[N];

int dp[N];

int uu1[N];

int maxu;
int s;
int dpp[N];

int solv()
{
    scanf(" %s", a);
    n = strlen(a);
    int l1 = -1, r1 = -1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '1')
        {
            l1 = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] == '1')
        {
            r1 = i;
            break;
        }
    }

    if (l1 == -1)
    {
        return n;
    }

    if (l1 == r1)
    {
        return ((l1 + 1) * 1LL * (n - r1)) % M;
    }

    int u0 = -1, u1 = -1;
    dp[l1] = 1;
    int ans = 0;
    for (int i = l1 + 1; i <= r1 - 1; ++i)
    {
        if (a[i] == '0')
        {
            u0 = i;
            if (u1 == -1)
            {
                maxu = max(maxu, i - l1);
            }
            else
            {
                maxu = max(maxu, i - u1);

                s -= dpp[i - u1];
                dpp[i - u1] = dp[u1 - 1];
                s += dpp[i - u1];

                s %= M;
                s = (s + M) % M;
            }
        }
        else
            u1 = i;
        uu1[i] = u1;

        dp[i] = 1;
        if (u0 != -1)
        {
            dp[i] = (dp[i] + maxu) % M;
            dp[i] = (dp[i] + s) % M;
        }
        if (u1 != -1)
        {
            dp[i] = (dp[i] + dp[u1 - 1]) % M;
        }
        //printf("%d ", dp[i]);
    }
    //printf("\n");

    ans = (ans + 1 + dp[r1 - 1]) % M;
    ans = (ans * 1LL * (l1 + 1)) % M;
    ans = (ans * 1LL * (n - r1)) % M;
    return ans;
}

int solv0()
{
    set<vector<bool> > s[100];
    vector<bool> v;
    s[0].insert(v);
    for (int i = 1; i <= n; ++i)
    {
        bool z = false;
        for (int j = i; j >= 1; --j)
        {
            if (a[j - 1] == '1')
                z = true;
            for (auto it = s[j - 1].begin(); it != s[j - 1].end(); ++it)
            {
                v = *it;
                v.push_back(z);
                s[i].insert(v);
            }
        }
    }
    return sz(s[n]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    printf("%d\n", solv());
    return 0;
    printf("   My answer: %d\n", solv());
    printf("Right answer: %d\n", solv0());
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}