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

const int K = 22;
const int N = (1<<K);
int bad[N] = {};
int n, k;
string s;
//int l1 = 0;

inline void add(unsigned int& x, bool bit)
{
    x <<= 1;
    if(bit) x ^= 1;
    if(k <= 31) x &= (1<<k)-1;
}

void solve(int t)
{
    cin >> n >> k;
    cin >> s; s.push_back('0');
    unsigned int x = 0;
    int c = 0;
    for(; c < k; ++c) add(x, !(s[c]-'0'));
    int l1 = 0;
    while(s[l1] == '1') ++l1;
    if(c - l1 <= K) bad[x] = t;
    while(c < n)
    {
        add(x, !(s[c++]-'0'));
        while(c - l1 > k) ++l1;
        while(s[l1] == '1') ++l1;
        if(c - l1 <= K) bad[x] = t;
    }
    int ans = -1;
    Loop(i,0,1 << min(k, K)) if(bad[i] != t) {ans = i; break;}
    if(ans == -1){cout << "NO\n"; return;}
    cout << "YES\n";
    string cans;
    Loop(_,0,k) cans.push_back((ans&1)+'0'), ans >>= 1;
    reverse(all(cans));
    cout << cans << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve(t+1);
}