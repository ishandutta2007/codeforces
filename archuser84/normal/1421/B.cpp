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

const int N = 210;
char a[N][N];
int n;

void solve()
{
    cin >> n;
    Loop(i,0,n){
        cin >> a[i];
        Loop(j,0,n)
            a[i][j] -= '0';
    }
    if(a[0][1] + a[1][0] + !a[0][2] + !a[1][1] + !a[2][0] < 3)
    {
        cout << a[0][1] + a[1][0] + !a[0][2] + !a[1][1] + !a[2][0] << '\n';
        if(a[0][1])
            cout << "1 2\n";
        if(a[1][0])
            cout << "2 1\n";
        if(!a[0][2])
            cout << "1 3\n";
        if(!a[1][1])
            cout << "2 2\n";
        if(!a[2][0])
            cout << "3 1\n";
    }
    else
    {
        cout << !a[0][1] + !a[1][0] + a[0][2] + a[1][1] + a[2][0] << '\n';
        if(!a[0][1])
            cout << "1 2\n";
        if(!a[1][0])
            cout << "2 1\n";
        if(a[0][2])
            cout << "1 3\n";
        if(a[1][1])
            cout << "2 2\n";
        if(a[2][0])
            cout << "3 1\n";
    }
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
        solve();
}