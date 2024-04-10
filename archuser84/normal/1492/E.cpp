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

mt19937 rd(time(0));
inline double gettime()
{
    return (double)clock()/CLOCKS_PER_SEC;
}

const int N = 250'010;
int n, m;
int* a[N];
int ans[N];

bool check()
{
    Loop(i,0,n)
    {
        int cnt = 0;
        int r = 0;
        int k[2];
        Loop(j,0,m) {
            cnt += a[i][j] != ans[j];
            if(ans[j] == -1)
                k[r++] = j;
        }
        if(cnt-r > 2) return 0;
        if(r == 2 && rd()&1) swap(k[0], k[1]);
        while(cnt > 2)
        {
            --r;
            ans[k[r]] = a[i][k[r]];
            --cnt;
        }
    }
    return 1;
}

int main()
{
    FAST;
    cin >> n >> m;
    Loop(i,0,n)
    {
        a[i] = new int[m];
        Loop(j,0,m) cin >> a[i][j];
    }
    do
    {
        Loop(j,0,m) ans[j] = a[rd()%n][j];
        ans[rd()%m] = -1;
        ans[rd()%m] = -1;
        if(check())
        {
            cout << "YES\n";
            Loop(j,0,m) cout << abs(ans[j]) << ' ';
            return 0;
        }
    }while(gettime() < 1.9);
    cout << "NO\n";
}