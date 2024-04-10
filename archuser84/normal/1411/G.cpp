#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll int64_t
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

const int mod = 998244353;
const int N = 100'010;
const int M = 512;

ll modDiv(ll x, ll y, ll mod = ::mod)
{
	if (x % y == 0) return x / y;
	return (modDiv(y - x % y, mod % y, y) * mod + x) / y;
}

ll eq[M][M+1] = {};

void solve()
{
    Loop(rc,0,M)
    {
        int sel;
        for(sel = rc; eq[sel][rc] == 0; ++sel) {assert(sel+1 < M);}
        Loop(i,0,M+1) swap(eq[sel][i], eq[rc][i]);

        ll x = modDiv(1, eq[rc][rc]);
        Loop(i,rc,M+1) eq[rc][i] = (eq[rc][i]*x) % mod;

        Loop(i,0,M)
        {
            if(i == rc || eq[i][rc] == 0) continue;
            ll x = mod-eq[i][rc];
            Loop(j,rc,M+1) eq[i][j] = (eq[i][j] + x*eq[rc][j]) % mod;
        }
    }
}

vector<int> A[N];
int cnt[M] = {};
int grn[N];
int n, m;

int grundy(int u)
{
    if(grn[u] >= 0) return grn[u];
    vector<int> a;
    for(int v : A[u]) a.push_back(grundy(v));
    Loop(i,0,a.size())
    {
        int j = a[i] & INT_MAX;
        if(j >= a.size()) continue;
        a[j] |= INT_MIN;
    }
    Loop(i,0,a.size()) if(a[i] >= 0) return grn[u] = i;
    return grn[u] = a.size();
}

int main()
{
    FAST;
    memset(grn, -1, sizeof grn);
    cin >> n >> m;
    Loop(i,0,m)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        A[u].push_back(v);
    }
    Loop(i,0,n) cnt[grundy(i)]++;
    ll r = modDiv(1, n+1);
    Loop(i,0,M) Loop(j,0,M) eq[i][i^j] += cnt[j];
    Loop(i,0,M) Loop(j,0,M) eq[i][j] = eq[i][j]*r % mod;
    Loop(i,0,M) eq[i][i] = (eq[i][i]+mod-1) % mod;
    eq[0][M] = (mod-1)*r % mod;
    solve();
    cout << (mod+1-eq[0][M])%mod << '\n';
}