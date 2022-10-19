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
const int N = 1003, S = 17, M = 998244353;

int n, qq;
char a[N];

int pr[N], su[N];

vector<int> v[(1 << S)];

int ast[N];

int ans[S + 1][(1 << S)];

void solv()
{
    cin >> n;
    cin >> (a + 1);

    for (int i = 1; i <= n; ++i)
    {
        pr[i] = pr[i - 1];
        if (a[i] == '?')
            ++pr[i];
    }
    for (int i = n; i >= 1; --i)
    {
        su[i] = su[i + 1];
        if (a[i] == '?')
            ++su[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        int x = 0;
        int q = 0;
        if (a[i] == '?')
            ++q;

        v[x].push_back(q + pr[i - 1] + su[i + 1]);
        for (int j = 1; ; ++j)
        {
            if (i + j > n)
                break;
            if (i - j < 1)
                break;

            if (a[i + j] == '?' && a[i - j] == '?')
            {
                ++q;
            }
            else if (a[i + j] == '?')
            {
                x |= (1 << (a[i - j] - 'a'));
            }
            else if (a[i - j] == '?')
            {
                x |= (1 << (a[i + j] - 'a'));
            }
            else if (a[i + j] != a[i - j])
                break;

            v[x].push_back(q + pr[i - j - 1] + su[i + j + 1]);
        }
    }

    for (int i = 1; i < n; ++i)
    {
        int x = 0;
        int q = 0;

        for (int j = 0; ; ++j)
        {
            if (i + 1 + j > n)
                break;
            if (i - j < 1)
                break;

            if (a[i + 1 + j] == '?' && a[i - j] == '?')
            {
                ++q;
            }
            else if (a[i + 1 + j] == '?')
            {
                x |= (1 << (a[i - j] - 'a'));
            }
            else if (a[i - j] == '?')
            {
                x |= (1 << (a[i + 1 + j] - 'a'));
            }
            else if (a[i + 1 + j] != a[i - j])
                break;

            v[x].push_back(q + pr[i - j - 1] + su[i + 1 + j + 1]);
        }
    }

    for (int s = 1; s <= S; ++s)
    {
        ast[0] = 1;
        for (int i = 1; i <= n; ++i)
            ast[i] = (ast[i - 1] * 1LL * s) % M;

        for (int x = 0; x < (1 << S); ++x)
        {
            for (int i = 0; i < v[x].size(); ++i)
                ans[s][x] = (ans[s][x] + ast[v[x][i]]) % M;
        }

        for (int i = 0; i < S; ++i)
        {
            for (int x = 0; x < (1 << S); ++x)
            {
                if ((x & (1 << i)))
                    ans[s][x] = (ans[s][x] + ans[s][(x ^ (1 << i))]) % M;
            }
        }
    }

    cin >> qq;
    while (qq--)
    {
        char a[S + 1];
        cin >> a;
        int s = strlen(a);

        int x = 0;
        for (int i = 0; i < s; ++i)
            x |= (1 << (a[i] - 'a'));

        cout << ans[s][x] << "\n";
    }
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