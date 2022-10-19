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
const int N = 23, NN = 20004, M = 998244353;

int n;
char s[NN];
int q[N][26];

int b[(1 << N)], qb[(1 << N)];
int uu[(1 << N)];
int u[2][(1 << N)];

int minu[(1 << N)];

void solv()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        int m = strlen(s);
        for (int j = 0; j < m; ++j)
            q[i][s[j] - 'a']++;
    }

    for (int x = 1; x < (1 << n); ++x)
    {
        uu[x] = 1;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
            {
                b[x] = i;
                ++qb[x];
            }
        }
    }

    for (int j = 0; j < 26; ++j)
    {
        minu[0] = NN;
        for (int x = 1; x < (1 << n); ++x)
        {
            minu[x] = min(minu[(x ^ (1 << b[x]))], (q[b[x]][j] + 1));
            uu[x] = (uu[x] * 1LL * minu[x]) % M;
        }
    }

    for (int x = 1; x < (1 << n); ++x)
    {
        u[qb[x] % 2][x] = uu[x];
    }


    for (int z = 0; z < 2; ++z)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int x = 0; x < (1 << n); ++x)
            {
                if ((x & (1 << i)))
                    u[z][x] = (u[z][x] + u[z][(x ^ (1 << i))]) % M;
            }
        }
    }

    ll ans = 0;
    for (int x = 1; x < (1 << n); ++x)
    {
        ll yans = (u[1][x] - u[0][x] + M) % M;
        yans *= qb[x];
        int s = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                s += (i + 1);
        }
        yans *= s;
        ans ^= yans;
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