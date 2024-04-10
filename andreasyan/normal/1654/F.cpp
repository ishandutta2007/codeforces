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
const int N = 300005;
const pair<int, int> M = m_p(993019889, 997084241);
const int P = 307;

bool prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

pair<int, int> sum(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi + b.fi) % M.fi, (a.se + b.se) % M.se);
}

pair<int, int> dif(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi - b.fi + M.fi) % M.fi, (a.se - b.se + M.se) % M.se);
}

pair<int, int> pro(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi * 1LL * b.fi) % M.fi, (a.se * 1LL * b.se) % M.se);
}

pair<int, int> ast[N];
void pre()
{
    ast[0] = m_p(1, 1);
    for (int i = 1; i < N; ++i)
        ast[i] = pro(ast[i - 1], m_p(P, P));
}

int n;
char a[N];

vector<pair<int, int> > t[N * 4];

void bil(int tl, int tr, int pos, int i)
{
    if (tl == tr)
    {
        t[pos].push_back(m_p(a[tl], a[tl]));
        return;
    }

    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2, i - 1);
    bil(m + 1, tr, pos * 2 + 1, i - 1);

    for (int x = 0; x < tr - tl + 1; ++x)
    {
        if (!(x & (1 << i)))
        {
            t[pos].push_back(sum(t[pos * 2][x], pro(ast[(1 << i)], t[pos * 2 + 1][x])));
        }
        else
        {
            t[pos].push_back(sum(t[pos * 2 + 1][(x ^ (1 << i))], pro(ast[(1 << i)], t[pos * 2][(x ^ (1 << i))])));
        }
    }
}

int qry(int tl, int tr, int x, int y, int posx, int posy, int i)
{
    if (t[posx][x] == t[posy][y])
        return -1;
    if (tl == tr)
        return tl;

    int hposx = posx * 2;
    if ((x & (1 << i)))
        ++hposx;

    int hposy = posy * 2;
    if ((y & (1 << i)))
        ++hposy;

    int m = (tl + tr) / 2;

    int hx = x;
    if ((x & (1 << i)))
        hx ^= (1 << i);

    int hy = y;
    if ((y & (1 << i)))
        hy ^= (1 << i);

    int u = qry(tl, m, hx, hy, hposx, hposy, i - 1);
    if (u != -1)
        return u;
    return qry(m + 1, tr, hx, hy, posx * 4 + 1 - hposx, posy * 4 + 1 - hposy, i - 1);
}

void solv()
{
    cin >> n;
    cin >> a;

    bil(0, (1 << n) - 1, 1, n - 1);

    /*for (int j = 0; j < (1 << n); ++j)
    {
        cout << j << ' ';
        for (int x = 0; x < (1 << n); ++x)
            cout << a[(x ^ j)];
        cout << endl;
    }*/

    int ansj = 0;
    for (int j = 0; j < (1 << n); ++j)
    {
        int u = qry(0, (1 << n) - 1, ansj, j, 1, 1, n - 1);
        if (u != -1 && a[(j ^ u)] < a[(ansj ^ u)])
            ansj = j;
    }


    for (int x = 0; x < (1 << n); ++x)
    {
        cout << a[(ansj ^ x)];
    }
    cout << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    solv();
    return 0;
}