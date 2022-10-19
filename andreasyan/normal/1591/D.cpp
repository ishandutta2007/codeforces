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
int a[N];

int t[N];
void ubd(int x)
{
    while (x <= n)
    {
        t[x]++;
        x += (x & (-x));
    }
}

int qry(int x)
{
    int ans = 0;
    while (x)
    {
        ans += t[x];
        x -= (x & (-x));
    }
    return ans;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        t[i] = 0;

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += ((i - 1) - qry(a[i]));
        ans %= 2;
        ubd(a[i]);
    }

    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i + 1])
        {
            cout << "YES\n";
            return;
        }
    }

    if (ans == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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