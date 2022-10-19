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
const int N = 103;

int n;
int h[N];

int ans[N];

void solv()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cout << "? ";
        for (int j = 1; j <= n; ++j)
        {
            if (j != i)
                cout << "1 ";
            else
                cout << "2 ";
        }
        cout << endl;

        int k;
        cin >> k;
        if (k != 0 && k < i)
        {
            h[i] = k;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << "? ";
        for (int j = 1; j <= n; ++j)
        {
            if (j != i)
                cout << "2 ";
            else
                cout << "1 ";
        }
        cout << endl;

        int k;
        cin >> k;
        if (k < i)
        {
            h[k] = i;
        }
    }

    int u = 0;
    for (int i = 1; i <= n; ++i)
    {
        u = h[u];
        ans[u] = i;
    }

    cout << "! ";
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
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