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
const int N = 200005, M = 2500006;

int n;
int a[N];

vector<int> v[M];
pair<int, int> u[M * 2];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        v[a[i]].push_back(i);
    }

    for (int i = 0; i < M; ++i)
    {
        if (sz(v[i]) >= 4)
        {
            cout << "YES\n";
            cout << v[i][0] << ' ' << v[i][1] << ' ' << v[i][2] << ' ' << v[i][3] << "\n";
            return;
        }
    }

    int j = -1;
    for (int i = 0; i < M; ++i)
    {
        if (sz(v[i]) >= 2)
        {
            if (j == -1)
                j = i;
            else
            {
                cout << "YES\n";
                cout << v[i][0] << ' ' << v[j][0] << ' ' << v[i][1] << ' ' << v[j][1] << "\n";
                return;
            }
        }
    }

    if (j != -1)
    {
        for (int k = 0; k < sz(v[j]) - 1; ++k)
            a[v[j][k]] = -1;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == -1)
            continue;
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[j] == -1)
                continue;
            if (u[a[i] + a[j]].fi)
            {
                cout << "YES\n";
                cout << u[a[i] + a[j]].fi << ' ' << u[a[i] + a[j]].se << ' ' << i << ' ' << j << "\n";
                return;
            }
            u[a[i] + a[j]] = m_p(i, j);
        }
    }
    if (j != -1)
    {
        if (u[j + j].fi)
        {
            cout << "YES\n";
            cout << u[j + j].fi << ' ' << u[j + j].se << ' ' << v[j][0] << ' ' << v[j][1] << "\n";
            return;
        }
    }

    cout << "NO\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}