///
///    "Your next line is..."
///
///                                    -Joseph Joestar

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

const int N = 100'010;
int n, k;

bool ask(int a, int b)
{
    char s[10];
    ++a; ++b;
    printf("1 %d %d\n", a, b);
    fflush(stdout);
    scanf("%s", s);
    return s[0] == 'T';
}

void trm(int a, int b)
{
    ++a; ++b;
    printf("2 %d %d\n", a, b);
    fflush(stdout);
    exit(0);
}

int bin(int l, int r)
{
    if(l == r) return l;
    int m = (l+r)/2;
    if(ask(m, m+1)) return bin(l, m);
    else            return bin(m+1, r);
}

int main()
{
    scanf("%d%d", &n, &k);
    int x = bin(0, n-1);
    int y;
         if(x == n-1) y = bin(0, n-2);
    else if(x == 0)   y = bin(1, n-1);
    else
    {
        y = bin(x+1, n-1);
        if(ask(y, x)) trm(x, y);
        y = bin(0, x-1);
    }
    trm(x, y);
}