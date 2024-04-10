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
const int N = 11;

int n;
char a[N];

int ans;

int xx;
int x;
void rec(int i)
{
    if (i == n)
    {
        if (x % 25 == 0)
            ++ans;
        return;
    }

    if ('0' <= a[i] && a[i] <= '9')
    {
        if (i == 0 && a[i] == '0' && n > 1)
            return;
        x = (x * 10 + (a[i] - '0'));
        rec(i + 1);
        x /= 10;
        return;
    }
    if (a[i] == '_')
    {
        for (int u = 0; u < 10; ++u)
        {
            if (i == 0 && u == 0 && n > 1)
                continue;
            x = (x * 10 + u);
            rec(i + 1);
            x /= 10;
        }
        return;
    }
    if (i == 0 && xx == 0 && n > 1)
        return;
    x = (x * 10 + xx);
    rec(i + 1);
    x /= 10;
}

void solv()
{
    cin >> a;
    n = strlen(a);

    bool z = false;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'X')
            z = true;
    }

    if (!z)
    {
        rec(0);
    }
    else
    {
        for (xx = 0; xx < 10; ++xx)
        {
            rec(0);
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

    int tt = 1;
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}