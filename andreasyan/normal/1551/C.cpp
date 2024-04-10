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

int n;
int q[N][5];

int m;
char s[N];

int b[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 5; ++j)
            q[i][j] = 0;

    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        m = strlen(s);
        for (int j = 0; j < m; ++j)
            q[i][s[j] - 'a']++;
    }

    int ans = 0;
    for (int j = 0; j < 5; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            b[i] = 0;
            for (int k = 0; k < 5; ++k)
            {
                if (k != j)
                    b[i] -= q[i][k];
                else
                    b[i] += q[i][k];
            }
        }

        sort(b + 1, b + n + 1);
        reverse(b + 1, b + n + 1);

        int s = 0;
        for (int i = 1; i <= n; ++i)
        {
            s += b[i];
            if (s > 0)
                ans = max(ans, i);
        }
    }

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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}