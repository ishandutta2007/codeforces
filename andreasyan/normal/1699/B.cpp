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
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i += 2)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << (((i / 2) % 2) ^ (((j + 1) / 2) % 2)) << ' ';
        }
        cout << "\n";
        for (int j = 0; j < m; ++j)
        {
            cout << (1 ^ ((i / 2) % 2) ^ (((j + 1) / 2) % 2)) << ' ';
        }
        cout << "\n";
    }
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