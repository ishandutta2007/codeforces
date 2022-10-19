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
const int N = 500005;

int n;
char s[N];
int x[N], y[N];

int ansx, ansy;
bool stg(int d)
{
    int lx = 0, rx = N * 20;
    int ly = 0, ry = N * 20;

    for (int i = 1; i <= n; ++i)
    {
        lx = max(lx, x[i] - d);
        rx = min(rx, x[i] + d);
        ly = max(ly, y[i] - d);
        ry = min(ry, y[i] + d);
    }

    if (lx > rx)
        return false;
    if (ly > ry)
        return false;

    int l = lx - ry;
    int r = rx - ly;
    for (int i = 1; i <= n; ++i)
    {
        int l1 = (x[i] - d) - y[i];
        int r1 = (x[i] + d) - y[i];
        l = max(l, l1);
        r = min(r, r1);
    }

    if (l > r)
        return false;

    ansx = rx;
    ansy = ansx - l;
    if (ly <= ansy && ansy <= ry)
        return true;

    ansy = ry;
    ansx = ansy + l;
    assert(lx <= ansx && ansx <= rx);

    return true;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        int m = strlen(s);
        for (int j = 0; j < m; ++j)
        {
            if (s[j] == 'B')
                ++x[i];
            else
                ++y[i];
        }
    }

    int l = 0, r = N * 4;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    cout << ans << "\n";
    for (int i = 0; i < ansx; ++i)
        cout << 'B';
    for (int i = 0; i < ansy; ++i)
        cout << 'N';
    cout << "\n";
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