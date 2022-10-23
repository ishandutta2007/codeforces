#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

using u32 = uint32_t;
using u64 = uint64_t;
#define u128 unsigned __int128

namespace myrand
{
    mt19937 mt(chrono::system_clock::now().time_since_epoch() / chrono::microseconds(1));
    ll Int(ll l, ll r) {return uniform_int_distribution<ll> (l, r) (mt);}
}

using namespace myrand;
const int N = 1 << 19;
const u64 Hmod = (1ull << 61) - 1, Hbase = Int(N + 10, Hmod - 1);

u64 modmul(u64 x, u64 y)
{
#if defined(__LP64__) || defined(_WIN64)
    u128 res = (u128)x * y + 1;
    res =(res & Hmod) + (res >> 61);
    res =(res & Hmod) + (res >> 61);
    return res - 1;
#else
    u64 lx = (u32)x, hx = x >> 32, ly = (u32)y, hy = y >> 32;
    u64 l = lx * ly, m = lx * hy + ly * hx, h = hx * hy;
    u64 res = (l & Hmod) + (l >> 61) + ((m << 35) >> 3) + (m >> 29) + (h << 3) + 1;
    res = (res & Hmod) + (res >> 61);
    res = (res & Hmod) + (res >> 61);
    return res - 1;
#endif
}

u64 modplus(u64 x, u64 y)
{
    x += y;
    if (x >= Hmod) x -= Hmod;
    return x;
}

vector<u64> it[N];
int pwb[N];

void build(int id, int l, int r, string &s)
{
    if (l == r)
    {
        it[id].eb(s[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid, s);
    build(id * 2 + 1, mid + 1, r, s);
    int len = it[id * 2].size();
    it[id].resize(2 * len);
    for (int i = 0; i < len; ++i)
    {
        it[id][i] = modplus(modmul(it[id * 2][i], pwb[len]), it[id * 2 + 1][i]);
        it[id][i | len] = modplus(modmul(it[id * 2 + 1][i], pwb[len]), it[id * 2][i]);
    }
}

bool cmp(int id1, int id2, int xor1, int xor2, int len)
{
    if (len == 1) return it[id1][0] < it[id2][0];
    len /= 2;
    int lef1 = id1 * 2, rig1 = lef1 + 1;
    int lef2 = id2 * 2, rig2 = lef2 + 1;
    if (xor1 >= len) xor1 -= len, swap(lef1, rig1);
    if (xor2 >= len) xor2 -= len, swap(lef2, rig2);
    if (it[lef1][xor1] == it[lef2][xor2]) return cmp(rig1, rig2, xor1, xor2, len);
    return cmp(lef1, lef2, xor1, xor2, len);
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    n = 1 << n;
    pwb[0] = 1;
    for (int i = 1; i <= n; ++i) pwb[i] = modmul(pwb[i - 1], Hbase);
    build(1, 0, n - 1, s);
    int d = 0;
    for (int i = 1; i < n; ++i)
        if (cmp(1, 1, i, d, n)) d = i;
    for (int i = 0; i < n; ++i)
    {
        int j = i ^ d;
        if (i < j) swap(s[i], s[j]);
    }
    cout << s;
    return 0;
}