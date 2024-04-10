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

int n, qq;
int minu[N], maxu[N];

int t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = max(t[pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return max(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    cin >> n >> qq;

    set<int> s;
    for (int i = 0; i <= n + 1; ++i)
        s.insert(i);

    for (int i = 1; i <= n; ++i)
    {
        minu[i] = n + 1;
        maxu[i] = 0;
    }

    while (qq--)
    {
        int ty;
        cin >> ty;
        if (ty == 0)
        {
            int l, r, x;
            cin >> l >> r >> x;

            if (x == 0)
            {
                while (1)
                {
                    if (s.empty())
                        break;
                    auto it = s.lower_bound(l);
                    if (*it <= r)
                        s.erase(it);
                    else
                        break;
                }
            }
            else
            {
                minu[l] = min(minu[l], r);
                maxu[r] = max(maxu[r], l);
                ubd(1, n, r, l, 1);
            }
        }
        else
        {
            int x;
            cin >> x;

            if (s.find(x) == s.end())
            {
                cout << "NO\n";
                continue;
            }

            auto it = s.upper_bound(x);
            int ur = *it;
            --it;
            --it;
            int ul = *it;

            if (minu[x] < ur)
            {
                cout << "YES\n";
                continue;
            }
            if (maxu[x] > ul)
            {
                cout << "YES\n";
                continue;
            }

            if (qry(1, n, x, ur - 1, 1) > ul)
            {
                cout << "YES\n";
                continue;
            }

            cout << "N/A\n";
        }
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