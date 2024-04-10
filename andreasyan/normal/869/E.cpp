#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 2503, Q = 100005;

int n, m;

long long t[N][N];

void ubdy(int x, int y, long long z)
{
    while (y <= m)
    {
        t[x][y] ^= z;
        y += (y & (-y));
    }
}

void ubdx(int x, int y, long long z)
{
    while (x <= n)
    {
        ubdy(x, y, z);
        x += (x & (-x));
    }
}

long long qryy(int x, int y)
{
    long long ans = 0;
    while (y)
    {
        ans ^= t[x][y];
        y -= (y & (-y));
    }
    return ans;
}

long long qryx(int x, int y)
{
    long long ans = 0;
    while (x)
    {
        ans ^= qryy(x, y);
        x -= (x & (-x));
    }
    return ans;
}

void ubd(int x1, int y1, int x2, int y2, long long z)
{
    ubdx(x1, y1, z);
    ubdx(x2 + 1, y2 + 1, z);
    ubdx(x1, y2 + 1, z);
    ubdx(x2 + 1, y1, z);
}

void solv()
{
    int qq;
    scanf("%d%d%d", &n, &m, &qq);
    map<pair<pair<int, int>, pair<int, int> >, long long> mp;
    while (qq--)
    {
        int ty, x1, y1, x2, y2;
        scanf("%d%d%d%d%d", &ty, &x1, &y1, &x2, &y2);
        if (ty == 1)
        {
            mp[m_p(m_p(x1, y1), m_p(x2, y2))] = rnd();
            ubd(x1, y1, x2, y2, mp[m_p(m_p(x1, y1), m_p(x2, y2))]);
        }
        else if (ty == 2)
        {
            ubd(x1, y1, x2, y2, mp[m_p(m_p(x1, y1), m_p(x2, y2))]);
        }
        else
        {
            if (qryx(x1, y1) == qryx(x2, y2))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}