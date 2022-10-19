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
const int N = 300005;

int n, m;
pair<int, char> a[N];

int p[N];
bool so(int x, int y)
{
    return a[x] < a[y];
}

int ans[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].fi;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].se;

    for (int i = 1; i <= n; ++i)
        p[i] = i;
    sort(p + 1, p + n + 1, so);
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i)
        ans[i] = -1;

    vector<pair<int, int> > v;
    stack<int> s[2];
    for (int i = 1; i <= n; ++i)
    {
        int z = a[i].fi % 2;
        if (a[i].se == 'R')
        {
            s[z].push(i);
        }
        else
        {
            if (!s[z].empty())
            {
                v.push_back(m_p(i, s[z].top()));
                s[z].pop();
            }
            else
            {
                s[z].push(i);
            }
        }
    }

    for (int z = 0; z < 2; ++z)
    {
        while (sz(s[z]) >= 2)
        {
            int x = s[z].top();
            s[z].pop();
            int y = s[z].top();
            s[z].pop();
            v.push_back(m_p(x, y));
        }
    }

    for (int i = 0; i < v.size(); ++i)
    {
        int x = v[i].fi;
        int y = v[i].se;

        if (a[x].fi > a[y].fi)
            swap(x, y);

        int d = 0;
        {
            if (a[x].se == 'R' && a[y].se == 'L')
            {
                d = abs(a[x].fi - a[y].fi);
            }
            else if (a[x].se == 'L' && a[y].se == 'L')
            {
                d = 2 * a[x].fi + abs(a[x].fi - a[y].fi);
            }
            else if (a[x].se == 'R' && a[y].se == 'R')
            {
                d = 2 * (m - a[y].fi) + abs(a[x].fi - a[y].fi);
            }
            else
            {
                d = m * 2 - abs(a[x].fi - a[y].fi);
            }
        }
        ans[p[x]] = ans[p[y]] = d / 2;
    }

    for (int i = 1; i <= n; ++i)
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}