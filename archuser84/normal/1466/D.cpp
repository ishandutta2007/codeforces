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

const int N = 100'010;
ll w[N];
int d[N];
int n;

void solve()
{
    cin >> n;
    ll ans = 0;
    vector<pll> A;
    Loop(i,0,n){
        cin >> w[i];
        d[i] = -1;
        ans += w[i];
        A.push_back({w[i], i});
    }
    sort(all(A));
    Loop(i,1,n)
    {
        int u, v;
        cin >> u >> v;
        d[u-1]++;
        d[v-1]++;
    }
    Loop(i,0,n-2)
    {
        cout << ans << ' ';
        while(d[A.back().S] <= 0) A.pop_back();
        ans += w[A.back().S];
        d[A.back().S]--;
    }
    cout << ans << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}