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
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

const int N = 400'010;
vector<pii> A[N];
bool vis[N];
vector<int> ans;
int n, m;

void euler(int u)
{
    int v = u;
    vector<int> tmp;
    while(1)
    {
        while(A[v].size() && vis[A[v].back().S]) A[v].pop_back();
        if(A[v].empty()) break;
        int w = A[v].back().F;
        int e = A[v].back().S;
        vis[e] = 1;
        //cerr << v << ' ' << w << '\n';
        v = w;
        tmp.push_back(v);
    }
    for(int v : tmp)
    {
        ans.push_back(v);
        euler(v);
    }
}

int main()
{
    FAST;
    cin >> n >> m;
    Loop(i,0,m)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        A[u].emplace_back(v, i);
        A[v].emplace_back(u, i);
    }
    int odd = -1;
    Loop(i,0,n)
    {
        if(A[i].size()%2 == 1)
        {
            if(odd == -1) odd = i;
            else
            {
                A[odd].emplace_back(i, m);
                A[i].emplace_back(odd, m);
                m++;
                odd = -1;
            }
        }
    }
    if(m%2 == 1) A[0].emplace_back(0, m++);
    ans.push_back(0);
    euler(0);
    cout << m << '\n';
    Loop(i,1,ans.size())
    {
        if(i&1) cout << ans[i-1]+1 << ' ' << ans[i]+1 << '\n';
        else    cout << ans[i]+1 << ' ' << ans[i-1]+1 << '\n';
    }
}