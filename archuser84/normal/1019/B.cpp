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
int n;

int query(int i)
{
    int x, y;
    printf("? %d\n", i+1);
    fflush(stdout);
    scanf("%d", &x);
    printf("? %d\n", i+n+1);
    fflush(stdout);
    scanf("%d", &y);
    return x - y;
}

int bin()
{
    int l = 1, r =  n-1;
    int x = query(0);
    if(x == 0) return 0;
    x /= abs(x);
    while(l < r)
    {
        int m = (l+r)/2;
        int t = query(m);
        if(t == 0) return m;
        if(l+1 == r) return r;
        t /= abs(t);
        if(t == x) l = m+1;
        else       r = m-1;
    }
    return l;
}

int terminate(int x)
{
    printf("! %d\n", x);
    fflush(stdout);
    return 0;
}

int main()
{
    scanf("%d", &n);
    if(n&3) return terminate(-1);
    n >>= 1;
    return terminate(bin()+1);
}