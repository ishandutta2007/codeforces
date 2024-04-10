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

const int N = 1e5 + 10;

bool vis[2*N];
vector<pii> A1[N];
vector<int> A2[N];
int cnt[N];
int a[N];
int n, x, y;

void trim(vector<pii>& x){while(x.size() && vis[x.back().S]) x.pop_back();}

void euler(int v)
{
    while(1)
    {
        trim(A1[v]);
        if(!A1[v].size()) break;
        int u = A1[v].back().F;
        vis[A1[v].back().S] = 1;
        A2[u].push_back(v);
        v = u;
    }
}

void clr()
{
    Loop(i,0,n+2)
        cnt[i] = 0,
        A1[i].clear(),
        A2[i].clear();
    Loop(i,0,2*n+4)
        vis[i] = 0;
}

void solve()
{
    cin >> n >> x >> y; y = n-y;
    clr();
    Loop(i,0,n)
    {
        cin >> a[i]; a[i]--;
        cnt[a[i]] += 2;
    }
    int zzz = 0;
    Loop(i,0,n+1) if(cnt[i] == 0) {zzz = i; break;}
    cnt[zzz] = 2*y;
    set<pii, greater<pii>> s;
    Loop(i,0,n+1)
        if(i != zzz) s.insert({cnt[i], i});
    Loop(_,0,x)
    {
        int i = s.begin()->S;
        s.erase(s.begin());
        cnt[i] -= 2;
        s.insert({cnt[i], i});
    }
    s.insert({cnt[zzz], zzz});
    if(s.begin()->F > n-x+y) {cout << "NO\n"; return;}
    Loop(_,0,n-x+y)
    {
        int i = s.begin()->S; s.erase(s.begin());
        int j = s.begin()->S; s.erase(s.begin());
        cnt[i]--;
        cnt[j]--;
        A1[i].push_back({j,_});
        A1[j].push_back({i,_});
        s.insert({cnt[i], i});
        s.insert({cnt[j], j});
    }
    Loop(i,0,n+1)
    {
        trim(A1[i]);
        if(A1[i].size())
            euler(i);
    }
    cout << "YES\n";
    Loop(i,0,n)
    {
        if(!A2[a[i]].size()) cout << a[i]+1 << ' ';
        else                 cout << A2[a[i]].back()+1 << ' ', A2[a[i]].pop_back();
    }
    cout << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}