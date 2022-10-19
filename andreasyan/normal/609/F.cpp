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
const int N = 200005, INF = 1000000009;

int n, m;
int x[N], t[N];
int p[N], b[N];

int q[N];

int minu[N * 4];
void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        minu[pos] = min(minu[pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
}

int qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return minu[pos];
    int m = (tl + tr) / 2;
    if (x <= m)
        return min(qry(tl, m, x, pos * 2), minu[pos]);
    return min(qry(m + 1, tr, x, pos * 2 + 1), minu[pos]);
}

vector<int> v;
void ubdd(int i)
{
    int l = lower_bound(all(v), x[i]) - v.begin();
    int r = upper_bound(all(v), x[i] + t[i]) - v.begin() - 1;
    ubd(0, m - 1, l, r, x[i], 1);
}

map<int, int> mp;
void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> t[i];
    for (int i = 1; i <= m; ++i)
        cin >> p[i] >> b[i];

    for (int i = 1; i <= n; ++i)
        mp[x[i]] = i;

    for (int i = 1; i <= m; ++i)
        v.push_back(p[i]);
    sort(all(v));

    for (int i = 0; i < N * 4; ++i)
        minu[i] = INF;
    for (int i = 1; i <= n; ++i)
        ubdd(i);

    multiset<pair<int, int> > s;
    for (int j = 1; j <= m; ++j)
    {
        int pp = lower_bound(all(v), p[j]) - v.begin();
        int i = qry(0, m - 1, pp, 1);
        if (i == INF)
            s.insert(m_p(p[j], b[j]));
        else
        {
            i = mp[i];
            t[i] += b[j];
            q[i]++;
            while (1)
            {
                if (s.empty())
                    break;
                auto it = s.lower_bound(m_p(x[i], -1));
                if (it == s.end())
                    break;
                if (it->fi <= x[i] + t[i])
                {
                    t[i] += it->se;
                    q[i]++;
                    s.erase(it);
                }
                else
                    break;
            }
            ubdd(i);
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << q[i] << ' ' << t[i] << "\n";
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