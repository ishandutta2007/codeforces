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
const int N = 100005, K = 503;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

int n, k;
int r1[N], c1[N], r2[N], c2[N];

int d[K][K][4];
void ave(int x1, int y1_, int x2, int y2)
{
    if (x1 > x2)
    {
        swap(x1, x2);
        assert(y1_ == y2);
    }
    if (y1_ > y2)
    {
        swap(y1_, y2);
        assert(x1 == x2);
    }

    if (x2 > k / 2)
    {
        x1 = k - x1;
        x2 = k - x2;
        y1_ = k - y1_;
        y2 = k - y2;
    }

    for (int i = 0; i < 4; ++i)
    {
        int hx = x1 + xx[i];
        int hy = y1_ + yy[i];
        if (m_p(hx, hy) == m_p(x2, y2))
            ++d[x1][y1_][i];
    }
    for (int i = 0; i < 4; ++i)
    {
        int hx = x2 + xx[i];
        int hy = y2 + yy[i];
        if (m_p(hx, hy) == m_p(x1, y1_))
            ++d[x2][y2][i];
    }

    if (x1 == k / 2 && x2 == k / 2)
    {
        y1_ = k - y1_;
        y2 = k - y2;
        for (int i = 0; i < 4; ++i)
        {
            int hx = x1 + xx[i];
            int hy = y1_ + yy[i];
            if (m_p(hx, hy) == m_p(x2, y2))
                ++d[x1][y1_][i];
        }
        for (int i = 0; i < 4; ++i)
        {
            int hx = x2 + xx[i];
            int hy = y2 + yy[i];
            if (m_p(hx, hy) == m_p(x1, y1_))
                ++d[x2][y2][i];
        }
    }
}

struct ban
{
    int x, y, d;
    ban(){}
    ban(int x, int y, int d)
    {
        this->x = x;
        this->y = y;
        this->d = d;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.d > b.d;
}

bool c[K][K];

int solvv()
{
    memset(d, 0, sizeof d);
    for (int i = 0; i < n; ++i)
    {
        int r1 = ::r1[i];
        int c1 = ::c1[i];
        int r2 = ::r2[i];
        int c2 = ::c2[i];
        if (r1 == r2)
        {
            if (c1 > c2)
                swap(c1, c2);
            ave(r1, c1, r1 - 1, c1);
        }
        else
        {
            if (r1 > r2)
                swap(r2, r1);
            ave(r1, c1 - 1, r1, c1);
        }
    }

    memset(c, false, sizeof c);
    priority_queue<ban> q;
    q.push(ban(0, 0, 0));
    while (1)
    {
        ban t;
        do
        {
            t = q.top();
            q.pop();
        } while (c[t.x][t.y]);
        c[t.x][t.y] = true;

        if (t.x == k / 2 && t.y == k / 2)
            return n - t.d;

        for (int i = 0; i < 4; ++i)
        {
            ban h = t;
            h.x += xx[i];
            h.y += yy[i];
            h.d += d[t.x][t.y][i];
            if (h.x >= 0 && h.x <= k / 2 && h.y >= 0 && h.y <= k)
                q.push(h);
        }
    }
}

void solv()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> r1[i] >> c1[i] >> r2[i] >> c2[i];

    int ans = solvv();
    for (int i = 0; i < n; ++i)
    {
        swap(r1[i], c1[i]);
        swap(r2[i], c2[i]);
    }
    ans = max(ans, solvv());

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