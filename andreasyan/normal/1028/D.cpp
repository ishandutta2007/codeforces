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
const int N = 500005, M = 1000000007;

int n;
string ty[N];
int a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> ty[i] >> a[i];

    set<int> l, m, r;
    l.insert(-M);
    r.insert(M);
    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (ty[i] == "ADD")
        {
            if (a[i] < *(--l.end()))
                l.insert(a[i]);
            else if (a[i] > *r.begin())
                r.insert(a[i]);
            else
                m.insert(a[i]);
        }
        else
        {
            if (l.find(a[i]) != l.end())
            {
                if (a[i] != *(--l.end()))
                {
                    cout << "0\n";
                    return;
                }
                l.erase(a[i]);

                for (auto it = m.begin(); it != m.end(); ++it)
                    r.insert(*it);
                m.clear();
            }
            else if (r.find(a[i]) != r.end())
            {
                if (a[i] != *r.begin())
                {
                    cout << "0\n";
                    return;
                }
                r.erase(a[i]);

                for (auto it = m.begin(); it != m.end(); ++it)
                    l.insert(*it);
                m.clear();
            }
            else
            {
                assert(m.find(a[i]) != m.end());
                ans = (ans * 2) % M;
                for (auto it = m.begin(); it != m.end(); ++it)
                {
                    if (*it < a[i])
                        l.insert(*it);
                    else if (*it > a[i])
                        r.insert(*it);
                }
                m.clear();
            }
        }
    }

    ans = (ans * 1LL * (sz(m) + 1)) % M;

    cout << ans << "\n";
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