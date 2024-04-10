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

int n, qq;
char a[N];

struct ban
{
    int qa, qb, qc;
    int ay, cy;
    int ans;
    ban()
    {
        qa = qb = qc = 0;
        ay = cy = N;
        ans = 0;
    }
    ban(char x)
    {
        qa = qb = qc = 0;
        ay = cy = 0;
        ans = 0;
        if (x == 'a')
        {
            qa = 1;
            cy = N;
        }
        else if (x == 'b')
        {
            qb = 1;
            ay = cy = N;
        }
        else if (x == 'c')
        {
            qc = 1;
            ay = N;
        }
        else
            assert(false);
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.qa = l.qa + r.qa;
    res.qb = l.qb + r.qb;
    res.qc = l.qc + r.qc;

    res.ay = min(l.ay + r.qb, l.qa + r.ay);
    res.cy = min(l.qb + r.cy, l.cy + r.qc);

    res.ans = min(l.ans + r.qc, l.qa + r.ans);
    res.ans = min(res.ans, l.ay + r.cy);

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

void ubd(int tl, int tr, int x, char y, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void solv()
{
    int qq;
    cin >> n >> qq;
    cin >> (a + 1);

    bil(1, n, 1);

    while (qq--)
    {
        int x;
        char y;
        cin >> x >> y;
        ubd(1, n, x, y, 1);

        cout << t[1].ans << "\n";
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