///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;

int lf;
int a[24];
int n;

vector<int> A[24];

int dfs(int v=0)
{
    int cnt = 1;
    int ans = 0;
    for(int u : A[v])
    {
        int x = dfs(u);
        if(x == -1) return -1;
        ans += x;
        cnt += a[u];
    }
    if(cnt > a[v]) return -1;
    if(a[v] == 2) return -1;
    if(cnt == a[v] && A[v].size() == 1) return -1;
    return ans + a[v] - cnt;
}

bool solve(int i=1)
{
    if(i == n) return dfs() == lf;
    Loop(j,0,i)
    {
        A[j].push_back(i);
        if(solve(i+1)) return 1;
        A[j].pop_back();
    }
    return 0;
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n) cin >> a[i], lf += a[i] == 1;
    if(lf*2 < n+1) Kill("NO");
    sort(a, a+n);
    reverse(a, a+n);
    while(n && a[n-1] == 1) --n;
    if(n==0) Kill(YN(lf==1));
    cout << YN(solve()) << '\n';
    /*Loop(i,0,n)
    {
        cerr << i << " (" << a[i] << "): ";
        for(int j : A[i]) cerr << j << ' ';
        cerr << '\n';
    }*/
}