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

const int N = 200'010;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> ans(m+10), cnt(n+10);
    vector<vector<int>> f(m+10);
    Loop(i,0,m)
    {
        int k;
        cin >> k;
        Loop(_,0,k)
        {
            int x;
            cin >> x; x--;
            f[i].push_back(x);
        }
        if(k == 1)
        {
            ans[i] = f[i][0];
            cnt[f[i][0]]++;
        }
    }
    Loop(i,0,m)
    {
        if(f[i].size() == 1) continue;
        if(cnt[f[i][0]] >= (m+1)/2) ans[i] = f[i][1];
        else                        ans[i] = f[i][0];
        cnt[ans[i]]++;
    }
    Loop(i,0,n) if(cnt[i] > (m+1)/2) {cout << "NO\n"; return;}
    cout << "YES\n";
    Loop(i,0,m) cout << ans[i]+1 << ' ';
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}