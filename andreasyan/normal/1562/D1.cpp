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

int n, qq;
char a[N];

int p[N];

map<int, vector<int> > mp;

void solv()
{
    cin >> n >> qq;
    cin >> (a + 1);

    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1];
        if (a[i] == '+')
        {
            if (i % 2)
                ++p[i];
            else
                --p[i];
        }
        else
        {
            if (i % 2)
                --p[i];
            else
                ++p[i];
        }
    }

    mp.clear();

    for (int i = 1; i<= n; ++i)
    {
        mp[p[i] + p[i - 1]].push_back(i);
    }

    while (qq--)
    {
        int l, r;
        cin >> l >> r;

        if (p[r] - p[l - 1] == 0)
        {
            cout << "0\n";
            continue;
        }

        if (mp.find(p[r] + p[l - 1]) != mp.end())
        {
            int i = lower_bound(all(mp[p[r] + p[l - 1]]), l) - mp[p[r] + p[l - 1]].begin();
            if (i < sz(mp[p[r] + p[l - 1]]) && mp[p[r] + p[l - 1]][i] <= r)
                cout << "1\n";
            else
                cout << "2\n";
        }
        else
            cout << "2\n";
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
        solv();
    return 0;
}