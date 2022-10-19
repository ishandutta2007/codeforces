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
int s[N];

int a[N];
bool stg(int i)
{
    if (i == 1 || i == n)
        return false;
    return (a[i - 1] < a[i] && a[i] > a[i + 1]);
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];

    for (int i = 1; i <= n; ++i)
        a[i] = s[i];

    for (int i = 2; i < n; ++i)
    {
        if (stg(i - 1) && stg(i + 1))
        {
            a[i] = max(a[i - 1], a[i + 1]);
        }
    }
    for (int i = 2; i < n; ++i)
    {
        if (stg(i))
        {
            a[i] = max(a[i - 1], a[i + 1]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != s[i])
            ++ans;
    }

    cout << ans << "\n";
    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}