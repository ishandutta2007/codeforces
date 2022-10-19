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

const int N = 1'010;
char a[N][N], b[N][N];
int n;

void solve()
{
    cin >> n;
    Loop(i,0,n) cin >> a[i];
    Loop(i,0,n) {cin >> b[i]; Loop(j,0,n) b[i][j] ^= a[i][j];}
    Loop(i,1,n)
    {
        bool z = b[i-1][0] ^ b[i][0];
        Loop(j,1,n)
        {
            if((b[i-1][j] ^ b[i][j]) != z)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}