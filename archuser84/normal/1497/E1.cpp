///
///    "I, Giorno Giovanna, have a dream."
///
///                                    -Giorno Giovanna

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize ("O0")

const int MAX = 1e7 + 10;
const int N = 200'010;
const int K = 21;
int code[MAX];
bool prime[MAX];
int dp[K][N];
int a[N];
int n, k;
int ls[MAX];
short tls[MAX];

void solve(int t)
{
    cin >> n >> k;
    Loop(i,0,n) cin >> a[i];
    Loop(i,0,K) dp[i][0] = 0;
    int lst[K]; Loop(i,0,K) lst[i] = -1;
    Loop(i,0,n)
    {
        if(tls[code[a[i]]] == t)
        {
            bool flag = 0;
            Loop(j,0,K)
            {
                if(lst[j] <= ls[code[a[i]]])
                {
                    LoopR(j2,j+1,K) lst[j2] = lst[j2-1];
                    lst[j] = ls[code[a[i]]];
                    break;
                }
            }
        }

        Loop(j,0,K){
            dp[j][i+1] = N;
            Loop(r,0,j+1)
                dp[j][i+1] = min(dp[j-r][lst[r]+1]+1, dp[j][i+1]);
        }
        tls[code[a[i]]] = t;
        ls[code[a[i]]] = i;
    }
    cout << dp[k][n] << '\n';
}

int main()
{
    FAST;
    fill(code, code+MAX, 1);
    fill(prime, prime+MAX, 1);
    Loop(x,2,MAX)
    {
        if(!prime[x]) continue;
        for(ll xi = x, i = 1; xi < MAX; xi *= x, ++i)
        {
            for(int y = xi; y < MAX; y += xi)
            {
                prime[y] = 0;
                if(i&1) code[y] *= x;
                else    code[y] /= x;
            }
        }
    }
    int t;
    cin >> t;
    while(t--) solve(t+10);
}