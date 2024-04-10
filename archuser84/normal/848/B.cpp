///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize("O0")

const int N = 100'010;
map<int, vector<pii>> h;
map<int, vector<pii>> v;
int g[N], p[N], t[N];
pii ans[N];
int n;
int W, H;

int main()
{
    FAST;
    cin >> n >> W >> H;
    Loop(i,0,n)
    {
        cin >> g[i] >> p[i] >> t[i]; g[i]--;
        if(g[i] == 0) v[t[i]-p[i]].push_back({p[i], i});
        else          h[t[i]-p[i]].push_back({p[i], i});
    }
    for(auto& [a, b] : h) sort(all(b));
    for(auto& [a, b] : v) sort(all(b));
    for(auto& [key, vec] : h)
    {
        Loop(i,0,vec.size())
        {
            int j = i+v[key].size();
            if(j < vec.size())
            {
                ans[vec[i].S] = {W, vec[j].F};
            }
            else
            {
                ans[vec[i].S] = {v[key][vec.size()-i-1].F, H};
            }
        }
    }
    for(auto& [key, vec] : v)
    {
        Loop(i,0,vec.size())
        {
            int j = i+h[key].size();
            if(j < vec.size())
            {
                ans[vec[i].S] = {vec[j].F, H};
            }
            else
            {
                ans[vec[i].S] = {W, h[key][vec.size()-i-1].F};
            }
        }
    }
    Loop(i,0,n)
    {
        cout << ans[i].F << ' ' << ans[i].S << '\n';
    }
}