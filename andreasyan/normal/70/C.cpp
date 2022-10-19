#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;
int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int xx, yy, w;

int rev(int x)
{
    int y = 0;
    while (x)
    {
        y = (y * 10 + (x % 10));
        x /= 10;
    }
    return y;
}

map<pair<int, int>, vector<int> > v;

int t[N * 4];
void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos]++;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int qry(int tl, int tr, int y, int pos)
{
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    if (t[pos * 2] >= y)
        return qry(tl, m, y, pos * 2);
    return qry(m + 1, tr, y - t[pos * 2], pos * 2 + 1);
}

void solv()
{
    scanf("%d%d%d", &xx, &yy, &w);
    for (int y = 1; y <= yy; ++y)
    {
        int r = rev(y);
        int g = gcd(y, r);
        v[m_p(r / g, y / g)].push_back(y);
    }
    int ansx = N, ansy = N;
    for (int x = 1; x <= xx; ++x)
    {
        int r = rev(x);
        int g = gcd(x, r);
        for (int i = 0; i < v[m_p(x / g, r / g)].size(); ++i)
        {
            int y = v[m_p(x / g, r / g)][i];
            ubd(1, yy, y, 1);
        }
        if (t[1] >= w)
        {
            int y = qry(1, yy, w, 1);
            if (x * 1LL * y < ansx * 1LL * ansy)
            {
                ansx = x;
                ansy = y;
            }
        }
    }
    if (ansx == N)
        printf("-1\n");
    else
        printf("%d %d\n", ansx, ansy);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}