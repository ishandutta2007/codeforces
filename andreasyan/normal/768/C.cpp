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
const int N = (1 << 10);

int n, k, x;
int a[N];

int na[N];

void solv()
{
    cin >> n >> k >> x;
    while (n--)
    {
        int x;
        cin >> x;
        ++a[x];
    }

    while (k--)
    {
        memset(na, 0, sizeof na);

        int q = 0;
        for (int i = 0; i < N; ++i)
        {
            na[(i ^ x)] += a[i] / 2;
            na[i] += a[i] / 2;
            if (q % 2 == 0)
                na[(i ^ x)] += (a[i] % 2);
            else
                na[i] += (a[i] % 2);

            q += a[i];
        }

        memcpy(a, na, sizeof na);
    }

    for (int i = N - 1; i >= 0; --i)
    {
        if (a[i])
        {
            cout << i << ' ';
            break;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        if (a[i])
        {
            cout << i << "\n";
            break;
        }
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