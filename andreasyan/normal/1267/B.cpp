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

int n;
char a[N];

void solv()
{
    cin >> a;
    n = strlen(a);

    vector<pair<char, int> > v;
    v.push_back(m_p(a[0], 1));
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i - 1])
            ++v.back().se;
        else
            v.push_back(m_p(a[i], 1));
    }

    if (sz(v) % 2 == 0)
    {
        cout << "0\n";
        return;
    }

    for (int i = 0; i < sz(v) / 2; ++i)
    {
        if (v[i].fi != v[sz(v) - i - 1].fi)
        {
            cout << "0\n";
            return;
        }
        if (v[i].se + v[sz(v) - i - 1].se < 3)
        {
            cout << "0\n";
            return;
        }
    }

    if (v[sz(v) / 2].se + 1 >= 3)
    {
        cout << v[sz(v) / 2].se + 1 << "\n";
    }
    else
    {
        cout << "0\n";
    }
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