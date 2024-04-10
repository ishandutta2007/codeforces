#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int a[64] = {};
int n;

int solve()
{
    cin >> n;
    int n = ::n;
    memset(a,0,256);
    while(n--)
    {
        int x;
        cin >> x;
        for(int i=0; x; i++)
        {
            a[i] += x&1;
            x >>= 1;
        }
    }
    LoopR(i,0,64)
    {
        if((a[i]&1) == 0)
            continue;
        if((a[i]&3) == 1)
            return 1;
        if((::n - a[i]) & 1)
            return 1;
        else
            return -1;
    }
    return 0;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        switch(solve())
        {
            case -1: cout << "LOSE\n"; break;
            case  0: cout << "DRAW\n"; break;
            case  1: cout << "WIN\n";  break;
        }
    }
}