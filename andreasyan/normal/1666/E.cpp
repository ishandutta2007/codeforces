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

int L, n;
int a[N];

bool stgg(int minu, int maxu)
{
    int l = a[1], r = a[1];
    for (int i = 2; i <= n; ++i)
    {
        int d = a[i] - a[i - 1];

        l = max(0, l + d - maxu);
        r = min(d, r + d - minu);

        if (l > r)
            return false;
    }

    l += (L - a[n]);
    r += (L - a[n]);
    l = max(l, minu);
    r = min(r, maxu);

    if (l > r)
        return false;

    return true;
}

bool stg(int minu)
{
    int l = minu, r = L;
    int maxu = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stgg(minu, m))
        {
            maxu = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return (maxu != -1);
}

int l0[N], r0[N];
void solv()
{
    cin >> L >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int l = 0, r = L;
    int minu = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            minu = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    assert(minu != -1);

    l = minu, r = L;
    int maxu = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stgg(minu, m))
        {
            maxu = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    assert(maxu != -1);

    assert(stgg(minu, maxu));

    l0[1] = a[1], r0[1] = a[1];
    for (int i = 2; i <= n; ++i)
    {
        int d = a[i] - a[i - 1];

        l0[i] = max(0, l0[i - 1] + d - maxu);
        r0[i] = min(d, r0[i - 1] + d - minu);
    }

    int x = (L - a[n]);
    vector<int> ans;
    for (int i = n; i >= 1; --i)
    {
        int d = a[i] - a[i - 1];
        l0[i] = max(l0[i], minu - x);
        r0[i] = min(r0[i], maxu - x);
        assert(l0[i] <= r0[i]);
        ans.push_back(x + l0[i]);
        x = d - l0[i];
    }
    ans.push_back(0);

    reverse(all(ans));
    for (int i = 1; i < sz(ans); ++i)
        ans[i] += ans[i - 1];
    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ' << ans[i + 1] << "\n";
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