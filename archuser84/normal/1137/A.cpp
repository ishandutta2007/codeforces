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

const int N = 1010;
int a[N][N];
vector<int> h[N], v[N];
int n, m;

int main()
{
    FAST;
    cin >> n >> m;
    Loop(i,0,n) Loop(j,0,m) cin >> a[i][j];
    Loop(i,0,n)
    {
        set<int> s;
        Loop(j,0,m)
            s.insert(a[i][j]);
        for(int x : s)
            h[i].push_back(x);
    }
    Loop(j,0,m)
    {
        set<int> s;
        Loop(i,0,n)
            s.insert(a[i][j]);
        for(int x : s)
            v[j].push_back(x);
    }
    Loop(i,0,n){
        Loop(j,0,m)
            cout << max(lower_bound(all(h[i]), a[i][j])-h[i].begin(), lower_bound(all(v[j]), a[i][j])-v[j].begin()) +
                    max(h[i].size()-(lower_bound(all(h[i]), a[i][j])-h[i].begin()), v[j].size()-(lower_bound(all(v[j]), a[i][j])-v[j].begin())) << ' ';
        cout << '\n';
    }
}