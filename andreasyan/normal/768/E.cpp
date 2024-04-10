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
const int N = 61;
const int gg[N] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};

map<ll, int> mp[N];

int rec(int x, ll y)
{
    if (mp[x].find(y) != mp[x].end())
        return mp[x][y];

    set<int> s;
    for (int i = 1; i <= x; ++i)
    {
        if ((y & (1LL << i)))
            continue;
        s.insert(rec(x - i, (y | (1LL << i))));
    }

    for (int i = 0; ; ++i)
    {
        if (s.find(i) == s.end())
        {
            return mp[x][y] = i;
        }
    }
}

void solv()
{
    /*for (int i = 0; i <= 60; ++i)
    {
        cout << rec(i, 0) << ", ";
    }*/

    int n;
    cin >> n;
    int ans = 0;
    while (n--)
    {
        int x;
        cin >> x;
        ans ^= gg[x];
    }

    if (ans == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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