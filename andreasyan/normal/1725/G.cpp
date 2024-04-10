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
    /*set<int> s;
    for (int i = 1; i <= 100; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            s.insert(i * i - j * j);
        }
    }
    for (auto it = s.begin(); it != s.end(); ++it)
        cout << *it << "\n";*/

    int n;
    cin >> n;
    if (n == 1)
        cout << "3\n";
    else if (n == 2)
        cout << "5\n";
    else
        cout << 7 + 4 * ((n - 3) / 3) + n % 3 << "\n";
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
    {
        solv();
    }
    return 0;
}