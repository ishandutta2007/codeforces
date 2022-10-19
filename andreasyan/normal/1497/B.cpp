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

int n, m;
int a[N];

int q[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i)
        q[i] = 0;

    for (int i = 1; i <= n; ++i)
        q[a[i] % m]++;

    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        if (!q[i])
            continue;
        int j = (m - i) % m;
        if (i == j)
        {
            ++ans;
            q[i] = 0;
        }
        else
        {
            ++ans;
            if (q[i] > q[j])
            {
                q[i] -= (q[j] + 1);
                q[j] = 0;
            }
            else if (q[j] > q[i])
            {
                q[j] -= (q[i] + 1);
                q[i] = 0;
            }
            else
            {
                q[i] = q[j] = 0;
            }
            ans += q[i];
            ans += q[j];
            q[i] = q[j] = 0;
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
    //scanf("%d", &tt);
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}