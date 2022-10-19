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

int n, k;

char s[N];

vector<int> u[26];

void solv()
{
    k = 2;
    for (int i = 0; i < 26; ++i)
        u[i].clear();
    cin >> s;
    n = strlen(s);
    for (int i = 1; i <= n; ++i)
    {
        int x = s[i - 1] - 'a';
        u[x].push_back(i);
    }

    vector<int> v;

    for (int x = 0; x < 26; ++x)
    {
        while (sz(u[x]) > k)
            u[x].pop_back();
        for (int j = 0; j < sz(u[x]); ++j)
            v.push_back(u[x][j]);
    }

    cout << sz(v) / k << "\n";
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