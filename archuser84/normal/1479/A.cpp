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
//#pragma GCC optimize ("O0")
using namespace std;

const int N = 200'010;
int n;

int query(int i)
{
    printf("? %d\n", i+1);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x-1;
}

int solve(int b, int e)
{
    if(e-b <= 4)
    {
        int mn = N, ans = b;
        Loop(i,b,e)
        {
            int x = query(i);
            if(x < mn)
            {
                mn = x;
                ans = i;
            }
        }
        return ans;
    }
    int m = (b+e)/2;
    int l = query(m-1);
    int r = query(m);
    if(l < r) return solve(b, m);
    else      return solve(m, e);
}

int main()
{
    //FAST;
    cin >> n;
    printf("! %d\n", solve(0, n) + 1);
    fflush(stdout);
}