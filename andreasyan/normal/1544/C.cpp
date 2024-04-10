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
int a[104], b[104];

bool stg(int q)
{
    a[100] += q;
    b[0] += q;

    int u = (n + q) - (n + q) / 4;
    int sa = 0;
    for (int i = 100; i >= 0; --i)
    {
        if (a[i] >= u)
        {
            sa += u * i;
            break;
        }
        else
        {
            u -= a[i];
            sa += a[i] * i;
        }
    }

    u = (n + q) - (n + q) / 4;
    int sb = 0;
    for (int i = 100; i >= 0; --i)
    {
        if (b[i] >= u)
        {
            sb += u * i;
            break;
        }
        else
        {
            u -= b[i];
            sb += b[i] * i;
        }
    }

    a[100] -= q;
    b[0] -= q;
    return sa >= sb;
}

void solv()
{
    cin >> n;
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        b[x]++;
    }

    int l = 0, r = n * 10;
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