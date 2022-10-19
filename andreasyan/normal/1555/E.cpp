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
vector<pair<int, pair<int, int> > > v;

bool t[N * 4];
int q[N * 4];

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        q[pos] += y;
        if (q[pos] > 0)
            t[pos] = true;
        else
        {
            if (tl != tr)
                t[pos] = (t[pos * 2] && t[pos * 2 + 1]);
            else
                t[pos] = false;
        }
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);

    if (q[pos] > 0)
        t[pos] = true;
    else
    {
        if (tl != tr)
            t[pos] = (t[pos * 2] && t[pos * 2 + 1]);
        else
            t[pos] = false;
    }
}

void solv()
{
    cin >> n >> m;
    while (n--)
    {
        int l, r, w;
        cin >> l >> r >> w;
        --r;
        v.push_back(m_p(w, m_p(l, r)));
    }
    --m;
    n = sz(v);

    int ans = N;

    sort(all(v));
    int j = -1;
    for (int i = 0; i < n; ++i)
    {
        while (t[1] == false)
        {
            if (j + 1 < n)
            {
                ++j;
                ubd(1, m, v[j].se.fi, v[j].se.se, 1, 1);
            }
            else
                break;
        }
        if (t[1] == false)
            break;
        ans = min(ans, v[j].fi - v[i].fi);
        ubd(1, m, v[i].se.fi, v[i].se.se, -1, 1);
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}