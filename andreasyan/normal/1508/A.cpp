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
const int N = 300005;

int n;
char a[3][N];

char ans[N];
bool solv()
{
    cin >> n;
    for (int i = 0; i < 3; ++i)
    {
        cin >> a[i];
    }

    int q[3][2] = {};
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < n * 2; ++j)
        {
            q[i][a[i][j] - '0']++;
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = i + 1; j < 3; ++j)
        {
            if (max(q[i][0], q[j][0]) + q[i][1] + q[j][1] <= n * 3)
            {
                int k = 0;
                int ii = 0;
                int jj = 0;
                while (1)
                {
                    if (ii == n * 2 && jj == n * 2)
                    {
                        ans[k] = 0;
                        break;
                    }
                    if (ii == n * 2)
                    {
                        ans[k++] = a[j][jj];
                        ++jj;
                        continue;
                    }
                    if (jj == n * 2)
                    {
                        ans[k++] = a[i][ii];
                        ++ii;
                        continue;
                    }
                    if (a[i][ii] == '0' && a[j][jj] == '0')
                    {
                        ans[k++] = '0';
                        ++ii;
                        ++jj;
                        continue;
                    }
                    ans[k++] = '1';
                    if (a[i][ii] == '1')
                        ++ii;
                    if (a[j][jj] == '1')
                        ++jj;
                }
                cout << ans << "\n";
                return true;
            }
            if (max(q[i][1], q[j][1]) + q[i][0] + q[j][0] <= n * 3)
            {
                int k = 0;
                int ii = 0;
                int jj = 0;
                while (1)
                {
                    if (ii == n * 2 && jj == n * 2)
                    {
                        ans[k] = 0;
                        break;
                    }
                    if (ii == n * 2)
                    {
                        ans[k++] = a[j][jj];
                        ++jj;
                        continue;
                    }
                    if (jj == n * 2)
                    {
                        ans[k++] = a[i][ii];
                        ++ii;
                        continue;
                    }
                    if (a[i][ii] == '1' && a[j][jj] == '1')
                    {
                        ans[k++] = '1';
                        ++ii;
                        ++jj;
                        continue;
                    }
                    ans[k++] = '0';
                    if (a[i][ii] == '0')
                        ++ii;
                    if (a[j][jj] == '0')
                        ++jj;
                }
                cout << ans << "\n";
                return true;
            }
        }
    }
    return false;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 10000;
    cin >> tt;
    while (tt--)
    {
        solv();
        continue;
        n = rnf() % 10 + 1;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 2 * n; ++j)
            {
                a[i][j] = rnf() % 2 + '0';
            }
        }
        if (!solv())
        {
            cout << a[0] << "\n" << a[1] << "\n" << a[2] << "\n";
            return 0;
        }
    }
    return 0;
}