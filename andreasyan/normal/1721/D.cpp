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
int a[N], b[N];

int u;
int j;
bool soa(int x, int y)
{
    return (x & (u | (1 << j))) < (y & (u | (1 << j)));
}
bool sob(int x, int y)
{
    return ((x & (u | (1 << j))) ^ (u | (1 << j))) < ((y & (u | (1 << j))) ^ (u | (1 << j)));
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    u = 0;
    for (j = 29; j >= 0; --j)
    {
        sort(a + 1, a + n + 1, soa);
        sort(b + 1, b + n + 1, sob);

        bool z = true;
        for (int i = 1; i <= n; ++i)
        {
            if ((a[i] & (1 << j)) == (b[i] & (1 << j)))
            {
                z = false;
                break;
            }
        }

        if (z)
            u |= (1 << j);
    }

    cout << u << "\n";
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