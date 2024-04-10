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

int n, m;
int a[N];
int b[N];

vector<int> v[3];

ll p[N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);

    v[1].clear();
    v[2].clear();
    for (int i = 1; i <= n; ++i)
        v[b[i]].push_back(a[i]);
    sort(all(v[1]));
    sort(all(v[2]));
    v[1].push_back(0);
    v[2].push_back(0);
    reverse(all(v[1]));
    reverse(all(v[2]));

    for (int i = 1; i < v[2].size(); ++i)
        p[i] = p[i - 1] + v[2][i];

    int ans = N * 4;
    ll mm = m;
    for (int q1 = 0; q1 < v[1].size(); ++q1)
    {
        mm -= v[1][q1];
        int l = 0, r = sz(v[2]) - 1;
        int u = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (mm - p[mid] <= 0)
            {
                u = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        if (u != -1)
            ans = min(ans, q1 + u * 2);
    }

    if (ans == N * 4)
        printf("-1\n");
    else
        printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}