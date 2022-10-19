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

bool a[1000][1000];

inline void add(int i, int j){a[i][j] = a[j][i] = 1;}

int solve(int n, int& j)
{
    if(n == 1){add(0, j); return 1;}
    int tmp = j;
    add(j,j+1);
    add(j,j+2);
    add(j+3,j+1);
    add(j+3,j+2);
    j += 3;
    int x = solve(n/2, j);
    if(n&1)
    {
        add(0,j+1);
        Loop(i,0,x) add(j+i+1, j+i+2);
        add(j+x+1, tmp);
        j += x+1;
    }
    return x+2;
}

int main()
{
    FAST;
    int n;
    cin >> n;
    int tmp = 1;
    solve(n, tmp);
    cout << tmp+1 << '\n';
    Loop(i,0,tmp+1)
    {
        Loop(j,0,tmp+1)
            cout << "N\0Y"[2*a[i][j]];
        cout << '\n';
    }
}