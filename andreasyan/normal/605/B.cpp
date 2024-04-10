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

struct ban
{
    int i;
    int d, z;
};
bool operator<(const ban& a, const ban& b)
{
    if (a.d < b.d)
        return true;
    if (a.d > b.d)
        return false;
    return a.z > b.z;
}

int n, m;
ban a[N];

int ansx[N], ansy[N];

int t[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        a[i].i = i;
        cin >> a[i].d >> a[i].z;
    }

    sort(a + 1, a + m + 1);

    int u = 1;
    int j = 1;
    for (int i = 1; i <= m; ++i)
    {
        if (a[i].z == 1)
        {
            ++u;
            ansx[a[i].i] = u - 1;
            ansy[a[i].i] = u;
            t[u] = u - 2;
        }
        else
        {
            while (j < u && t[j] == 0)
                ++j;
            if (t[j] == 0)
            {
                cout << "-1\n";
                return;
            }
            ansx[a[i].i] = t[j];
            ansy[a[i].i] = j;
            --t[j];
        }
    }

    for (int i = 1; i <= m; ++i)
        cout << ansx[i] << ' ' << ansy[i] << "\n";
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