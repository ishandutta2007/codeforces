#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 200'010;
int n;
ll x, y;
string a;

int main()
{
    FAST;
    cin >> n >> x >> y;
    cin >> a;
    int bcnt = 0;
    Loop(i,1,n)
    {
        if(a[i] == '1' && a[i-1] == '0')
            bcnt++;
    }
    if(a[n-1] == '0')
        bcnt++;
    if(!bcnt) Kill(0);
    if(x > y) cout << y*bcnt << '\n';
    else cout << x*(bcnt-1)+y << '\n';
}