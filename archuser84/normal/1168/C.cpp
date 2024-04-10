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
const int logN = 19;
int dp[N][190];
int a[N];
int n;

int& gp(int i, int x, int y)
{
    if(x > y) swap(x, y);
    return dp[i][190 - (20-x)*(19-x)/2 + (y-x)];
}

int nxt(int i, int v)
{
    int ans = INT_MAX;
    Loop(x,0,logN){
        if(!(v&(1<<x))) continue;
        Loop(y,0,logN)
        {
            if(!((~v)&(1<<y))) continue;
            ans = min(ans, gp(i,x,y));
        }
    }
    return ans;
}

int main()
{
    FAST;
    int q;
    cin >> n >> q;
    Loop(i,0,n)
        cin >> a[i];

    // base
    Loop(x,0,logN) Loop(y,0,logN)
    {
        gp(n-1,x,y) = INT_MAX;
    }

    // step
    LoopR(i,1,n)
    {
        Loop(x,0,logN) Loop(y,0,logN)
        {
            if((a[i]&(1<<x)) && (a[i]&(1<<y))) gp(i-1,x,y) = i;
            else                               gp(i-1,x,y) = gp(i,x,y);
        }
    }

    while(q--)
    {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int x = a[l];
        while(1) {
            l = nxt(l, x);
            if(l > r) break;
            x |= a[l];
        }
        cout << ((x&a[r])? "Shi\n": "Fou\n");
    }
}