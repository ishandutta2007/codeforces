#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll int64_t
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

const int N = 1003;
vector<int> A[2*N+1];
bool is[2*N+1] = {};
bool vis[2*N+1] = {};
int n, k;

int bfs()
{
    queue<pii> Q; Q.push({}); vis[N] = 1;
    while(Q.size())
    {
        int u = Q.front().F;
        int d = Q.front().S;
        Q.pop();
        for(int v : A[u+N])
        {
            if(v == 0) return d+1;
            if(vis[v+N]) continue;
            vis[v+N] = 1;
            Q.push({v, d+1});
        }
    }
    return -1;
}

int main()
{
    FAST;
    cin >> n >> k;
    while(k--)
    {
        int x;
        cin >> x;
        if(x == n) Kill(1);
        is[x-n+N] = 1;
    }
    Loop(x,-N,N+1)
    {
        if(!is[x+N]) continue;
        for(int u = max(-N, -N-x); u + x <= N && u <= N; ++u)
            A[u+N].push_back(u+x);
    }
    cout << bfs() << '\n';
}