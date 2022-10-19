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

int n, k;

int query(int i)
{
    printf("? %d\n", i+1);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}

int terminate(int i)
{
    printf("! %d", i+1);
    return 0;
}

int main()
{
    scanf("%d%d", &n, &k);
    int s = sqrt(n);
    Loop(i,0,s) query(0);
    int c;
    int dmy = -1;
    for(int i = -1;; i += s){
        i %= n;
        if(i == dmy) dmy = ++i;
        int x = query(i);
        if(x > k) {c = i; break;}
    }
    for(int i = c-1;; --i)
    {
        if(i < 0) i += n;
        if(query(i) == k) return terminate(i);
    }
}