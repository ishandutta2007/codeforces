#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll int64_t
#define ull uint64_t
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

int find(string& s, int l, char c)
{
    Loop(i,l,s.size()) if(s[i] == c) return i;
    return -1;
}

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<pii> ans;
    int l = 0;
    while(k > 1)
    {
        int r;
        r = find(s, l, '(');
        ans.emplace_back(l+1, r+1);
        reverse(s.begin()+l, s.begin()+r+1);
        ++l;
        r = find(s, l, ')');
        ans.emplace_back(l+1, r+1);
        reverse(s.begin()+l, s.begin()+r+1);
        ++l;
        --k;
    }
    int re = (s.size()-l)/2;
    Loop(i,0,re)
    {
        int r = find(s, l, '(');
        ans.emplace_back(l+1, r+1);
        reverse(s.begin()+l, s.begin()+r+1);
        ++l;
    }
    Loop(i,0,re)
    {
        int r = find(s, l, ')');
        ans.emplace_back(l+1, r+1);
        reverse(s.begin()+l, s.begin()+r+1);
        ++l;
    }
    assert(ans.size() == s.size());
    cout << s.size() << '\n';
    for(auto x : ans)
    {
        cout << x.F << ' ' << x.S << '\n';
    }
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}