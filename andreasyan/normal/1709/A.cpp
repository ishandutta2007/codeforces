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

void solv()
{
    int x;
    int a[4];
    cin >> x;
    for (int i = 1; i <= 3; ++i)
        cin >> a[i];

    for (int i = 0; i < 2; ++i)
    {
        if (!a[x])
        {
            cout << "NO\n";
            return;
        }
        else
        {
            int u = a[x];
            a[x] = 0;
            x = u;
        }
    }
    cout << "YES\n";
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