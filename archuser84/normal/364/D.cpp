///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
#pragma GCC optimize("Ofast")

typedef __uint128_t u128;
typedef uint64_t u64;

mt19937 rd(time(0));
const int N = 1e6 + 10;
u64 a[N];
int n;

pair<u64, u64> inv(u64 x)
{
    int k = __builtin_ctzll(x); x >>= k;
    u64 rx = 1, tmp = x;
    Loop(_,0,63) {rx = rx*tmp; tmp = tmp*tmp;}
    return {rx, (1ll<<k)-1};
}

inline bool div(u64 x, u64 y, u64 ry, u64 k)
{
    if(x&k) return 0;
    if((u128(x*ry)*y) >> 64) return 0;
    return 1;
}

int count(u64 x, u64 rx, u64 k)
{
    int ans = 0;
    Loop(i,0,n)
    {
        if(div(a[i], x, rx, k))
            ++ans;
    }
    return ans;
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n) cin >> a[i];
    map<ll, int> m;
    Loop(_,0,200)
    {
        ll x = a[rd()%n];
        for(ll y = 1; y*y <= x; ++y)
        {
            if(x%y) continue;
            m[y]++;
            if(y*y != x) m[x/y]++;
        }
    }
    vector<ll> v;
    ll ans = 1;
    for(auto [x, cnt] : m)
    {
        if(cnt > 125) ans = x;
        else if(cnt >= 75) v.emplace_back(x);
    }
    random_shuffle(v.begin(), v.end());
    vector<tuple<u64, u64, u64>> bad;
    for(auto x : v)
    {
        if(clock() > 3980) break;
        if(x <= ans) continue;
        bool flg=0; for(auto [y, ry, k] : bad) if(div(x, y, ry, k)) {flg = 1; break;} if(flg) continue;
        auto [rx, k] = inv(x);
        if(2*count(x, rx, k) >= n) ans = x;
        else bad.emplace_back(x, rx, k);
    }
    cout << ans << '\n';
}