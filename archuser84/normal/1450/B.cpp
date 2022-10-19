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

const int N = 110;
pii pnt[N];
int n, k;

inline int dis(pii a, pii b){return abs(a.F-b.F) + abs(a.S-b.S);}

bool check(int i)
{
    Loop(j,0,n)
    {
        if(dis(pnt[i], pnt[j]) > k) return 0;
    }
    return 1;
}

void solve()
{
    cin >> n >> k;
    Loop(i,0,n)
        cin >> pnt[i].F >> pnt[i].S;
    Loop(i,0,n)
    {
        if(check(i))
        {
            cout << "1\n";
            return;
        }
    }
    cout << "-1\n";
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