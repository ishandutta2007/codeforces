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
const int N = 10004;

int n;
int a[N];

int p[N], s[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    p[1] = a[1];
    for (int i = 2; i <= n; ++i)
        p[i] = max(p[i - 1], a[i]);

    s[n] = a[n];
    for (int i = n - 1; i >= 1; --i)
        s[i] = min(s[i + 1], a[i]);

    for (int i = 1; i < n; ++i)
    {
        if (p[i] > s[i + 1])
        {
            cout << "YES\n";
            return;
        }
    }

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