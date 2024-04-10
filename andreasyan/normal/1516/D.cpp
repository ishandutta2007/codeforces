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
const int N = 100005;

int u[N];
void pre()
{
    u[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        if (u[i])
            continue;
        u[i] = i;
        if (i * 1LL * i >= N)
            continue;
        for (int j = i * i; j < N; j += i)
        {
            if (!u[j])
                u[j] = i;
        }
    }
}

int n, qq;
int a[N];
vector<int> v[N];

int p0[N];
bool c[N];

const int m = 20;
int p[N][m];

void solv()
{
    cin >> n >> qq;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        int x = a[i];
        int z = -1;
        while (x > 1)
        {
            if (u[x] != z)
                v[i].push_back(u[x]);
            z = u[x];
            x /= u[x];
        }
    }

    p0[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        p0[i] = p0[i - 1];
        while (1)
        {
            bool z = false;
            for (int j = 0; j < v[i].size(); ++j)
            {
                if (c[v[i][j]])
                {
                    z = true;
                    break;
                }
            }
            if (!z)
                break;
            for (int j = 0; j < v[p0[i]].size(); ++j)
            {
                c[v[p0[i]][j]] = false;
            }
            ++p0[i];
        }
        for (int j = 0; j < v[i].size(); ++j)
            c[v[i][j]] = true;
    }

    for (int i = 1; i <= n; ++i)
    {
        p[i][0] = p0[i] - 1;
        for (int j = 1; j < m; ++j)
        {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }

    while (qq--)
    {
        int l, r;
        cin >> l >> r;

        int ans = 0;
        for (int j = m - 1; j >= 0; --j)
        {
            if (p[r][j] >= l)
            {
                ans += (1 << j);
                r = p[r][j];
            }
        }
        ++ans;
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

    pre();

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}