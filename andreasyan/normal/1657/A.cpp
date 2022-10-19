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
    int x, y;
    cin >> x >> y;

    if (x == 0 && y == 0)
    {
        cout << "0\n";
        return;
    }
    for (int z = sqrt(x * x + y * y) - 10; z <= sqrt(x * x + y * y) + 10; ++z)
    {
        if (z * z == x * x + y * y)
        {
            cout << "1\n";
            return;
        }
    }
    cout << "2\n";
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