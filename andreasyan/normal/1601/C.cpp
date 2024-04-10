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
const int N = 2000006;

int n, m;
int a[N], b[N];

int t[N];
void ubd(int x, int y)
{
    while (x < N)
    {
        t[x] += y;
        x += (x & (-x));
    }
}

int qry(int l, int r)
{
    if (l > r)
        return 0;

    int ans = 0;
    while (r)
    {
        ans += t[r];
        r -= (r & (-r));
    }

    --l;
    while (l)
    {
        ans -= t[l];
        l -= (l & (-l));
    }

    return ans;
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];

    sort(b + 1, b + m + 1);

    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(a[i]);
    for (int i = 1; i <= m; ++i)
        v.push_back(b[i]);
    sort(all(v));

    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
    for (int i = 1; i <= m; ++i)
        b[i] = lower_bound(all(v), b[i]) - v.begin() + 1;

    ll ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        ans += qry(a[i] + 1, sz(v));
        ubd(a[i], 1);
    }
    for (int i = 1; i <= n; ++i)
        ubd(a[i], -1);

    priority_queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        int r = upper_bound(b + 1, b + m + 1, a[i]) - b;
        int l = lower_bound(b + 1, b + m + 1, a[i]) - b;

        q.push(l);
        q.push(r);
        ans += (n + 1 - r);

        ans -= (n + 1 - q.top());
        q.pop();
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