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
const int N = 5003, M = 998244353;

int c[N][N];

int n, k;
char a[N];

void solv()
{
    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }

    cin >> n >> k;
    cin >> (a + 1);

    int q1 = 0;
    for (int i = 1; i <= n; ++i)
        q1 += (a[i] - '0');

    if (q1 < k)
    {
        cout << "1\n";
        return;
    }

    vector<int> v;
    int q0 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == '1')
        {
            v.push_back(q0);
            q0 = 0;
        }
        else
            ++q0;
    }
    v.push_back(q0);

    int ans = 1;
    for (int i = 0; i < sz(v); ++i)
    {
        int q = v[i];
        int kk = 0;
        for (int j = i + 1; j < sz(v); ++j)
        {
            ++kk;
            if (kk > k)
                break;
            q += v[j];

            if (kk == 1)
            {
                ans = (ans + c[q + kk][kk]) % M;
                ans = (ans - 1 + M) % M;
                continue;
            }

            ans = (ans + c[q + kk][kk]) % M;
            ans = (ans - c[q - v[j] + kk - 1][kk - 1] + M) % M;
            ans = (ans - c[q - v[i] + kk - 1][kk - 1] + M) % M;
            ans = (ans + c[q - v[i] - v[j] + kk - 2][kk - 2]) % M;
        }
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