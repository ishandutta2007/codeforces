#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

const int N = 300'010;
int a[N];
int cnt[1'000'010] = {};
int reset[1'000'010] = {};
vector<int> seen;
int n;

int to_bin(int x)
{
    int ans = 1;
    for(int d = 2; d*d <= x; ++d)
    {
        int cnt = 0;
        while(x%d == 0)
        {
            ++cnt;
            x /= d;
        }
        if(cnt&1) ans *= d;
    }
    ans *= x;
    return ans;
}

void solve(int t)
{
    seen.clear(); cnt[1] = 0;
    cin >> n;
    Loop(i,0,n)
    {
        int x;
        cin >> x;
        x = to_bin(x);
        if(reset[x] != t)
            cnt[x] = 0,
            reset[x] = t,
            seen.push_back(x);
        cnt[x]++;
    }
    int ans = 0;
    int ecnt = 0;
    for(int x : seen)
    {
        if(x != 1 && (cnt[x]&1) == 0) ecnt += cnt[x];
        ans = max(ans, cnt[x]);
    }
    int q;
    cin >> q;
    while(q--)
    {
        ll w;
        cin >> w;
        if(w == 0) cout << ans << '\n';
        else cout << max(ans, ecnt + cnt[1]) << '\n';
    }
}

int main()
{
    FAST;
    int t;
    cin >> t;
    Loop(i,1,t+1) solve(i);
}