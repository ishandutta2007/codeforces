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
const int N = 100005;

int n, qq;
char a[N];

int p[N][26];

void solv()
{
    cin >> n >> qq;
    cin >> (a + 1);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 26; ++j)
            p[i][j] = p[i - 1][j];
        p[i][a[i] - 'a']++;
    }

    while (qq--)
    {
        int l, r;
        cin >> l >> r;

        int ans = 0;
        for (int j = 0; j < 26; ++j)
        {
            ans += (p[r][j] - p[l - 1][j]) * (j + 1);
        }

        cout << ans << "\n";
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