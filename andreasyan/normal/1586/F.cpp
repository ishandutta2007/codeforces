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
const int N = 1003;

int n, k;

int a[N][N];

void solv()
{
    cin >> n >> k;

    vector<vector<int> > v;
    for (int i = 1; i <= n; ++i)
    {
        v.push_back({i});
    }

    int ans = 0;
    while (sz(v) > 1)
    {
        ++ans;

        vector<vector<int> > nv;

        vector<vector<int> > vv;
        for (int i = 0; i < sz(v); ++i)
        {
            vv.push_back(v[i]);
            if (sz(vv) == k)
            {
                for (int i = 0; i < sz(vv); ++i)
                {
                    for (int ii = 0; ii < sz(vv[i]); ++ii)
                    {
                        for (int j = i + 1; j < sz(vv); ++j)
                        {
                            for (int jj = 0; jj < sz(vv[j]); ++jj)
                            {
                                a[vv[i][ii]][vv[j][jj]] = ans;
                            }
                        }
                    }
                }
                vector<int> u;
                for (int i = 0; i < sz(vv); ++i)
                    for (int ii = 0; ii < sz(vv[i]); ++ii)
                        u.push_back(vv[i][ii]);
                nv.push_back(u);

                vv.clear();
            }
        }
        if (!vv.empty())
        {
            for (int i = 0; i < sz(vv); ++i)
            {
                for (int ii = 0; ii < sz(vv[i]); ++ii)
                {
                    for (int j = i + 1; j < sz(vv); ++j)
                    {
                        for (int jj = 0; jj < sz(vv[j]); ++jj)
                        {
                            a[vv[i][ii]][vv[j][jj]] = ans;
                        }
                    }
                }
            }
            vector<int> u;
            for (int i = 0; i < sz(vv); ++i)
                for (int ii = 0; ii < sz(vv[i]); ++ii)
                    u.push_back(vv[i][ii]);
            nv.push_back(u);

            vv.clear();
        }
        v = nv;
    }

    cout << ans << "\n";
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            cout << a[i][j] << ' ';
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