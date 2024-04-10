#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define err(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

const int SZ = 1e7;

int Next[SZ][2];
int Last = 1;
int cnt[SZ];

void add(ll x, int sign)
{
    int pos = 1;
    cnt[pos] += sign;
    for (int i = 59; i >= 0; --i)
    {
        int b = (x >> i) & 1;
        if (!Next[pos][b]) Next[pos][b] = ++Last;
        pos = Next[pos][b];
        cnt[pos] += sign;
    }
}

ll get(ll val, int pos, int i, ll z, int flag)
{
    if (!cnt[pos]) return -1;
    if (i == -1)
    {
        return z;
    }
    
    int b = (val >> i) & 1;
    ll zz;

    if (b == 0)
    {
        zz = get(val, Next[pos][0], i - 1, z, flag);
        if (zz != -1) return zz;
        zz = get(val, Next[pos][1], i - 1, z + (1ll << i), 1);
        if (zz != -1) return zz;
    }

    if (b == 1)
    {
        zz = get(val, Next[pos][0], i - 1, z, flag);
        if (zz != -1) return zz;
        
        if (flag)
        {
            zz = get(val, Next[pos][1], i - 1, z + (1ll << i), 1);
            if (zz != -1) return zz;
        }
        
    }
    return -1;
}


const int N = 1e5;
ll a[N];
ll b[N];

int main() {
#ifdef amit_swami
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    forn(i, n) scanf("%lld", &a[i]);

    forn(i, n) add(a[i], 1);
    
    ll val = 0;
    forn(i, n)
    {
        ll z = get(val, 1, 59, 0, 0);
        if (z == -1) return 0 * printf("No\n");
        val ^= z;
        b[i] = z;
        add(z, -1);
    }
    
    printf("Yes\n");
    forn(i, n) printf("%lld%c", b[i], " \n"[i + 1 == n]);


    return 0;
}