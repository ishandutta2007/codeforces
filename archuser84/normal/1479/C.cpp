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

int main()
{
    int l, r;
    cin >> l >> r; r -= l;
    vector<pair<pii, int>> ans;
    int c = 2;
    int k = 1;
    while(k <= r)
    {
        Loop(i,1,c) ans.push_back({{i, c}, k});
        r -= k;
        k *= 2;
        ++c;
    }
    int p = k-1;
    k = 1;
    Loop(i,2,100)
    {
        if(r&1)
        {
            ans.push_back({{i, c}, p});
            p += k;
        }
        p -= k;
        k *= 2;
        r >>= 1;
        if(!r) break;
    }
    Loop(i,1,32) ans.push_back({{i, 32}, l});
    cout << "YES\n32 " << ans.size() << "\n";
    for(auto e : ans)
    {
        cout << e.F.F << ' ' << e.F.S << ' ' << e.S << '\n';
    }
}