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

int n, qq;
char a[N];

void solv()
{
    cin >> n >> qq;
    cin >> (a + 1);

    int ans = 0;
    for (int i = 1; i <= n - 2; ++i)
    {
        if (a[i] == 'a' && a[i + 1] == 'b' && a[i + 2] == 'c')
            ++ans;
    }
    a[n + 1] = a[n + 2] = 'd';

    while (qq--)
    {
        int x;
        char y;
        cin >> x >> y;

        for (int i = max(1, x - 2); i <= x; ++i)
        {
            if (a[i] == 'a' && a[i + 1] == 'b' && a[i + 2] == 'c')
                --ans;
        }

        a[x] = y;

        for (int i = max(1, x - 2); i <= x; ++i)
        {
            if (a[i] == 'a' && a[i + 1] == 'b' && a[i + 2] == 'c')
                ++ans;
        }

        cout << ans << "\n";
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}