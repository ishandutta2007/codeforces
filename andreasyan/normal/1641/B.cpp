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
const int N = 505;

int n;
int a[N];

int b[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    map<int, int> mp;
    for (int i = 1; i <= n; ++i)
        mp[a[i]]++;

    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        if (it->se % 2 == 1)
        {
            cout << "-1\n";
            return;
        }
    }

    int q = 0;
    vector<pair<int, int> > ans;
    vector<int> t;
    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(a[i]);
    while (!v.empty())
    {
        for (int i = 1; i < sz(v); ++i)
        {
            if (v[i] == v[0])
            {
                t.push_back(i * 2);
                for (int j = 1; j < i; ++j)
                {
                    ans.push_back(m_p(q + i + j, v[j]));
                }

                q += i * 2;

                vector<int> vv;
                for (int j = 1; j < sz(v); ++j)
                {
                    if (j == i)
                        continue;
                    vv.push_back(v[j]);
                }
                v = vv;
                for (int j = 0; j < i - 1; ++j)
                {
                    v[j] = vv[i - 2 - j];
                }
                break;
            }
        }
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i].fi << ' ' << ans[i].se << "\n";
    cout << sz(t) << "\n";
    for (int i = 0; i < sz(t); ++i)
        cout << t[i] << ' ';
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