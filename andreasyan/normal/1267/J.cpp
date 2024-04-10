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
const int N = 2000006;

int n;
int a[N];
int q[N];
bool c[N];
int u[N];

void solv()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        q[i] = 0;
        c[i] = false;
    }

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        ++q[a[i]];
    for (int i = 1; i <= n; ++i)
        c[q[i]] = true;

    u[n + 1] = n + 1;
    for (int i = n; i >= 1; --i)
    {
        u[i] = u[i + 1];
        if (c[i])
            u[i] = i;
    }

    int s = 1;
    for (s = n; s >= 2; --s)
    {
        bool z = true;
        for (int i = s; i <= n; i += s)
        {
            if (u[i - s + 1] < i)
            {
                int qq = u[i - s + 1];
                if (s - (qq % s) > (qq + s - (qq % s)) / s)
                {
                    z = false;
                    break;
                }
            }
        }
        if (z)
            break;
    }

    int yans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (q[i] % s != 0)
            yans += (q[i] + s - (q[i] % s)) / s;
        else
            yans += q[i] / s;
    }

    cout << yans << "\n";
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