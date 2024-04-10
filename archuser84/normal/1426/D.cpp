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

const int N = 200'010;
int a[N];
int dp[N];
int last[N];
unordered_map<ll, pair<bool, int>> lasttmp;
int n;

int main()
{
    FAST;
    cin >> n;
    ll sum = 0;
    lasttmp[0] = {1, 0};
    Loop(i,0,n)
    {
        cin >> a[i];
        sum += a[i];
        auto& x = lasttmp[sum];
        if(x.F)
            last[i] = x.S;
        else
            last[i] = -1;
        x = {1, i+1};
    }
    int lst = -1;
    int ans = 0;
    Loop(i,0,n)
    {
        //cerr << last[i] << ' ';
        if(last[i] > lst)
        {
            lst = i-1;
            ++ans;
        }
    }
    cout << ans << '\n';
}