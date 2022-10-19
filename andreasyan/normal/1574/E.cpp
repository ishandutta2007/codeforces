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
const int N = 1000006, M = 998244353;

int n, m, qq;

int ast2[N];

int q1, q2;

int fqx, qqx;
int qx[N][2];

int fqy, qqy;
int qy[N][2];

void solv()
{
    cin >> n >> m >> qq;

    ast2[0] = 1;
    for (int i = 1; i < N; ++i)
        ast2[i] = (ast2[i - 1] * 2) % M;

    map<pair<int, int>, int> mp;

    while (qq--)
    {
        int x, y, z;
        cin >> x >> y >> z;

        if (mp.find(m_p(x, y)) != mp.end())
        {
            int u = mp[m_p(x, y)];

            if ((x + y) % 2 == u)
                --q1;
            if ((x + y) % 2 != u)
                --q2;

            if (qx[x][0] == 0 && qx[x][1] != 0)
                --fqx;
            else if (qx[x][0] != 0 && qx[x][1] == 0)
                --fqx;
            else if (qx[x][0] != 0 && qx[x][1] != 0)
                --qqx;

            qx[x][((y % 2) ^ u)]--;

            if (qx[x][0] == 0 && qx[x][1] != 0)
                ++fqx;
            else if (qx[x][0] != 0 && qx[x][1] == 0)
                ++fqx;
            else if (qx[x][0] != 0 && qx[x][1] != 0)
                ++qqx;

            if (qy[y][0] == 0 && qy[y][1] != 0)
                --fqy;
            else if (qy[y][0] != 0 && qy[y][1] == 0)
                --fqy;
            else if (qy[y][0] != 0 && qy[y][1] != 0)
                --qqy;

            qy[y][((x % 2) ^ u)]--;

            if (qy[y][0] == 0 && qy[y][1] != 0)
                ++fqy;
            else if (qy[y][0] != 0 && qy[y][1] == 0)
                ++fqy;
            else if (qy[y][0] != 0 && qy[y][1] != 0)
                ++qqy;
        }

        if (z == -1)
        {
            if (mp.find(m_p(x, y)) != mp.end())
                mp.erase(m_p(x, y));
        }
        else
            mp[m_p(x, y)] = z;

        if (mp.find(m_p(x, y)) != mp.end())
        {
            int u = mp[m_p(x, y)];

            if ((x + y) % 2 == u)
                ++q1;
            if ((x + y) % 2 != u)
                ++q2;

            if (qx[x][0] == 0 && qx[x][1] != 0)
                --fqx;
            else if (qx[x][0] != 0 && qx[x][1] == 0)
                --fqx;
            else if (qx[x][0] != 0 && qx[x][1] != 0)
                --qqx;

            qx[x][((y % 2) ^ u)]++;

            if (qx[x][0] == 0 && qx[x][1] != 0)
                ++fqx;
            else if (qx[x][0] != 0 && qx[x][1] == 0)
                ++fqx;
            else if (qx[x][0] != 0 && qx[x][1] != 0)
                ++qqx;

            if (qy[y][0] == 0 && qy[y][1] != 0)
                --fqy;
            else if (qy[y][0] != 0 && qy[y][1] == 0)
                --fqy;
            else if (qy[y][0] != 0 && qy[y][1] != 0)
                --qqy;

            qy[y][((x % 2) ^ u)]++;

            if (qy[y][0] == 0 && qy[y][1] != 0)
                ++fqy;
            else if (qy[y][0] != 0 && qy[y][1] == 0)
                ++fqy;
            else if (qy[y][0] != 0 && qy[y][1] != 0)
                ++qqy;
        }

        int ans = 0;
        if (qqx == 0)
            ans = (ans + ast2[n - fqx]) % M;
        if (qqy == 0)
            ans = (ans + ast2[m - fqy]) % M;
        if (q1 == 0)
            ans = (ans - 1 + M) % M;
        if (q2 == 0)
            ans = (ans - 1 + M) % M;

        cout << ans << "\n";
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
        solv();
    return 0;
}