#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 300'010;
int n;
int a[N];
vector<pii> ans;

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
        cin >> a[i];
    int free = n;
    vector<pii> tak;
    vector<int> last;
    LoopR(i,0,n)
    {
        if(a[i] == 0)
            continue;
        if(a[i] == 1)
        {
            ans.push_back({free, i+1});
            tak.push_back({free, i+1});
            free--;
            continue;
        }
        if(a[i] == 2)
        {
            if(tak.size() == 0)
                Kill(-1);
            ans.push_back({tak.back().F, i+1});
            last.push_back(i+1);
            tak.pop_back();
            continue;
        }
        if(a[i] == 3)
        {
            int x;
            if(last.size() > 0)
            {
                x = last.back();
                last.pop_back();
            }
            else if(tak.size() > 0)
            {
                x = tak.back().S;
                tak.pop_back();
            }
            else
                Kill(-1);
            ans.push_back({free, i+1});
            ans.push_back({free, x});
            last.push_back(i+1);
            free--;
            continue;
        }
    }
    if(free < 0)
        Kill(-1);
    cout << ans.size() << '\n';
    for(auto p : ans)
    {
        cout << p.first << ' ' << p.second << '\n';
    }
}