///
///    "I, Giorno Giovanna, have a dream."
///
///                                    -Giorno Giovanna

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize ("O0")

const int N = 200'010;
int a[N], b[N], nxt[N];
int n;

void solve()
{
    cin >> n;
    Loop(i,0,n) cin >> a[i]; a[n] = a[0];
    Loop(i,0,n) b[i] = __gcd(a[i], a[i+1]);
    Loop(i,0,n) nxt[i] = (i+1)%n;
    vector<int> ans;
    int bg = 0;
    while(1)
    {
        int* p = find(b+bg, b+n, 1);
        //cerr << "!" << p-b << '\n';
        if(p == b+n) p = find(b, b+n, 1);
        if(p == b+n) break;
        int i = p-b;
        ans.push_back(nxt[i]);
        int tmp = nxt[i];
        nxt[i] = nxt[nxt[i]];
        b[i] = __gcd(a[i], a[nxt[i]]);
        b[tmp] = 0;
        bg = nxt[i];
    }
    cout << ans.size() << ' ';
    for(auto x : ans) cout << x+1 << ' ';
    cout << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}