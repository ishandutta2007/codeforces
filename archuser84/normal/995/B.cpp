#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
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

const int N = 110;
int a[2*N];

int main()
{
    FAST;
    int n;
    cin >> n;
    Loop(i,0,2*n)
        cin >> a[i];
    int ans = 0;
    for(int i = 2*n-1; i >= 0; i -= 2)
    {
        int k;
        for(k = i-1; k >= 0; --k)
        {
            if(a[k] == a[i]) break;
        }
        ans += i-k-1;
        for(int j = k; j<i; ++j) swap(a[j], a[j+1]);
    }
    cout << ans << '\n';
}