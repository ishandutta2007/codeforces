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
const int N = 44, M = 2000006;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int v[M];
void pre()
{
    v[1] = 1;
    for (int i = 2; i < M; ++i)
    {
        if (v[i])
            continue;
        for (int j = i; j < M; j += i)
        {
            if (v[j] == 0)
                v[j] = i;
        }
    }
}

vector<int> vu;
void getb(int x)
{
    if (x == 1)
    {
        vu.push_back(1);
        return;
    }
    int b = v[x];
    int bq = 0;
    while (x % b == 0)
    {
        x /= b;
        ++bq;
    }
    getb(x);

    int s = sz(vu);
    for (int i = 0; i < s; ++i)
    {
        int y = vu[i];
        for (int j = 0; j < bq; ++j)
        {
            y *= b;
            vu.push_back(y);
        }
    }
}

int n;
int a[N];

int q[M];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    memset(q, 0, sizeof q);

    int ans = 0;
    for (int s = 1; s <= n; ++s)
    {
        int qq = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (i == s)
                continue;
            int u = abs(a[i] - a[s]);
            if (u == 0)
            {
                ++qq;
                continue;
            }
            vu.clear();
            getb(u);
            for (int j = 0; j < vu.size(); ++j)
            {
                ++q[vu[j]];
                if (q[vu[j]] >= n / 2 - qq)
                    ans = max(ans, vu[j]);
            }
        }
        if (qq >= n / 2)
        {
            ans = -1;
            break;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (i == s)
                continue;
            int u = abs(a[i] - a[s]);
            if (u == 0)
                continue;
            vu.clear();
            getb(u);
            for (int j = 0; j < vu.size(); ++j)
            {
                q[vu[j]] = 0;
            }
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

    pre();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}