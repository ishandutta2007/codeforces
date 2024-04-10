#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

const int N = 310;
string a[N];
int n;

int check(int k)
{
    int ans = 0;
    Loop(i,0,n)
    {
        Loop(j,0,n)
        {
            switch((i+j+k)%3)
            {
                case 0: ans += a[i][j] == 'O'; break; // bayad X bashe
                case 1: ans += a[i][j] == 'X'; break; // bayad O bashe
                case 2: break;
            }
        }
    }
    return ans;
}
void Do(int k)
{
    Loop(i,0,n)
    {
        Loop(j,0,n)
        {
            switch((i+j+k)%3)
            {
                case 0: if(a[i][j] != '.') a[i][j] = 'X'; break; // bayad X bashe
                case 1: if(a[i][j] != '.') a[i][j] = 'O'; break; // bayad O bashe
                case 2: break;
            }
        }
    }
}

void solve()
{
    cin >> n;
    int cnt = 0;
    Loop(i,0,n) {
        cin >> a[i];
        Loop(j,0,n)
        {
            cnt += a[i][j] != '.';
        }
    }
    Loop(k,0,3)
    {
        if(check(k) <= (cnt/3))
        {
            Do(k);
            Loop(i,0,n)
            {
                cout << a[i] << '\n';
            }
            return;
        }
    }
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}