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
int a[N];

void solv()
{
    cin >> n;

    int k = 0;
    a[++k] = n / 2 + 1;
    for (int i = 1; i <= (n - 2) / 2; ++i)
        a[++k] = i;
    for (int i = n / 2 + 2; i <= n; ++i)
        a[++k] = i;
    a[++k] = a[1] - 1;

    ll ans = 0;
    for (int i = n / 2; i < n - 1; ++i)
        ans += (i * 2LL * i);
    ans += (n - 1) * 1LL * (n - 1);
    if (n % 2 == 1)
        ans -= (n / 2) * 1LL * (n / 2);
    cout << ans << "\n";
    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    cout << "\n";
    cout << n - 1 << "\n";
    while (1)
    {
        if (a[1] == 1 && a[n] == n)
            break;
        if (a[1] != 1)
        {
            cout << a[1] << ' ' << 1 << "\n";
            swap(a[a[1]], a[1]);
        }
        if (a[n] != n)
        {
            cout << a[n] << ' ' << n << "\n";
            swap(a[a[n]], a[n]);
        }
    }
}

int ans;
void rec(int yans)
{
    bool z = false;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != i)
        {
            z = true;
            int u = a[i];
            swap(a[i], a[u]);
            rec(yans + (i - u) * (i - u));
            swap(a[i], a[u]);
        }
    }
    if (!z)
        ans = max(ans, yans);
}

int b[13];
void solv0()
{
    ans = 0;
    for (int i = 1; i <= n; ++i)
        a[i] = i;
    do
    {
        int sans = ans;
        rec(0);
        if (sans != ans)
        {
            for (int i = 1; i <= n; ++i)
                b[i] = a[i];
        }
    } while (next_permutation(a + 1, a + n + 1));
    cout << ans << "\n";
    for (int i = 1; i <= n; ++i)
        cout << b[i] << ' ';
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
    //scanf("%d", &tt);
    cin >> tt;
    while (tt--)
    {
        solv();
        //solv0();
    }
    return 0;
}