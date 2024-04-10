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
const int N = 102, M = 2003;

int n;
int a[N];

bitset<N * M> u;

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int s = 0;
    for (int i = 1; i <= n; ++i)
        s += a[i];

    u[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        u = (u | (u << a[i]));
    }

    if (s % 2 == 0 && u[s / 2])
    {
        while (1)
        {
            for (int i = 1; i <= n; ++i)
            {
                if (a[i] % 2 == 1)
                {
                    cout << "1\n";
                    cout << i << "\n";
                    return;
                }
            }
            for (int i = 1; i <= n; ++i)
                a[i] /= 2;
        }
    }
    else
    {
        cout << "0\n";
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