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
const int N = 10004;

int n, m;
int e[N], k[N];

void solv()
{
    cin >> n >> m;
    for (int i = 2; i <= n; ++i)
    {
        cout << "and 1 " << i << endl;
        cin >> e[i];
    }
    for (int i = 2; i <= n; ++i)
    {
        cout << "or 1 " << i << endl;
        cin >> k[i];
    }

    int e23;
    cout << "and 2 3" << endl;
    cin >> e23;
    int k23;
    cout << "or 2 3" << endl;
    cin >> k23;

    int x = 0;
    for (int j = 0; j < 30; ++j)
    {
        bool z = false;
        for (int i = 2; i <= n; ++i)
        {
            if ((e[i] & (1 << j)) == (k[i] & (1 << j)))
            {
                x += (e[i] & (1 << j));
                z = true;
                break;
            }
        }
        if (!z)
        {
            x += (1 << j) - (e23 & (1 << j));
        }
    }

    int ans = 0;

    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);
    for (int j = 29; j >= 0; --j)
    {
        vector<int> u[2];
        for (int i = 0; i < sz(v); ++i)
        {
            if ((e[v[i]] & (1 << j)) == (k[v[i]] & (1 << j)))
                u[0].push_back(v[i]);
            else
                u[1].push_back(v[i]);
        }

        if ((x & (1 << j)))
            swap(u[0], u[1]);

        if (m <= sz(u[0]))
        {
            v = u[0];
        }
        else
        {
            ans += (1 << j);
            m -= sz(u[0]);
            v = u[1];
        }
    }
    cout << "finish " << ans << endl;
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
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