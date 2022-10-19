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
int a[N], b[N];
int n;

int main()
{
    FAST;
    cin >> n;
    int p1=-1, p2=-1;
    Loop(i,0,n) {cin >> a[i]; if(a[i] == 1) p1 = i;}
    Loop(i,0,n) {cin >> b[i]; if(b[i] == 1) p2 = i;}
    while(1)
    {
        do p1 = (p1+1)%n; while(a[p1] == 0);
        do p2 = (p2+1)%n; while(b[p2] == 0);
        if(a[p1] == 1) break;
        if(a[p1] != b[p2]) Kill("NO");
    }
    Kill("YES");
}