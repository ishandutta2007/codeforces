#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 200'010;
const int M = 30;
int a[N];
int n;

inline bool bit(int x, int b){return (x>>b)&1;}

int bin(int l, int r, int b)
{
    while(r-l > 1)
    {
        int m = (l+r-1)/2;
        if(bit(a[m], b))
            r = m+1;
        else
            l = m+1;
    }
    return l;
}

int dc(int l, int r, int b = M)
{
    if(r-l <= 2)
        return r-l;
    if(bit(a[l], b) == bit(a[r-1], b))
        return dc(l, r, b-1);
    int m = bin(l, r, b);
    return max(dc(l, m, b-1), dc(m, r, b-1)) + 1;
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
        cin >> a[i];
    sort(a, a+n);
    cout << n - dc(0, n) << '\n';
}