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

const int M = 200'010;
pll x[M];
ll d, n, m;
set<pll> f;
ll c = 0;
ll cf;

int main()
{
    FAST;
    cin >> d >> n >> m;
    Loop(i,0,m)
    {
        cin >> x[i].F >> x[i].S;
    }
    sort(x, x+m);
    ll ans = 0;
    f.insert({0, n});
    int it = 0; x[m] = {d, 0};
    cf = n;
    while(1)
    {
        if(cf == 0) Kill(-1);
        int nxt = min(x[it].F, c + f.begin()->S);
        ans += f.begin()->F * (nxt - c);
        ll fbs = f.begin()->S;
        fbs -= (nxt - c);
        cf -= (nxt - c);
        c = nxt;
        if(c == d) Kill(ans);
        if(fbs == 0)
        {
            f.erase(f.begin());
        }
        else
        {
            ll fbf = f.begin()->F;
            f.erase(f.begin());
            f.insert({fbf, fbs});
        }
        if(c == x[it].F)
        {
            f.insert({x[it].S, n});
            cf += n;
            while(cf > n)
            {
                auto end = --f.end();
                if(cf - end->S < n)
                {
                    auto x = *end;
                    x.S = n - (cf - end->S);
                    f.erase(end);
                    f.insert(x);
                    cf = n;
                }
                else
                {
                    cf -= end->S;
                    f.erase(end);
                }
            }
            it++;
        }
    }
}