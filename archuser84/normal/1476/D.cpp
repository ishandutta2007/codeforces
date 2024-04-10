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

const int N = 300'010;

char s[N];
bool a[N], b[N];
int la[N], lb[N], ra[N], rb[N];
int n;

void solve()
{
    cin >> n;
    cin >> s;
    Loop(i,0,n)
    {
        a[i] = (!!(s[i]-'L'))^(i&1);
        b[i] = (!!(s[i]-'L'))^(i&1)^1;
    }
    int c;
    c = 0;
    la[0] = 0;
    Loop(i,0,n)
    {
        ++c;
        if(a[i]) c = 0;
        la[i+1] = c;
    }
    c = 0;
    lb[0] = 0;
    Loop(i,0,n)
    {
        ++c;
        if(b[i]) c = 0;
        lb[i+1] = c;
    }
    c = 0;
    ra[n] = 0;
    LoopR(i,0,n)
    {
        ++c;
        if(!a[i]) c = 0;
        ra[i] = c;
    }
    c = 0;
    rb[n] = 0;
    LoopR(i,0,n)
    {
        ++c;
        if(!b[i]) c = 0;
        rb[i] = c;
    }
    Loop(i,0,n+1)
    {
        if(i&1) cout << 1 + la[i] + rb[i] << ' ';
        else    cout << 1 + lb[i] + ra[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}