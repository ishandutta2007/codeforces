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

const int N = 100'010;
char a[N];
int k, n;

bool win1()
{
    int cnt = 0;
    Loop(i,k,n)
        cnt += a[i] == '1';
    int l = 0, r = k;
    while(1)
    {
        if(cnt == n-k || cnt == 0)
            return 1;
        if(r == n)
            break;
        cnt += a[l++] == '1';
        cnt -= a[r++] == '1';
    }
    return 0;
}
bool tie1()
{
    int cnt = 0;
    Loop(i,k+1,n)
        cnt += a[i] == '1';
    int l = 0, r = k+1;
    while(1)
    {
        if((a[l] == '1' && cnt > 0) || (a[l] == '0' && cnt < n-r))
            return 1;
        if(r == n)
            break;
        l++;
        cnt -= a[r++] == '1';
    }
    return 0;
}
bool tie2()
{
    int cnt = 0;
    Loop(i,0,k)
        cnt += a[i] == '1';
    int l = 0, r = k;
    while(1)
    {
        if(cnt == k || cnt == 0)
            return 1;
        if(r == n)
            break;
        cnt -= a[l++] == '1';
        cnt += a[r++] == '1';
    }
    return 0;
}

int main()
{
    FAST;
    cin >> n >> k;
    cin >> a;
    if(win1())
        Kill("tokitsukaze");
    if(tie1() || tie2())
        Kill("once again");
    Kill("quailty");
}