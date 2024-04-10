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
const int N = 1000006, S = 302, M = 1000000007;

int astt(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int n, qq;
int m;
char s[S];

char t[N];
int q[N];

int pu[N][26];

int k;
char a[N];

int ast[N];
int pa[N];

int ss[N][26];

void solv()
{
    scanf("%d%d", &n, &qq);
    scanf(" %s", s);
    m = strlen(s);
    scanf(" %s", (t + 1));

    for (int i = n; i >= 1; --i)
    {
        if (t[i] == t[i + 1])
            q[i] = q[i + 1] + 1;
        else
            q[i] = 1;
    }
    ast[0] = 1;
    for (int i = 1; i <= n; ++i)
        ast[i] = (ast[i - 1] * 2) % M;
    pa[0] = 1;
    for (int i = 1; i <= n; ++i)
        pa[i] = (pa[i - 1] + ast[i]) % M;

    for (int i = n; i >= 1; --i)
    {
        for (int j = 0; j < 26; ++j)
            ss[i][j] = ss[i + 1][j];
        ss[i][t[i] - 'a'] = (ss[i][t[i] - 'a'] + astt(ast[i], M - 2)) % M;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            pu[i][j] = (pu[i - 1][j] * 2) % M;
            if (t[i] == j + 'a')
                pu[i][j] = (pu[i][j] + 1) % M;
        }
    }

    s[m] = '?';
    for (int i = m + 1; i < m * 2 + 1; ++i)
        s[i] = s[i - m - 1];

    while (qq--)
    {
        int x;
        scanf("%d", &x);
        scanf(" %s", (a + 1));
        for (k = 1; a[k]; ++k){}
        --k;

        if (k <= m)
        {
            int ans = 0;

            for (int i = 0; i < m - k + 1; ++i)
            {
                bool z = true;
                for (int j = i; j <= i + k - 1; ++j)
                {
                    if (a[j - i + 1] != s[j])
                    {
                        z = false;
                        break;
                    }
                }
                if (z)
                {
                    ans = (ans + ast[x]) % M;
                }
            }

            for (int i = 0; i < m * 2 + 1 - k + 1; ++i)
            {
                bool z = true;
                bool zh = false;
                char u;
                for (int j = i; j <= i + k - 1; ++j)
                {
                    if (a[j - i + 1] != s[j] && s[j] != '?')
                    {
                        z = false;
                        break;
                    }
                    if (s[j] == '?')
                    {
                        u = a[j - i + 1];
                        zh = true;
                    }
                }
                if (!zh)
                    z = false;

                if (z)
                {
                    ans = (ans + pu[x][u - 'a']) % M;
                }
            }

            printf("%d\n", ans);
        }
        else
        {
            int ans = 0;

            for (int i = 0; i <= m; ++i)
            {
                bool z = true;
                for (int j = i; j <= k; j += (m + 1))
                {
                    for (int u = j - m; u < j; ++u)
                    {
                        if (!(1 <= u && u <= k))
                            continue;
                        if (a[u] != s[u - (j - m)])
                        {
                            z = false;
                            break;
                        }
                    }
                    for (int u = j + 1; u <= j + m; ++u)
                    {
                        if (!(1 <= u && u <= k))
                            continue;
                        if (a[u] != s[u - (j + 1)])
                        {
                            z = false;
                            break;
                        }
                    }
                    if (!z)
                        break;
                }
                if (z)
                {
                    vector<char> v;
                    for (int j = i; j <= k; j += (m + 1))
                    {
                        if (j > 0)
                            v.push_back(a[j]);
                    }
                    for (int u = 1; u <= x; ++u)
                    {
                        if (sz(v) == 1)
                        {
                            ans = (ans + (ss[u][v[0] - 'a'] - ss[x + 1][v[0] - 'a'] + M) * 1LL * ast[x]) % M;
                            break;
                        }

                        bool z0 = true;
                        bool z1 = true;
                        for (int j = 0; j < sz(v); j += 2)
                        {
                            if (v[j] != t[u])
                            {
                                z0 = false;
                                break;
                            }
                        }
                        for (int j = 1; j < sz(v); j += 2)
                        {
                            if (v[j] != t[u])
                            {
                                z1 = false;
                                break;
                            }
                        }
                        if (z0 == false && z1 == false)
                            break;
                        else if (z0 == true && z1 == false)
                        {
                            vector<char> vv;
                            for (int j = 1; j < sz(v); j += 2)
                                vv.push_back(v[j]);
                            v = vv;
                        }
                        else if (z0 == false && z1 == true)
                        {
                            vector<char> vv;
                            for (int j = 0; j < sz(v); j += 2)
                                vv.push_back(v[j]);
                            v = vv;
                        }
                        else
                        {
                            int q0 = min(x - u + 1, q[u]);
                            int sv = sz(v);

                            int x1 = sv;
                            int x2 = sv;
                            int dp1 = 1;
                            int dp2 = 0;

                            int mn = x - u + 1;
                            int uu = u;
                            while (1)
                            {
                                if (!dp1 && !dp2)
                                    break;
                                if (!x1)
                                {
                                    ans = (ans + (dp1 * 1LL * ast[mn]) % M) % M;
                                    dp1 = 0;
                                }
                                if (!x2)
                                {
                                    ans = (ans + (dp2 * 1LL * ast[mn]) % M) % M;
                                    dp2 = 0;
                                }
                                if (x1 == 1)
                                {
                                    ans = (ans + (ss[uu][v[0] - 'a'] - ss[x + 1][v[0] - 'a'] + M) * 1LL * ast[x] % M * dp1) % M;
                                    dp1 = 0;
                                }
                                if (x2 == 1)
                                {
                                    ans = (ans + (ss[uu][v[0] - 'a'] - ss[x + 1][v[0] - 'a'] + M) * 1LL * ast[x] % M * dp2) % M;
                                    dp2 = 0;
                                }
                                ++uu;
                                --q0;
                                --mn;
                                if (q0 < 0)
                                    break;

                                int xx1 = min((x1 / 2), (x2 / 2));
                                int xx2 = max((x1 / 2) + (x1 % 2), (x2 / 2) + (x2 % 2));
                                int dpp1 = 0;
                                int dpp2 = 0;

                                if (x1 / 2 == xx1)
                                {
                                    dpp1 = (dpp1 + dp1) % M;
                                }
                                else if (x1 / 2 == xx2)
                                {
                                    dpp2 = (dpp2 + dp1) % M;
                                }
                                else
                                    assert(false);
                                if (x1 / 2 + (x1 % 2) == xx1)
                                {
                                    dpp1 = (dpp1 + dp1) % M;
                                }
                                else if (x1 / 2 + (x1 % 2) == xx2)
                                {
                                    dpp2 = (dpp2 + dp1) % M;
                                }
                                else
                                    assert(false);

                                if (x2 / 2 == xx1)
                                {
                                    dpp1 = (dpp1 + dp2) % M;
                                }
                                else if (x2 / 2 == xx2)
                                {
                                    dpp2 = (dpp2 + dp2) % M;
                                }
                                else
                                    assert(false);
                                if (x2 / 2 + (x2 % 2) == xx1)
                                {
                                    dpp1 = (dpp1 + dp2) % M;
                                }
                                else if (x2 / 2 + (x2 % 2) == xx2)
                                {
                                    dpp2 = (dpp2 + dp2) % M;
                                }
                                else
                                    assert(false);

                                x1 = xx1;
                                x2 = xx2;
                                dp1 = dpp1;
                                dp2 = dpp2;
                            }

                            break;
                        }
                    }
                }
            }

            printf("%d\n", ans);
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}