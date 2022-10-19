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
const int m = 20;

int n;
int a[N], ca[N];;

int d[(1 << m)], b[(1 << m)];

vector<int> v[m];

vector<int> ans;

vector<int> yans;
void rec(int i)
{
    bool z = false;
    for (int j = 0; j < sz(v[i]); ++j)
    {
        int x = v[i][j];
        if (d[x] || b[x])
        {
            z = true;
            break;
        }
    }

    if (i == m - 1)
    {
        if (!z)
        {
            if (sz(yans) < sz(ans))
                ans = yans;
        }
        return;
    }

    if (!z)
    {
        rec(i + 1);
        return;
    }

    yans.push_back((1 << i));
    for (int j = 0; j < sz(v[i]); ++j)
    {
        int x = v[i][j];
        d[x - (1 << i)] += d[x];
        b[x + (1 << i)] += b[x];
    }
    rec(i + 1);
    for (int j = 0; j < sz(v[i]); ++j)
    {
        int x = v[i][j];
        d[x - (1 << i)] -= d[x];
        b[x + (1 << i)] -= b[x];
    }
    yans.pop_back();

    yans.push_back(-(1 << i));
    for (int j = 0; j < sz(v[i]); ++j)
    {
        int x = v[i][j];
        d[x + (1 << i)] += d[x];
        b[x - (1 << i)] += b[x];
    }
    rec(i + 1);
    for (int j = 0; j < sz(v[i]); ++j)
    {
        int x = v[i][j];
        d[x + (1 << i)] -= d[x];
        b[x - (1 << i)] -= b[x];
    }
    yans.pop_back();
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > 0)
            ++d[a[i]];
        else
            ++b[-a[i]];
    }

    for (int x = 0; x < (1 << m); ++x)
    {
        for (int i = 0; i < m; ++i)
        {
            if ((x & (1 << i)))
            {
                v[i].push_back(x);
                break;
            }
        }
    }

    for (int i = 0; i <= m; ++i)
    {
        ans.push_back(0);
    }
    rec(0);

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i] << ' ';
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