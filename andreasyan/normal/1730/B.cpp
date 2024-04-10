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
int x[N];
int t[N];

int s;
bool stg(int d)
{
    int l = -1000000009;
    int r = 1000000009;
    for (int i = 1; i <= n; ++i)
    {
        if (t[i] > d)
            return false;
        l = max(l, x[i] - (d - t[i]));
        r = min(r, x[i] + (d - t[i]));
    }
    s = l;
    return (l <= r);
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    for (int i = 1; i <= n; ++i)
    {
        x[i] *= 2;
        t[i] *= 2;
    }

    int l = 0, r = 1000000009;
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

    assert(stg(ans));

    if (s % 2 == 0)
        cout << s / 2 << "\n";
    else
        cout << s / 2 << ".5\n";
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