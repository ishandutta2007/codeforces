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

bool query(pii a, pii b)
{
    printf("? %d %d %d %d\n", a.F+1, a.S+1, b.F+1, b.S+1);
    fflush(stdout);
    bool ans;
    scanf("%hhd", &ans);
    return ans;
}
bool query(int x1, int y1, int x2, int y2)
{
    return query({x1, y1}, {x2, y2});
}

bool ans[51][51];
int n;

void solve_black()
{
    ans[0][0] = 1;
    for(int i = 2; i < n; i += 2)
        ans[0][i] = !ans[0][i-2]^query(0, i-2, 0, i),
        ans[i][0] = !ans[i-2][0]^query(i-2, 0, i, 0);
    for(int i = 1; i < n; ++i)
        for(int j = 1+(!(i&1)); j < n; j += 2)
            ans[i][j] = !ans[i-1][j-1]^query(i-1, j-1, i, j);
}
void solve_white()
{
    ans[0][1] = 0;
    for(int i = 3; i < n; i += 2)
        ans[0][i] = !ans[0][i-2]^query(0, i-2, 0, i),
        ans[i-1][1] = !ans[i-3][1]^query(i-3, 1, i-1, 1);
    ans[n-1][1] = !ans[n-3][1]^query(n-3, 1, n-1, 1);
    for(int i = 1; i < n; i += 2)
        ans[i][0] = !ans[i+1][1]^query(i,0,i+1,1);
    for(int i = 1; i < n; ++i)
        for(int j = 2+(!(i&1)); j < n; j += 2)
            ans[i][j] = !ans[i-1][j-1]^query(i-1, j-1, i, j);
}

void reverse_white()
{
    for(int i = 0; i < n; ++i)
        for(int j = !(i&1); j < n; j += 2)
            ans[i][j] = !ans[i][j];
}

void check_white()
{
    for(int k = 0; k+3 <= 2*n-2; ++k)
    {
        int cnt = 0;
        Loop(_,k,k+4)
            cnt += ans[(_+1)/2][_/2];
        if(cnt%2) continue;
        int r = k+3;
        if(query((k+1)/2, k/2, (r+1)/2, r/2) != (ans[(k+1)/2][k/2] == ans[(r+1)/2][r/2]))
            reverse_white();
        break;
    }
}

void out()
{
    printf("!\n");
    Loop(i,0,n){
        Loop(j,0,n)
            printf("%d", ans[i][j]);
        printf("\n");
    }
    fflush(stdout);
}

int main()
{
    scanf("%d", &n);
    solve_black();
    solve_white();
    check_white();
    out();
}