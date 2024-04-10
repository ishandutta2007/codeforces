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

int n, qq;
int a[N];

void solv()
{
    cin >> n >> qq;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> b;
    int x = n;
    for (int i = 2; i < n; ++i)
    {
        if (x % i == 0)
        {
            b.push_back(n / i);
            while (x % i == 0)
            {
                x /= i;
            }
        }
    }
    if (b.empty())
        b.push_back(1);

    vector<vector<ll> > v;
    v.assign(sz(b), {});
    for (int j = 0; j < sz(b); ++j)
        v[j].assign(b[j], 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < sz(b); ++j)
        {
            v[j][(i % b[j])] += a[i] * 1LL * b[j];
        }
    }

    multiset<ll> s;
    for (int j = 0; j < sz(b); ++j)
    {
        for (int i = 0; i < b[j]; ++i)
            s.insert(v[j][i]);
    }
    cout << *(--s.end()) << "\n";
    while (qq--)
    {
        int i, x;
        cin >> i >> x;
        --i;

        int t = x - a[i];
        a[i] = x;

        for (int j = 0; j < sz(b); ++j)
        {
            s.erase(s.find(v[j][(i % b[j])]));
            v[j][(i % b[j])] += t * 1LL * b[j];
            s.insert(v[j][(i % b[j])]);
        }

        cout << *(--s.end()) << "\n";
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}