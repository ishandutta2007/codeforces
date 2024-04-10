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

int n, k;
int a[N];

int t[N * 4];
int q[N * 4];

void bil(int tl, int tr, int pos)
{
    t[pos] = q[pos] = 0;
    if (tl == tr)
        return;
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
}

void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos] += x;
        ++q[pos];
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
    q[pos] = q[pos * 2] + q[pos * 2 + 1];
}

int x, ans;
void qry(int tl, int tr, int pos)
{
    if (x >= t[pos])
    {
        x -= t[pos];
        ans += q[pos];
        return;
    }
    if (x < tl)
        return;
    if (tl == tr)
    {
        ans += (x / tl);
        x %= tl;
        return;
    }

    int m = (tl + tr) / 2;
    qry(tl, m, pos * 2);
    qry(m + 1, tr, pos * 2 + 1);
}

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    a[0] = -1;
    sort(a + 1, a + n + 1);
    vector<pair<int, int> > v;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != a[i - 1])
            v.push_back(m_p(a[i], 1));
        else
            v.back().se++;
    }

    bil(1, n, 1);
    int yans = N;
    for (int m = n; m >= 0; --m)
    {
        while (!v.empty() && v.back().fi >= m)
        {
            ubd(1, n, v.back().se, 1);
            v.pop_back();
        }

        if (m - sz(v) <= k)
        {
            if (k >= t[1])
            {
                yans = 0;
            }
            else
            {
                x = k;
                ans = 0;
                qry(1, n, 1);
                yans = min(yans, q[1] - ans);
            }
        }
    }

    cout << yans << "\n";
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