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
const int M = 998244353;

int n, m;
string a[8];
int s[8];

struct ban
{
    int a[5][8][6][5][8][6] = {};
};
ban operator*(const ban& a, const ban& b)
{
    ban c;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k <= s[j]; ++k)
            {
                for (int ii = 0; ii < 5; ++ii)
                {
                    for (int jj = 0; jj < n; ++jj)
                    {
                        for (int kk = 0; kk <= s[jj]; ++kk)
                        {
                            for (int iii = 0; iii < 5; ++iii)
                            {
                                for (int jjj = 0; jjj < n; ++jjj)
                                {
                                    for (int kkk = 0; kkk <= s[jjj]; ++kkk)
                                    {
                                        c.a[i][j][k][ii][jj][kk] = (c.a[i][j][k][ii][jj][kk] +
                            a.a[i][j][k][iii][jjj][kkk] * 1LL * b.a[iii][jjj][kkk][ii][jj][kk]) % M;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return c;
}

ban ast(ban x, int n)
{
    ban ans;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < ::n; ++j)
        {
            for (int k = 0; k <= s[j]; ++k)
            {
                ans.a[i][j][k][i][j][k] = 1;
            }
        }
    }
    while (n)
    {
        if (n % 2)
            ans = (ans * x);
        x = (x * x);
        n /= 2;
    }
    return ans;
}

void solv()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        s[i] = sz(a[i]);
    }

    ban t;
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k <= s[j]; ++k)
            {
                if (k == 0)
                {
                    for (int u1 = 0; u1 < n; ++u1)
                    {
                        for (int u2 = 0; u2 < n; ++u2)
                        {
                            bool z = true;
                            for (int kk = 0; kk < min(s[u1], s[u2]); ++kk)
                            {
                                if (a[u1][kk] != a[u2][kk])
                                {
                                    z = false;
                                    break;
                                }
                            }
                            if (!z)
                                continue;
                            if (s[u1] > s[u2])
                                t.a[0][j][k][s[u2] - 1][u1][s[u1] - s[u2]]++;
                            else
                                t.a[0][j][k][s[u1] - 1][u2][s[u2] - s[u1]]++;
                        }
                    }
                }
                else
                {
                    string g = "";
                    for (int kk = s[j] - k; kk < s[j]; ++kk)
                        g += a[j][kk];
                    for (int u = 0; u < n; ++u)
                    {
                        bool z = true;
                        for (int kk = 0; kk < min(k, s[u]); ++kk)
                        {
                            if (g[kk] != a[u][kk])
                            {
                                z = false;
                                break;
                            }
                        }
                        if (!z)
                            continue;
                        if (k > s[u])
                            t.a[0][j][k][s[u] - 1][j][k - s[u]]++;
                        else
                            t.a[0][j][k][k - 1][u][s[u] - k]++;
                    }
                }
            }
        }
    }
    for (int i = 1; i < 5; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k <= s[j]; ++k)
            {
                t.a[i][j][k][i - 1][j][k]++;
            }
        }
    }

    t = ast(t, m);
    int ans = 0;
    for (int j = 0; j < n; ++j)
    {
        ans = (ans + t.a[0][0][0][0][j][0]) % M;
    }

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}