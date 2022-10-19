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
const int N = 18;

int l, r;
int a[(1 << N)];

int z;
int t[(1 << N) * N][2];

void solv()
{
    cin >> l >> r;
    for (int i = 1; i <= r - l + 1; ++i)
        cin >> a[i];

    z = 0;
    t[z][0] = t[z][1] = 0;

    for (int i = 1; i <= r - l + 1; ++i)
    {
        int pos = 0;
        for (int j = N - 1; j >= 0; --j)
        {
            int u = 0;
            if ((a[i] & (1 << j)))
                u = 1;

            if (!t[pos][u])
            {
                ++z;
                t[z][0] = t[z][1] = 0;
                t[pos][u] = z;
            }
            pos = t[pos][u];
        }
    }

    for (int ii = 1; ii <= r - l + 1; ++ii)
    {
        bool z = true;
        int x = (a[ii] ^ l);
        int pos = 0;
        for (int j = N - 1; j >= 0; --j)
        {
            int u = 0;
            if (((x ^ l) & (1 << j)))
                u = 1;
            if (t[pos][(u ^ 1)])
            {
                if ((l & (1 << j)))
                {
                    z = false;
                    break;
                }
            }
            if (!t[pos][u])
                break;
            pos = t[pos][u];
        }
        if (!z)
            continue;

        pos = 0;
        for (int j = N - 1; j >= 0; --j)
        {
            int u = 0;
            if (((x ^ r) & (1 << j)))
                u = 1;
            if (t[pos][(u ^ 1)])
            {
                if (!(r & (1 << j)))
                {
                    z = false;
                    break;
                }
            }
            if (!t[pos][u])
                break;
            pos = t[pos][u];
        }
        if (!z)
            continue;

        cout << x << "\n";
        /*for (int i = 1; i <= r - l + 1; ++i)
            cout << (a[i] ^ x) << ' ';
        cout << "\n";*/
        return;
    }
    assert(false);
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