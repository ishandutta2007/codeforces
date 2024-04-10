///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

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

const int N = 510;
int n, m;

bool a[N][N];
char s[N][N];

void solve()
{
    cin >> n >> m;
    Loop(i,0,n) cin >> s[i];
    Loop(i,0,n)
    {
        for(int j = 1-(m%3==1); j < m; j += 3)
        {
            s[i][j] = 'X';
        }
    }
    for(int j = 2-(m%3==1); j < m-1; j += 3)
    {
        bool good = 0;
        Loop(i,0,n)
        {
            if(s[i][j] == 'X' || s[i][j+1] == 'X')
            {
                s[i][j] = s[i][j+1] = 'X';
                good = 1;
                break;
            }
        }
        if(!good) s[0][j] = s[0][j+1] = 'X';
    }
    Loop(i,0,n) cout << s[i] << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}