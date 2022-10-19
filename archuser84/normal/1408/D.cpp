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

const int N = 2'010;
const int inf = 1'000'000'007;
pii rob[N], lit[N];
bool del[N] = {};
int dis[N], up[N];
int n, m;

void trim()
{
    Loop(i,0,n)
    {
        Loop(j,0,i)
        {
            if(rob[j].F <= rob[i].F && rob[j].S <= rob[i].S)
                {del[i] = true; break;}
            if(rob[j].F >= rob[i].F && rob[j].S >= rob[i].S)
                del[j] = true;
        }
    }
}

void update_dis(int i, int j)
{
    if(dis[i] < lit[j].F - rob[i].F)
    {
        dis[i] = lit[j].F - rob[i].F;
        up[i] = j;
    }
    else if(dis[i] == lit[j].F - rob[i].F)
    {
        if(lit[j].S > lit[up[i]].S)
            up[i] = j;
    }
}

void calc_dis(int i, int cur)
{
    dis[i] = -inf;
    Loop(j,0,m)
        if(lit[j].F - rob[i].F < cur)
            if(rob[i].S <= lit[j].S)
                update_dis(i, j);
}

int solve()
{
    priority_queue<pii> H;
    Loop(i,0,n)
        if(!del[i])
            calc_dis(i, inf),
            H.push({dis[i], i});
    int gr = H.top().F + 1;
    int gu = 0;
    int ans = gr;
    if(ans <= 0)
        return 0;

    auto top = H.top(); H.pop();
    int pre_qued = lit[up[top.S]].S - rob[top.S].S;
    calc_dis(top.S, dis[top.S]);
    H.push({dis[top.S], top.S});
    while(true)
    {
        auto top = H.top();
        H.pop();
        gr = dis[top.S] + 1;
        gu = max(gu, pre_qued + 1);
        pre_qued = lit[up[top.S]].S - rob[top.S].S;
        calc_dis(top.S, dis[top.S]);
        if(gr < 0)
        {
            ans = min(ans, gu);
            break;
        }
        ans = min(ans, gu + gr);
        H.push({dis[top.S], top.S});
    }
    return ans;
}

void Input()
{
    cin >> n >> m;
    Loop(i,0,n)
        cin >> rob[i].F >> rob[i].S;
    Loop(i,0,m)
        cin >> lit[i].F >> lit[i].S;
}

int main()
{
    FAST;
    Input();
    trim();
    cout << solve() << '\n';
}