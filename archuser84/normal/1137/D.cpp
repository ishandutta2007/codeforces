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

bool a[10][10];

void up()
{
    static string dmy;
    fflush(stdout);
    int t;
    cin >> t;
    bool ans = 0;
    memset(a, 0, sizeof a);
    while(t--)
    {
        cin >> dmy;
        for(char c : dmy)
            for(char d : dmy)
                a[c-'0'][d-'0'] = 1;
    }
}

int main()
{
    while(1)
    {
        printf("next 0 1\n"); up();
        printf("next 0\n"); up();
        if(a[0][1]) break;
    }
    while(1)
    {
        printf("next 1 2\n"); up();
        if(a[0][1]) break;
    }
    while(1)
    {
        printf("next 2 3 4 5 6 7 8 9\n"); up();
        if(a[2][3]) break;
    }
    while(!a[0][2])
    {
        printf("next 0 1\n"); up();
    }
    printf("done\n");
    fflush(stdout);
}