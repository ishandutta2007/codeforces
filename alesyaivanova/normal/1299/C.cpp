#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define ld long double
#define matr vector<vector<int> >
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e6 + 9;
int n;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    cin >> n;
    map<int, pair<int, ld> > s;
    for (int i = 0; i < n; i++)
    {
        int kek;
        cin >> kek;
        s.emplace(i, mp(1, kek));
    }
    for (auto j = s.begin(); j != s.end(); )
    {
        if (j != s.begin())
        {
            auto u = j;
            u--;
            if ((*u).ss.ss >= (*j).ss.ss)
            {
                (*u).ss.ss = ((*u).ss.ss * (*u).ss.ff +
                        (*j).ss.ss * (*j).ss.ff) / ((*u).ss.ff + (*j).ss.ff);
                (*u).ss.ff += (*j).ss.ff;
                s.erase(j);
                j = u;
                continue;
            }
        }
        j++;
    }
    cout.precision(20);
    cout << fixed;
    for (auto j = s.begin(); j != s.end(); j++)
    {
        for (int e = 0; e < (int)(*j).ss.ff; e++)
            cout << (*j).ss.ss << "\n";
    }
}