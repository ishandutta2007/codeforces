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
const int N = 100005, S = 333;

int n;
int a[N];

vector<pair<int, int> > v[N * 2];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int ans = 0;
    for (int d = -S; d <= S; ++d)
    {
        vector<int> v;
        for (int i = 1; i <= n; ++i)
        {
            v.push_back(a[i] - d * i);
        }
        sort(all(v));
        int q = 0;
        for (int i = 0; i < sz(v); ++i)
        {
            if (!i || v[i] != v[i - 1])
            {
                ans = max(ans, q);
                q = 1;
            }
            else
                ++q;
        }
        ans = max(ans, q);
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i - 1; j >= max(1, i - S); --j)
        {
            int x = (a[i] - a[j]) / (i - j);
            if (x * (i - j) == (a[i] - a[j]))
            {
                if (v[x + N].empty() || v[x + N].back().fi != i)
                    v[x + N].push_back(m_p(i, j));
            }
        }
    }

    for (int i = 0; i < N * 2; ++i)
    {
        if (-S <= i - N && i - N <= S)
            continue;
        int q = 0;
        for (int j = 0; j < sz(v[i]); ++j)
        {
            if (!j || v[i][j].se != v[i][j - 1].fi)
            {
                ans = max(ans, q);
                q = 2;
            }
            else
                ++q;
        }
        ans = max(ans, q);
    }

    cout << n - ans << "\n";
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