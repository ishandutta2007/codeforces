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
const int N = 606;
const ll INF = 1000000009003;

int n, m;
ll a[N][N];
ll aa[N];

bool c[N];
ll d[N];

void solv()
{
    cin >> n >> m;
    for (int x = 0; x < n; ++x)
    {
        for (int y = 0; y < n; ++y)
        {
            a[x][y] = INF;
        }
    }
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[x][y] = z;
    }

    for (int s = 0; s < n; ++s)
    {
        for (int x = 0; x < n; ++x)
        {
            d[x] = INF;
            c[x] = false;
        }
        d[s] = 0;
        for (int ii = 0; ii < n; ++ii)
        {
            int x = -1;
            for (int i = 0; i < n; ++i)
            {
                if (c[i])
                    continue;
                if (x == -1)
                    x = i;
                else if (d[i] < d[x])
                    x = i;
            }
            c[x] = true;

            for (int i = 0; i < n; ++i)
                aa[(i + d[x]) % n] = a[x][i];

            ll minu = INF;
            for (int h = 0; h < n; ++h)
            {
                ++minu;
                minu = min(minu, d[x] + aa[h]);
                d[h] = min(d[h], minu);
            }
            minu = INF;
            for (int h = n - 1; h >= 0; --h)
            {
                d[h] = min(d[h], minu + h);
                minu = min(minu, d[x] + aa[h] + n - h);
            }
        }
        for (int x = 0; x < n; ++x)
            cout << d[x] << ' ';
        cout << "\n";
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