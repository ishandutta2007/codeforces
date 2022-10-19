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
//#pragma GCC optimize ("Ofast")
using namespace std;

const int N = 502;
int a[N], b[N];
int n, m;
short dp[N][N][N] = {};
int cmpr[N];

int main()
{
    FAST;
    map<int, vector<int*>> cmp;
    cin >> n;
    Loop(i,0,n)
    {
        cin >> a[i];
        cmp[a[i]].push_back(&a[i]);
    }
    cin >> m;
    Loop(i,0,m)
    {
        cin >> b[i];
        cmp[b[i]].push_back(&b[i]);
    }
    int dcnt = 0;
    for(auto& v : cmp)
    {
        if(v.S.size() == 1){
            *v.S[0] = N-1;
        }
        else {
            cmpr[dcnt] = v.F;
            for(int* x : v.S) *x = dcnt;
            ++dcnt;
        }
    }
    Loop(i,1,n+1)
    {
        Loop(j,1,m+1)
        {
            Loop(x,0,dcnt+1)
            {
                dp[i][j][x] = max(dp[i-1][j][x], dp[i][j-1][x]);
                if(a[i-1] == b[j-1] && a[i-1] < x)
                    dp[i][j][x] = max<short>(dp[i][j][x], dp[i-1][j-1][a[i-1]] + 1);
            }
        }
    }
    vector<int> ans;
    int i = n, j = m, x = dcnt;
    while(i && j)
    {
        auto aa = dp[i-1][j][x];
        auto bb = dp[i][j-1][x];
        auto cc = dp[i-1][j-1][a[i-1]] + 1;
        if(a[i-1] == b[j-1] && a[i-1] < x && cc > max(aa, bb)){
            ans.push_back(a[i-1]);
            x = a[i-1]; i--; j--;
        }
        else if(aa > bb) i--;
        else j--;
    }
    reverse(all(ans));
    cout << dp[n][m][dcnt] << '\n';
    for(auto x : ans)
        cout << cmpr[x] << ' ';
}