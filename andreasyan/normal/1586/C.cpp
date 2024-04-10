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
const int N = 1000006;

int n, m;
char** a;

int p[N];

void solv()
{
    cin >> n >> m;
    a = new char*[n + 5];
    for (int i = 0; i < n + 5; ++i)
        a[i] = new char[m + 5];

    for (int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);

    for (int j = 1; j < m; ++j)
    {
        bool z = false;
        for (int i = 2; i <= n; ++i)
        {
            if (a[i][j] == 'X' && a[i - 1][j + 1] == 'X')
            {
                z = true;
                break;
            }
        }
        p[j] = p[j - 1] + z;
    }

    int qq;
    cin >> qq;
    while (qq--)
    {
        int l, r;
        cin >> l >> r;
        if (p[r - 1] - p[l - 1] == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
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