#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 10;
int n;
const int r[] = {1, 5, 10, 50};
int x[N] = {};
bool add(int i = n-1)
{
    if(i < 0) return 0;
    x[i]++;
    if(x[i] == 4)
    {
        x[i] = 0;
        return add(i-1);
    }
    return 1;
}
int cnt()
{
    int ans = 0;
    Loop(i,0,n)
        ans += r[x[i]];
    return ans;
}
bool e[610]={};
int naive()
{
    while(1)
    {
        e[cnt()] = 1;
        if(!add()) break;
    }
    int ans = 0;
    Loop(i,0,610)
        ans += e[i];
    return ans;
}

int main()
{
    FAST;
    cin >> n;
    if(n <= N) cout << naive() << '\n';
    else cout << 49LL*n - 247LL << '\n';
}