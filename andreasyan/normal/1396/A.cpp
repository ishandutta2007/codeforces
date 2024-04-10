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
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    if (n == 1)
    {
        cout << "1 1\n";
        cout << "0\n";
        cout << "1 1\n";
        cout << "0\n";
        cout << "1 1\n";
        cout << -a[1] << "\n";
        return;
    }

    cout << "1 " << n << "\n";
    for (int i = 1; i <= n; ++i)
    {
        if (i < n)
            cout << -a[i] * 1LL * n << ' ';
        else
            cout << "0\n";
    }

    cout << "1 " << n - 1 << "\n";
    for (int i = 1; i < n; ++i)
    {
        cout << a[i] * 1LL * (n - 1) << ' ';
    }
    cout << "\n";

    cout << n << ' ' << n << "\n";
    cout << -a[n] << "\n";
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