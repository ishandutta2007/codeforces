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
//#pragma GCC optimize("O0")

const int N = 300010;
const int lg = 20;
int l[lg][3*N], r[lg][3*N];
int ans[N], ansl[N], ansr[N];
int a[3*N];
int n;

namespace rmq
{
    int l[lg][N], r[lg][N];

    void init(int _k)
    {
        Loop(i,0,3*n)
            l[0][i] = ::l[_k][i],
            r[0][i] = ::r[_k][i];
        Loop(k,0,lg-1)
            for(int i = 0; i+(1<<k) <= 3*n; ++i)
                l[k+1][i] = min(l[k][i], l[k][i+(1<<k)]),
                r[k+1][i] = max(r[k][i], r[k][i+(1<<k)]);
    }

    int getl(int b, int e)
    {
        int k = 31 - __builtin_clz(e-b);
        return min(l[k][b], l[k][e-(1<<k)]);
    }

    int getr(int b, int e)
    {
        int k = 31 - __builtin_clz(e-b);
        return max(r[k][b], r[k][e-(1<<k)]);
    }
}


int main()
{
    FAST;
    cin >> n; if(n==1) Kill(0);
    Loop(i,0,n) cin >> a[i], a[i+2*n] = a[i+n] = a[i];

    Loop(i,0,3*n)
        l[0][i] = i-a[i],
        r[0][i] = i+a[i]+1;
    rmq::init(0);

    Loop(k,0,lg-1)
    {
        Loop(i,0,3*n)
        {
            if(l[k][i] < 0 || r[k][i] >= 3*n) l[k+1][i] = l[k][i], r[k+1][i] = r[k][i];
            else {
                l[k+1][i] = rmq::getl(l[k][i], r[k][i]);
                r[k+1][i] = rmq::getr(l[k][i], r[k][i]);
            }
        }
        rmq::init(k+1);
    }

    Loop(i,0,n) ansl[i] = n+i, ansr[i] = n+i+1;
    LoopR(k,0,lg)
    {
        rmq::init(k);
        Loop(i,0,n)
        {
            int newl = rmq::getl(ansl[i], ansr[i]);
            int newr = rmq::getr(ansl[i], ansr[i]);
            if(newr-newl >= n) continue;
            ans[i] += 1<<k;
            ansl[i] = newl;
            ansr[i] = newr;
        }
    }
    Loop(i,0,n) cout << ans[i]+1 << ' ';
}