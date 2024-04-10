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

const int N = 500'010;
const int mod = 1e9 + 7;
vector<pii> A[N];
vector<int> ans;
bool vis[N] = {};
ll p2[N];
int n, m;

int par[N];
int cnt[N];

int root(int u){
    if(par[u] == -1) return u;
    return par[u] = root(par[u]);
}

void unite(int a, int b, int t)
{
    a = root(a);
    b = root(b);
    if(a == b) return;
    par[b] = a;
    cnt[a] += cnt[b];
    ans.push_back(t);
}

int main()
{
    FAST;
    p2[0] = 1; Loop(i,1,N) p2[i] = (p2[i-1]*2) % mod;
    Loop(i,0,N) par[i] = -1, cnt[i] = 1;
    cin >> n >> m;
    Loop(i,0,n)
    {
        int a, b, k;
        cin >> k;
        if(k == 2){
            cin >> a >> b;
            a--; b--;
        }
        else {
            cin >> a;
            a--; b = m;
        }
        unite(a, b, i+1);
    }
    ll ans = 1;
    Loop(i,0,m+1){
        if(par[i] == -1)
            ans = (ans * p2[cnt[i]-1])%mod;
    }
    cout << ans << ' ' << ::ans.size() << '\n';
    for(int x : ::ans)
        cout << x << ' ';
}