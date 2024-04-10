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

int n, m;

int main()
{
    FAST;
    cin >> n >> m;
    int p1 = 0, p2 = n*m-1;
    while(1)
    {
        cout << (p1/m)+1 << ' ' << (p1%m)+1 << '\n';
        p1++;
        if(p1 > p2) break;

        cout << (p2/m)+1 << ' ' << (p2%m)+1 << '\n';
        p2--;
        if(p1 > p2) break;
    }
}