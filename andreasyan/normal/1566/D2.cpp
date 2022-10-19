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
const int N = 303;

int n, m;
int a[N * N];
int b[N * N];

int t[N][N];
void ubd(int x, int y)
{
    while (y <= m)
    {
        t[x][y]++;
        y += (y & (-y));
    }
}
int qry(int x, int y)
{
    int ans = 0;
    while (y)
    {
        ans += t[x][y];
        y -= (y & (-y));
    }
    return ans;
}

void solv()
{
    memset(t, 0, sizeof t);

    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i)
        cin >> a[i];

    for (int i = 1; i <= n * m; ++i)
        b[i] = a[i];
    sort(b + 1, b + n * m + 1);

    map<int, vector<int> > v;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j >= 1; --j)
        {
            v[b[(i - 1) * m + j]].push_back((i - 1) * m + j);
        }
    }

    for (auto it = v.begin(); it != v.end(); ++it)
        reverse(all(it->se));

    int ans = 0;
    for (int i = 1; i <= n * m; ++i)
    {
        int x = v[a[i]].back();
        v[a[i]].pop_back();
        ans += qry((x - 1) / m + 1, (x - 1) % m + 1);
        ubd((x - 1) / m + 1, (x - 1) % m + 1);
    }

    cout << ans << "\n";
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
        solv();
    return 0;
}