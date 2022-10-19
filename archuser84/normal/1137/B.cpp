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

const int N = 500'010;
const int bs = 31;
const int mod = 1e9 + 7;
char s[N], t[N];
int cnt[2]={};
int n, m;

void rem()
{
    while(cnt[0]--) cout << 0;
    while(cnt[1]--) cout << 1;
}

int main()
{
    FAST;
    cin >> s >> t;
    n = strlen(s); m = strlen(t);
    Loop(i,0,n) cnt[s[i]-'0']++;
    int ans = 0;
    ll h1 = 0, h2 = 0, h22 = 1;
    Loop(i,0,m-1)
    {
        h1 = h1*bs + (t[i]-'0'); h1 %= mod;
        h2 = h2 + h22*(t[m-1-i]-'0'); h2 %= mod;
        h22 = h22*bs; h22 %= mod;
        if(h1 == h2) ans = i+1;
    }
    Loop(i,0,m)
    {
        if(!cnt[t[i]-'0']) {rem(); return 0;}
        cnt[t[i]-'0']--;
        cout << t[i];
    }
    for(int i = ans;; i++)
    {
        if(i >= m) i = ans;
        if(!cnt[t[i]-'0']) {rem(); return 0;}
        cnt[t[i]-'0']--;
        cout << t[i];
    }
}