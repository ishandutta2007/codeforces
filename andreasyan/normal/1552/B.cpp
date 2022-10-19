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
const int N = 50004;

int n;
int a[N][5];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 5; ++j)
            cin >> a[i][j];
    }

    int x = 1;
    for (int i = 2; i <= n; ++i)
    {
        int q = 0;
        for (int j = 0; j < 5; ++j)
        {
            if (a[x][j] < a[i][j])
                ++q;
        }
        if (q < 3)
            x = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (x == i)
            continue;
        int q = 0;
        for (int j = 0; j < 5; ++j)
        {
            if (a[x][j] < a[i][j])
                ++q;
        }
        if (q < 3)
        {
            cout << "-1\n";
            return;
        }
    }

    cout << x << "\n";
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