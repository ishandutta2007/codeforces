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
const int N = 1003;

int n;
int l[N], r[N];

int ans[N];
pair<int, int> q[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> l[i] >> r[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        q[i].se = i;
        q[i].fi = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        q[l[i]].fi++;
        q[r[i] + 1].fi--;
    }
    for (int i = 1; i <= n; ++i)
        q[i].fi += q[i - 1].fi;

    sort(q + 1, q + n + 1);
    for (int i = 1; i <= n; ++i)
        ans[i] = 0;

    for (int i = 1; i <= n; ++i)
    {
        int x = q[i].se;
        for (int j = 1; j <= n; ++j)
        {
            if (ans[j])
                continue;
            if (l[j] <= x && x <= r[j])
            {
                ans[j] = x;
                break;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << l[i] << ' ' << r[i] << ' ' << ans[i] << "\n";
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