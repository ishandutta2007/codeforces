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

int n;
char a[N];

int u[N];

char h[N];
int e[N];
string ans[N];

void dz(string& ans)
{
    if (sz(ans) <= 10)
        return;

    string yans = "";
    for (int i = 0; i < 5; ++i)
        yans += ans[i];
    yans += "...";
    for (int i = sz(ans) - 2; i < sz(ans); ++i)
        yans += ans[i];
    ans = yans;
}

void solv()
{
    cin >> (a + 1);
    for (n = 1; a[n]; ++n){}
    --n;

    for (int i = n; i >= 1; --i)
    {
        if (a[i] == a[i + 1])
            u[i] = u[i + 1];
        else
            u[i] = i;

        if (e[u[i] + 1] == 0)
        {
            e[i] = (u[i] - i + 1) % 2;
            if (e[i])
                ans[i] += a[i];
            h[i] = 0;
        }
        else
        {
            if (ans[u[i] + 1][0] < a[i] || (ans[u[i] + 1][0] == a[i] && h[u[i]] < ans[u[i] + 1][0]))
            {
                e[i] = (u[i] - i + 1) % 2 + e[u[i] + 1];

                ans[i] = ans[u[i] + 1];
                reverse(all(ans[i]));
                if ((u[i] - i + 1) % 2)
                    ans[i] += a[i];
                reverse(all(ans[i]));
                dz(ans[i]);

                if ((u[i] - i + 1) % 2 && a[i] != ans[u[i] + 1][0])
                    h[i] = ans[u[i] + 1][0];
                else
                    h[i] = h[u[i] + 1];
            }
            else
            {
                e[i] = u[i] - i + 1 + e[u[i] + 1];

                ans[i] = ans[u[i] + 1];
                reverse(all(ans[i]));
                for (int j = 0; j < min(10, u[i] - i + 1); ++j)
                    ans[i] += a[i];
                reverse(all(ans[i]));
                dz(ans[i]);

                if (a[i] != ans[u[i] + 1][0])
                    h[i] = ans[u[i] + 1][0];
                else
                    h[i] = h[u[i] + 1];
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << e[i] << ' ' << ans[i] << "\n";
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