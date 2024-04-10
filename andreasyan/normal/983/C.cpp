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
const int N = 2003;

int n;
int a[N], b[N];

struct ban
{
    int i;
    int u;
    int x1, x2, x3, x4;
    int d;
    ban(){}
    ban(int i, int u, int x1, int x2, int x3, int x4, int d)
    {
        this->i = i;
        this->u = u;
        this->x1 = x1;
        this->x2 = x2;
        this->x3 = x3;
        this->x4 = x4;
        this->d = d;
    }
};

bool c[N][10][10][10][10][10];
queue<ban> q;

void ave(ban t)
{
    if (c[t.i][t.u][t.x1][t.x2][t.x3][t.x4])
        return;
    c[t.i][t.u][t.x1][t.x2][t.x3][t.x4] = true;
    q.push(t);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i], &b[i]);
    ave(ban(0, 1, 0, 0, 0, 0, 0));
    while (!q.empty())
    {
        ban t = q.front();
        q.pop();
        if (t.i == n && t.x1 == 0 && t.x2 == 0 && t.x3 == 0 && t.x4 == 0)
        {
            printf("%d\n", t.d);
            return;
        }
        if (t.x1 == t.u)
        {
            t.x1 = 0;
            ++t.d;
            ave(t);
            continue;
        }
        if (t.x2 == t.u)
        {
            t.x2 = 0;
            ++t.d;
            ave(t);
            continue;
        }
        if (t.x3 == t.u)
        {
            t.x3 = 0;
            ++t.d;
            ave(t);
            continue;
        }
        if (t.x4 == t.u)
        {
            t.x4 = 0;
            ++t.d;
            ave(t);
            continue;
        }
        if (t.i < n && a[t.i + 1] == t.u)
        {
            if (t.x1 == 0)
            {
                t.x1 = b[t.i + 1];
                ++t.i;
                ++t.d;
                ave(t);
                continue;
            }
            if (t.x2 == 0)
            {
                t.x2 = b[t.i + 1];
                ++t.i;
                ++t.d;
                ave(t);
                continue;
            }
            if (t.x3 == 0)
            {
                t.x3 = b[t.i + 1];
                ++t.i;
                ++t.d;
                ave(t);
                continue;
            }
            if (t.x4 == 0)
            {
                t.x4 = b[t.i + 1];
                ++t.i;
                ++t.d;
                ave(t);
                continue;
            }
        }
        if (t.u > 1)
        {
            ban h = t;
            --h.u;
            ++h.d;
            ave(h);
        }
        if (t.u < 9)
        {
            ban h = t;
            ++h.u;
            ++h.d;
            ave(h);
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}