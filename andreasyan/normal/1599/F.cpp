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
const int N = 200005, M = 1000000007, K = 55;

int ast(int x, int n)
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
int a[N];

int p[N];

const int k = 50;
int pk[N];

int c[K][K];
int pi[N][K];

int asta1[K];
int astd[K];

void solv()
{
    cin >> n >> qq;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        p[i] = (p[i - 1] + a[i]) % M;

    for (int i = 1; i <= n; ++i)
        pk[i] = (pk[i - 1] + ast(a[i], k)) % M;

    for (int i = 0; i < K; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
    pi[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        int ii = 1;
        for (int j = 0; j < K; ++j)
        {
            pi[i][j] = (pi[i - 1][j] + ii) % M;
            ii = (ii * 1LL * i) % M;
        }
    }

    while (qq--)
    {
        int l, r, d;
        cin >> l >> r >> d;

        int s = (p[r] - p[l - 1] + M) % M;

        int a1 = (s * 2LL * ast(r - l + 1, M - 2)) % M;
        a1 = (a1 - (r - l) * 1LL * d) % M;
        a1 = (a1 * 1LL * ast(2, M - 2)) % M;
        a1 = (a1 + M) % M;

        asta1[0] = 1;
        for (int i = 1; i < K; ++i)
            asta1[i] = (asta1[i - 1] * 1LL * a1) % M;
        astd[0] = 1;
        for (int i = 1; i < K; ++i)
            astd[i] = (astd[i - 1] * 1LL * d) % M;

        int ss = 0;
        for (int i = 0; i <= k; ++i)
        {
            int pp = (asta1[k - i] * 1LL * astd[i]) % M;
            pp = (pp * 1LL * c[k][i]) % M;
            pp = (pp * 1LL * pi[r - l][i]) % M;
            ss = (ss + pp) % M;
        }

        if (ss == (pk[r] - pk[l - 1] + M) % M)
            cout << "Yes\n";
        else
            cout << "No\n";
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