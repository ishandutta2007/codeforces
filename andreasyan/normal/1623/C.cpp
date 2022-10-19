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
int a[N];

int b[N];

bool stg(int x)
{
    for (int i = 1; i <= n; ++i)
        b[i] = 0;
    for (int i = n; i >= 1; --i)
    {
        if (a[i] + b[i] < x)
            return false;

        if (i > 2)
        {
            int d = min(a[i] + b[i] - x, a[i]) / 3;
            b[i - 1] += d;
            b[i - 2] += d * 2;
        }
    }
    return true;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int l = 1, r = 1000000000;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}