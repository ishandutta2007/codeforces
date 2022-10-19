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
int n, m;
int a[N];

bool check(int x)
{
    int p = 0;
    Loop(i,0,n)
    {
        if(a[i]+x < m)
        {
            if(a[i]+x < p) return 0;
            p = max(a[i], p);
        }
        else
        {
            int r = (a[i]+x)%m;
            if(r >= p) continue;
            p = max(a[i], p);
        }
    }
    return 1;
}

int bin()
{
    int l = 0, r = m-1;
    while(l < r)
    {
        int mid = (l+r)/2;
        if(check(mid))
            r = mid;
        else
            l = mid+1;
    }
    return l;
}

int main()
{
    FAST;
    cin >> n >> m;
    Loop(i,0,n) cin >> a[i];
    cout << bin();
}