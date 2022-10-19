#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 300'010;
char a[N];
int b[N];
int n;

void solve()
{
    cin >> n;
    cin >> a;
    int l = 0;
    int cnt = 0;
    Loop(i,1,n)
    {
        if(a[i] != a[i-1])
            b[cnt++] = i-l,
            l = i;
    }
    b[cnt++] = n-l;
    int p1=0, p2=0;
    int ans = 0;
    while(1)
    {
        while(p1 < cnt && b[p1] == 1)
            ++p1;
        if(p1 == cnt)
            break;
        ++ans;
        --b[p1];
        ++p2;
        p1 = max(p1, p2);
    }
    cout << ans+(cnt-p2+1)/2 << '\n';
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