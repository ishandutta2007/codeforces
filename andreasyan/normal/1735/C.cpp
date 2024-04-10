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
char a[N];

int u[30], ru[30];

void solv()
{
    for (int i = 1; i <= 26; ++i)
        u[i] = ru[i] = 0;

    cin >> n;
    cin >> (a + 1);
    for (int i = 1; i <= n; ++i)
        a[i] = a[i] - 'a' + 1;
    for (int i = 1; i <= n; ++i)
    {
        if (!ru[a[i]])
        {
            int y = a[i];
            while (u[y])
                y = u[y];
            for (int x = 1; x <= 26; ++x)
            {
                if (u[x] || x == y)
                    continue;
                u[x] = a[i];
                ru[a[i]] = x;
                break;
            }
            if (!ru[a[i]])
            {
                u[y] = a[i];
                ru[a[i]] = y;
            }
        }
        cout << (char)(ru[a[i]] - 1 + 'a');
    }
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