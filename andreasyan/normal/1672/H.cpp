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
char a[N];

struct ban
{
    int ans;
    int l, r;
    int q0, q1;
    ban(){}
    ban(char x)
    {
        ans = 0;
        l = r = x - '0';
        q0 = q1 = 0;
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.ans = l.ans + r.ans;
    res.l = l.l;
    res.r = r.r;
    res.q1 = l.q1 + r.q1;
    res.q0 = l.q0 + r.q0;

    if (l.r == 0 && r.l == 0)
        ++res.q0;

    if (l.r == 1 && r.l == 1)
        ++res.q1;

    int minu = min(res.q0, res.q1);
    res.ans += minu;

    res.q0 -= minu;
    res.q1 -= minu;

    return res;
}

ban t[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(a[tl]);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);

    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];

    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);

    return mer(qry(tl, m, l, m, pos * 2),
               qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

void solv()
{
    int qq;
    cin >> n >> qq;
    cin >> (a + 1);

    bil(1, n, 1);
    while (qq--)
    {
        int l, r;
        cin >> l >> r;

        ban u = qry(1, n, l, r, 1);

        cout << u.ans + u.q0 + u.q1 + 1 << "\n";
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