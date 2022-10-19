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

const int N = 200'010;
int cnt[N];
set<int> s;

int main()
{
    FAST;
    int n;
    cin >> n;
    int ans = 0;
    Loop(i,0,n)
    {
        int x;
        cin >> x;
        if(cnt[x] < 2) ++ans, ++cnt[x];
        ++cnt[x];
        s.insert(x);
        vector<int> tmp;
        for(int y : s)
        {
            --cnt[y];
            if(cnt[y] == 0) tmp.push_back(y);
        }
        for(int y : tmp)
        {
            s.erase(y);
        }
    }
    cout << ans << '\n';
}