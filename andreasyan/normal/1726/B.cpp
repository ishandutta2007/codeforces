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

int n, m;

void solv()
{
    cin >> n >> m;

    if (m < n)
    {
        cout << "No\n";
        return;
    }

    if (n % 2 == 1)
    {
        cout << "Yes\n";
        for (int i = 1; i < n; ++i)
            cout << "1 ";
        cout << m - (n - 1) << "\n";
        return;
    }

    if (m % 2 == 0)
    {
        cout << "Yes\n";
        for (int i = 1; i < n - 1; ++i)
            cout << "1 ";
        cout << (m - (n - 2)) / 2 << ' ' << (m - (n - 2)) / 2 << "\n";
        return;
    }

    cout << "No\n";
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