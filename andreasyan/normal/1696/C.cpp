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
const int N = 200005;

int n, m;
int a[N];
int k;
int b[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> k;
    for (int i = 1; i <= k; ++i)
        cin >> b[i];

    vector<pair<int, ll> > va;
    for (int i = 1; i <= n; ++i)
    {
        int q = 1;
        while (a[i] % m == 0)
        {
            a[i] /= m;
            q *= m;
        }

        if (va.empty() || va.back().fi != a[i])
            va.push_back(m_p(a[i], q));
        else
            va.back().se += q;
    }

    vector<pair<int, ll> > vb;
    for (int i = 1; i <= k; ++i)
    {
        int q = 1;
        while (b[i] % m == 0)
        {
            b[i] /= m;
            q *= m;
        }

        if (vb.empty() || vb.back().fi != b[i])
            vb.push_back(m_p(b[i], q));
        else
            vb.back().se += q;
    }

    if (va == vb)
        cout << "Yes\n";
    else
        cout << "No\n";
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