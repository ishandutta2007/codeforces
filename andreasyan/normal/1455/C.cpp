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

pair<int, int> rec(int x, int y, int z)
{
    if (z == 0)
    {
        if (x == 0 && y == 0)
            return m_p(0, 0);
        if (x == 0)
        {
            pair<int, int> u = rec(y, x, 0);
            swap(u.fi, u.se);
            return u;
        }
        else
        {
            pair<int, int> u = rec(y, x - 1, 1);
            swap(u.fi, u.se);
            return u;
        }
    }
    else
    {
        if (x == 0)
        {
            pair<int, int> u = rec(y, x, 0);
            swap(u.fi, u.se);
            u.se++;
            return u;
        }
        pair<int, int> u1 = rec(y, x, 0);
        swap(u1.fi, u1.se);
        u1.se++;
        pair<int, int> u2 = rec(y, x - 1, 1);
        swap(u2.fi, u2.se);
        if (u1.fi > u2.fi)
            return u1;
        if (u1.fi < u2.fi)
            return u2;
        return min(u1, u2);
    }
}

void solv()
{
    int ans1 = 0, ans2 = 0;
    int x, y;
    scanf("%d%d", &x, &y);

    //pair<int, int> u = rec(x, y, 0);
    //printf("%d %d\n", u.fi, u.se);

    if (x > y)
    {
        ans1 += (x - y);
        ans1 += (y - 1);
        ans2 += y;
    }
    else
    {
        --x;
        --y;
        ans2++;

        ans2 += (y - x);
        ans2 += x;
        ans1 += x;
    }

    printf("%d %d\n", ans1, ans2);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}