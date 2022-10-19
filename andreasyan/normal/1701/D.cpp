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
const int N = 500005;

int n;
int b[N];

vector<pair<int, int> > v[N];

int a[N];
void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        v[i].clear();
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
    {
        int l = 1, r = n;
        int ur;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if ((i / m) >= b[i])
            {
                l = m + 1;
                ur = m;
            }
            else
                r = m - 1;
        }

        l = 1, r = n;
        int ul;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if ((i / m) <= b[i])
            {
                ul = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }

        v[ul].push_back(m_p(ur, i));
    }

    set<pair<int, int> > s;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < sz(v[i]); ++j)
        {
            s.insert(v[i][j]);
        }
        a[s.begin()->se] = i;
        s.erase(s.begin());
    }

    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
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