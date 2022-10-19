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

map<int, int> p, d, q;

int fi(int x)
{
    if (p[x] == x)
        return x;
    int pp = fi(p[x]);
    d[x] ^= d[p[x]];
    p[x] = pp;
    return pp;
}

void kpc(int x, int y, int z)
{
    int xx = fi(x);
    int yy = fi(y);
    if (q[xx] > q[yy])
        swap(xx, yy);
    q[yy] += q[xx];
    p[xx] = yy;
    d[xx] = d[x] ^ z ^ d[y];
}

void solv()
{
    int qq;
    scanf("%d", &qq);
    int ans = 0;
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            x ^= ans;
            y ^= ans;
            z ^= ans;
            if (x > y)
                swap(x, y);
            ++y;
            if (p.find(x) == p.end())
                p[x] = x;
            if (p.find(y) == p.end())
                p[y] = y;
            if (fi(x) == fi(y))
                continue;
            kpc(x, y, z);
        }
        else
        {
            int x, y;
            scanf("%d%d", &x, &y);
            x ^= ans;
            y ^= ans;
            if (x > y)
                swap(x, y);
            ++y;
            if (p.find(x) == p.end())
                p[x] = x;
            if (p.find(y) == p.end())
                p[y] = y;
            if (fi(x) != fi(y))
                ans = -1;
            else
            {
                fi(x);
                fi(y);
                ans = (d[x] ^ d[y]);
            }
            printf("%d\n", ans);
            if (ans == -1)
                ans = 1;
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}