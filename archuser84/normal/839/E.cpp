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

const int N = 40;
int ans = 0;
int l[1<<(N/2)];
int fl, cl, n;
double k;
bool A[N][N];

bool checkl(int x)
{
    Loop(i,0,fl) Loop(j,i+1,fl)
    {
        if((x&(1<<j)) && (x&(1<<i)) && !A[i][j]) return 0;
    }
    return 1;
}
bool checkr(int x)
{
    Loop(i,0,cl) Loop(j,i+1,cl)
    {
        if((x&(1<<j)) && (x&(1<<i)) && !A[i+fl][j+fl]) return 0;
    }
    return 1;
}
int maker(int x)
{
    int ans = (1<<fl)-1;
    Loop(i,0,cl) Loop(j,0,fl)
    {
        if((x&(1<<i)) && !A[i+fl][j]) ans = (ans|(1<<j))^(1<<j);
    }
    return ans;
}

int main()
{
    FAST;
    cin >> n >> k;
    fl = n/2, cl = (n+1)/2;
    Loop(i,0,n) Loop(j,0,n) cin >> A[i][j];
    Loop(i,0,1<<fl)
    {
        l[i] = 0;
        if(checkl(i)) l[i] = __builtin_popcount(i);
        else
        {
            Loop(j,0,fl)
                l[i] = max(l[i], l[(i|(1<<j))^(1<<j)]);
        }
    }
    Loop(i,0,1<<cl)
    {
        if(checkr(i))
            ans = max(ans, __builtin_popcount(i) + l[maker(i)]);
    }
    cout << fixed << setprecision(9);
    cout << (k/ans)*(k/ans)*(ans*(ans-1)/2) << '\n';
}