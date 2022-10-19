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
int a[N];

vector<int> v[3];

int ans[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        v[a[i] % 3].push_back(i);
    }

    if (sz(v[0]) <= n / 2)
    {
        cout << "0\n";
    }
    else
    {
        cout << "2\n";
    }
    int q = n / 2;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < sz(v[i]); ++j)
        {
            if (q)
            {
                --q;
                ans[v[i][j]] = 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i];
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}