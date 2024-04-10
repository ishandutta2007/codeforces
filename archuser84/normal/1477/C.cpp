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

const int N = 5'010;

ll x[N], y[N];
bool vis[N] = {};
inline ll sqr(ll x){return x*x;}

int main()
{
    int n;
    cin >> n;
    vector<int> ans;
    Loop(i,0,n) cin >> x[i] >> y[i];
    ans.push_back(0);
    int c = 0; vis[0] = 1;
    Loop(_,1,n)
    {
        int mx = c;
        Loop(i,0,n)
        {
            if(vis[i]) continue;
            if(sqr(x[i]-x[c]) + sqr(y[i]-y[c]) > sqr(x[mx]-x[c]) + sqr(y[mx]-y[c])) mx = i;
        }
        ans.push_back(mx);
        c = mx;
        vis[mx] = 1;
    }
    for(int x : ans)
        cout << x+1 << ' ';
}