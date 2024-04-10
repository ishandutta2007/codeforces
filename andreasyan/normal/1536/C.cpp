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
const int N = 500005;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
char a[N];

int p1[N], p2[N];

int dp[N];

void solv()
{
    cin >> n;
    cin >> (a + 1);

    for (int i = 1; i <= n; ++i)
    {
        p1[i] = p1[i - 1];
        p2[i] = p2[i - 1];
        if (a[i] == 'D')
            ++p1[i];
        else
            ++p2[i];
    }

    for (int i = 1; i <= n; ++i)
        dp[i] = 0;

    map<pair<int, int>, int> mp;

    int q1 = 0, q2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 'D')
            ++q1;
        else
            ++q2;

        int g = gcd(q1, q2);

        ++mp[m_p(q1 / g, q2 / g)];
        cout << mp[m_p(q1 / g, q2 / g)] << ' ';
    }
    cout << "\n";
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