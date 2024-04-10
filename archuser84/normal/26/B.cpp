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

char s[1'000'010];

int main()
{
    scanf("%s", s);
    int cnt = 0;
    int ans = 0;
    int now = 0;
    for(int i = 0; s[i]; ++i)
    {
        ++now;
        if(s[i] == '(') ++cnt;
        else            --cnt;
        if(cnt < 0) {--now; cnt = 0;}
        ans = now - cnt;
    }
    printf("%d\n", ans);
}