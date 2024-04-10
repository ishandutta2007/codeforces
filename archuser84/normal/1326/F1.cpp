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

const int N = 14;
const int N_2 = 7;
bool A[N][N];
int l, r;
int n;

int a[N_2], b[N_2];
ll ans[1<<(N-1)];
ll ansl[1<<(N_2-1)][N], ansr[1<<(N_2-1)][N];

void make_b()
{
    int x = 0, y = 0, cur = 0;
    while(y < r)
    {
        if(x >= l || a[x] > cur)
            b[y++] = cur;
        else
            x++;
        cur++;
    }
}

void solve_for_ab()
{
    memset(ansl, 0, sizeof(ansl));
    memset(ansr, 0, sizeof(ansr));
    do
    {
        int mask = 0;
        Loop(i,1,l)
        {
            mask <<= 1;
            mask += A[a[i]][a[i-1]];
        }
        ansl[mask][a[l-1]]++;
    }while(next_permutation(a, a+l));
    do
    {
        int mask = 0;
        Loop(i,1,r)
        {
            mask <<= 1;
            mask += A[b[i]][b[i-1]];
        }
        ansr[mask][b[0]]++;
    }while(next_permutation(b, b+r));
    Loop(x,0,l)
        Loop(y,0,r)
            Loop(mask1,0,1<<(l-1))
                Loop(mask2,0,1<<(r-1))
                    ans[(mask1 << r) + (A[a[x]][b[y]] << (r-1)) + mask2] +=
                        ansl[mask1][a[x]] * ansr[mask2][b[y]];
}

void solve14()
{
    l = 7; r = n-l;
    for(a[0] = 0; a[0] < n; a[0]++)
        for(a[1] = a[0]+1; a[1] < n; a[1]++)
            for(a[2] = a[1]+1; a[2] < n; a[2]++)
                for(a[3] = a[2]+1; a[3] < n; a[3]++)
                    for(a[4] = a[3]+1; a[4] < n; a[4]++)
                        for(a[5] = a[4]+1; a[5] < n; a[5]++)
                            for(a[6] = a[5]+1; a[6] < n; a[6]++)
                                make_b(), solve_for_ab();
    Loop(i,0,1<<(n-1))
        cout << ans[i] << ' ';
}

void solve7()
{
    l = 1; r = n-l;
    for(a[0] = 0; a[0] < n; a[0]++)
        make_b(), solve_for_ab();
    Loop(i,0,1<<(n-1))
        cout << ans[i] << ' ';
}

int main()
{
    FAST;
    cin >> n;
    string s;
    Loop(i,0,n)
    {
        cin >> s;
        Loop(j,0,n)
            A[i][j] = s[j] == '1';
    }
    if(n > 7)
        solve14();
    else
        solve7();
}