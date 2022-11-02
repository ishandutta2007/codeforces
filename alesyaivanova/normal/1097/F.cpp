#include <bits/stdc++.h>
#pragma GCC target("sse4")

using namespace std;

#define int long long

const int MAX_N = 100009;
const int SZ = 7005;
bitset<SZ> b[MAX_N];
bitset<SZ> e;
bitset<SZ> g[SZ];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 1; i < SZ; i++)
    {
        for (int p = i; p < SZ; p += i)
            g[i].set(p);
        for (int p = 2; p * p * i < SZ; p++)
        {
            for (int w = i; p * p * w < SZ; w += i)
                g[i].reset(p * p * w);
        }
    }
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, v;
            cin >> x >> v;
            b[x] &= e;
            for (int j = 1; j * j <= v; j++)
            {
                if (v % j == 0)
                {
                    b[x].set(j);
                    b[x].set(v / j);
                }
            }
        }
        else if (t == 2)
        {
            int x, y, z;
            cin >> x >> y >> z;
            b[x] = (b[y] ^ b[z]);
        }
        else if (t == 3)
        {
            int x, y, z;
            cin >> x >> y >> z;
            b[x] = (b[y] & b[z]);
        }
        else
        {
            int x, v;
            cin >> x >> v;
            bitset<SZ> q = (b[x] & g[v]);
            cout << (q.count() & 1);
        }
    }
}