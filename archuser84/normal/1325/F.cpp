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

const int N = 100'010;
int n, s;
int m;
int d[N]={};
vector<int> A[N];
vector<int> ind;
vector<int> cyc;
bool del[N] = {};

bool find_ind()
{
    set<pii> Q;
    Loop(i,0,n) Q.insert({d[i], i});
    while(ind.size() < s)
    {
        int u = Q.begin()->S;
        if(d[u]+1 >= s) return 0;
        del[u] = 1; Q.erase(Q.begin());
        ind.push_back(u);
        for(int a : A[u])
        {
            if(del[a]) continue;
            del[a] = 1; Q.erase({d[a], a});
            for(int b : A[a])
            {
                if(del[b]) continue;
                Q.erase({d[b]--, b});
                Q.insert({d[b], b});
            }
        }
    }
    return 1;
}

void find_cyc()
{
    int nxt[N], vis[N] = {}, u;
    Loop(i,0,n) if(!del[i]) {u = i; break;}
    vis[u] = 1;
    while(1)
    {
        for(int v : A[u])
        {
            if(del[v]) continue;
            if(!vis[v]){
                vis[v] = vis[u]+1;
                nxt[u] = v;
                u = v;
                break;
            }
            if(vis[v]+s-1 > vis[u]) continue;
            nxt[u] = -1;
            u = v;
            goto make_cyc;
        }
    }
make_cyc:
    while(u != -1)
    {
        cyc.push_back(u);
        u = nxt[u];
    }
}

int main()
{
    FAST;
    cin >> n >> m; s = ceil(sqrt(n));
    Loop(i,0,m)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        d[u]++; d[v]++;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    if(find_ind())
    {
        cout << "1\n";
        for(int u : ind)
            cout << u+1 << ' ';
    }
    else
    {
        find_cyc();
        cout << "2\n" << cyc.size() << '\n';
        for(int u : cyc)
            cout << u+1 << ' ';
    }
}