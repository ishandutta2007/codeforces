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
const int N = 200005;

int n;
int a[3][N];

int l[3][N], r[3][N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    }

    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j])
                ++a[i][j];
        }
    }

    for (int i = 1; i <= 2; ++i)
    {
        l[i][n] = r[i][n] = a[i][n];
        for (int j = n - 1; j >= 1; --j)
        {
            l[i][j] = max(l[i][j + 1] + 1, a[i][j]);
            r[i][j] = max(r[i][j + 1], a[i][j] + n - j);
        }
    }

    int tans = 2000000009;
    int ans = 0;
    int q = 2 * n;
    for (int j = 1; j <= n; ++j)
    {
        vector<int> u;
        u.push_back(0);
        if (j % 2 == 1)
        {
            u.push_back(1);
            u.push_back(2);
        }
        else
        {
            u.push_back(2);
            u.push_back(1);
        }

        {
            --q;
            ans = max(ans, a[u[1]][j] + q);

            int yans = ans;
            yans = max(yans, r[u[1]][j + 1] + n - j + 1);
            yans = max(yans, l[u[2]][j]);

            if (j != n)
                tans = min(tans, yans);
        }
        {
            --q;
            ans = max(ans, a[u[2]][j] + q);

            int yans = ans;
            yans = max(yans, r[u[2]][j + 1] + n - j);
            yans = max(yans, l[u[1]][j + 1]);

            if (j != n)
                tans = min(tans, yans);
        }
    }
    tans = min(tans, ans);

    cout << tans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}