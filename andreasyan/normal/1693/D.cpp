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
int a[N];

struct ban
{
    int il, ir;
    int dl, dr;
    ban()
    {
        il = ir = dl = dr = 0;
    }
    ban(int il, int ir, int dl, int dr)
    {
        this->il = il;
        this->ir = ir;
        this->dl = dl;
        this->dr = dr;
    }
};

bool operator==(const ban& a, const ban& b)
{
    return (a.il == b.il && a.ir == b.ir && a.dl == b.dl && a.dr == b.dr);
}

bool vat(const ban& a, int i, const ban& b, int j)
{
    if (a == b)
    {
        return i < j;
    }

    if (!a.il && b.il)
        return false;
    if (a.il && b.il)
    {
        if (a.il > b.il)
            return false;
        if (a.ir < b.ir)
            return false;
    }

    if (!a.dl && b.dl)
        return false;
    if (a.dl && b.dl)
    {
        if (a.dl < b.dl)
            return false;
        if (a.dr > b.dr)
            return false;
    }

    return true;
}

vector<ban> mer(const vector<ban>& l, const vector<ban>& r)
{
    vector<ban> res;
    for (int i = 0; i < sz(l); ++i)
    {
        for (int j = 0; j < sz(r); ++j)
        {
            ban u;
            if (l[i].il && r[j].il)
            {
                if (l[i].ir > r[j].il)
                    continue;
                u.il = l[i].il;
                u.ir = r[j].ir;
            }
            else
            {
                u.il = l[i].il + r[j].il;
                u.ir = l[i].ir + r[j].ir;
            }

            if (l[i].dl && r[j].dl)
            {
                if (l[i].dr < r[j].dl)
                    continue;
                u.dl = l[i].dl;
                u.dr = r[j].dr;
            }
            else
            {
                u.dl = l[i].dl + r[j].dl;
                u.dr = l[i].dr + r[j].dr;
            }

            res.push_back(u);
        }
    }

    vector<ban> tres;
    for (int i = 0; i < sz(res); ++i)
    {
        bool z = true;
        for (int j = 0; j < sz(tres); ++j)
        {
            if (vat(res[i], i, res[j], j))
            {
                z = false;
                break;
            }
        }
        if (z)
        {
            for (int j = i + 1; j < sz(res); ++j)
            {
                if (vat(res[i], i, res[j], j))
                {
                    z = false;
                    break;
                }
            }
        }
        if (z)
            tres.push_back(res[i]);
    }

    return tres;
}

vector<ban> t[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos].push_back(ban(a[tl], a[tl], 0, 0));
        t[pos].push_back(ban(0, 0, a[tl], a[tl]));
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
    assert(sz(t[pos]) <= 3);
}

/*vector<ban> qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return {ban()};
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return mer(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}*/

vector<ban> h;
int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return n + 1;
    if (tl == l && tr == r)
    {
        if (!mer(h, t[pos]).empty())
        {
            h = mer(h, t[pos]);
            return n + 1;
        }
    }
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    int ans = qry(tl, m, l, min(m, r), pos * 2);
    if (ans <= n)
        return ans;
    return qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    /*for (int i = 1; i <= n; ++i)
        a[i] = i;
    for (int i = n; i >= 1; --i)
        swap(a[i], a[rnd() % i + 1]);*/

    bil(1, n, 1);

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        h.clear();
        h.push_back(ban());
        ans += (qry(1, n, i, n, 1) - i);
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