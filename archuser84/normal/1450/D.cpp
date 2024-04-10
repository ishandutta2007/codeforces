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

const int N = 300'010;
int a[N];
int fp[N];
bool mo[N];
int n;

bool check_one()
{
    Loop(i,0,n)
    {
        if(fp[i] == -1 || mo[i]) return 0;
    }
    return 1;
}

int find(int l, int r, int k)
{
    if(l > r) return 2;
    if(fp[k] == -1) return r-l+2;
    if(mo[k] == 1) return r-l+1;
    if(l == fp[k]) return find(l+1, r, k+1);
    if(r == fp[k]) return find(l, r-1, k+1);
    return r-l+1;
}

void solve()
{
    cin >> n;
    Loop(i,0,n)
        cin >> a[i], a[i]--;
    memset(fp, -1, 4*n);
    memset(mo, 0, n);
    Loop(i,0,n)
    {
        if(fp[a[i]] == -1)
            fp[a[i]] = i;
        else
            mo[a[i]] = 1;
    }
    cout << check_one();
    int x = find(0, n-1, 0);
    Loop(i,2,x) cout << 0;
    Loop(i,x,n+1) cout << 1;
    cout << '\n';
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