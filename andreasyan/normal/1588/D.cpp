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
const int N = 12, k = 52, M = k * 2 + 5;

int ctoi(char x)
{
    if ('a' <= x && x <= 'z')
        return (x - 'a');
    else if ('A' <= x && x <= 'Z')
        return (x - 'A') + 26;
    assert(false);
}

char itoc(int x)
{
    if (0 <= x && x <= 25)
        return (x + 'a');
    else if (26 <= x && x <= 51)
        return (x - 26 + 'A');
    assert(false);
}

int n;
char a[N][M];

int u[N][M][k];

map<vector<int>, string> mp;

string rec(vector<int> v)
{
    if (mp.find(v) != mp.end())
        return mp[v];

    mp[v] = "";

    for (int t = 0; t < k; ++t)
    {
        vector<int> vv;
        for (int i = 0; i < n; ++i)
        {
            if (u[i][v[i]][t] == M)
                break;
            vv.push_back(u[i][v[i]][t] + 1);
        }
        if (sz(vv) == n)
        {
            string s = rec(vv);
            reverse(all(s));
            s += itoc(t);
            reverse(all(s));
            if (sz(s) > sz(mp[v]))
                mp[v] = s;
        }
    }

    return mp[v];
}

void solv()
{
    mp.clear();

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
    {
        int m = strlen(a[i]);
        for (int t = 0; t < k; ++t)
            u[i][m][t] = M;
        for (int j = m - 1; j >= 0; --j)
        {
            for (int t = 0; t < k; ++t)
                u[i][j][t] = u[i][j + 1][t];
            u[i][j][ctoi(a[i][j])] = j;
        }
    }

    vector<int> v;
    for (int i = 0; i < n; ++i)
        v.push_back(0);

    string s = rec(v);

    cout << sz(s) << "\n";
    cout << s << "\n";
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