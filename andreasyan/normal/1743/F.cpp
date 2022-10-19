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
const int N = 300005, M = 998244353;

struct ban
{
    int t[2][2];
    ban()
    {
        t[0][0] = t[0][1] = t[1][0] = t[1][1] = 0;
    }
    ban(int x)
    {
        t[0][0] = t[0][1] = t[1][0] = t[1][1] = 0;
        for (int s = 0; s < 2; ++s)
        {
            t[s][(s ^ x)]++;
            t[s][(s & x)]++;
            t[s][(s | x)]++;
        }
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    for (int x = 0; x < 2; ++x)
    {
        for (int y = 0; y < 2; ++y)
        {
            for (int z = 0; z < 2; ++z)
            {
                res.t[x][z] = (res.t[x][z] + l.t[x][y] * 1LL * r.t[y][z]) % M;
            }
        }
    }
    return res;
}

int c[N];
ban t[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(c[tl]);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(c[x]);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

vector<int> v[N];
void solv()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int l, r;
        cin >> l >> r;
        v[l].push_back(i);
        v[r + 1].push_back(i);
    }

    bil(2, n, 1);
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < sz(v[i]); ++j)
        {
            c[v[i][j]] ^= 1;
            if (v[i][j] > 1)
                ubd(2, n, v[i][j], 1);
        }
        ans = (ans + t[1].t[c[1]][1]) % M;
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