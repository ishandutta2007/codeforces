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
int x[N];
int y[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];

    for (int i = 1; i <= n; ++i)
        y[i] = 0;

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < 30; ++j)
        {
            int xx = (x[i - 1] ^ y[i - 1]);
            if ((xx & (1 << j)) > (x[i] & (1 << j)))
                y[i] ^= (1 << j);
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << y[i] << ' ';
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