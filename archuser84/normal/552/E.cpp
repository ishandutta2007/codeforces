#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#pragma GCC optimize ("O1")
using namespace std;

const int N = 5'010;
char s[N];
ll x[N];
vector<int> muls;
int n;

template<class T>
T* find_plus(T* b, T* e){while(*b != '+' && b < e) ++b; return b;}

template<class T>
ll expr(T* b, T* e)
{
    if(b >= e) return 0;
    auto m = find_plus(b, e);
    ll ans = 1;
    for(; b < m; b += 2)
        ans *= *b-'0';
    return ans + expr(m+1, e);
}

int main()
{
    FAST;
    cin >> s;
    n = strlen(s);
    muls.push_back(-1);
    Loop(i,0,n)
        if(s[i] == '*')
            muls.push_back(i);
    muls.push_back(n);
    ll ans = expr(s, s+n);
    int k = muls.size();
    Loop(i,0,k)
    {
        Loop(j,i+1,k)
        {
            ll br = expr(s+muls[i]+1, s+muls[j]);
            int sz = muls[j]-muls[i]-1;
            Loop(t, 0, muls[i]+1)
                x[t] = s[t];
            x[muls[i]+1] = br + '0';
            Loop(t, muls[j], n)
                x[t-sz+1] = s[t];
            ans = max(ans, expr(x, x+n-sz+1));
        }
    }
    cout << ans << '\n';
}