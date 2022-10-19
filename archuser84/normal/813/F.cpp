///
///    I have a dream and a piano
///

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

const int N = 100'010;
int n, q;

namespace dsu
{
    vector<tuple<int,int,bool>> st;

    bool bi=1;
    pii par[N];
    int cnt[N];

    pair<int,bool> rt(int v){
        if(par[v].F == -1) return {v,0};
        auto [p, w] = rt(par[v].F);
        return {p, w^par[v].S};
    }

    void unite(int x, int y)
    {
        auto [a1, b1] = rt(x);
        auto [a2, b2] = rt(y);
        if(a1 == a2) {
            st.emplace_back(-1,-1,bi);
            bi &= b1 ^ b2;
            return;
        }
        if(cnt[a1] < cnt[a2]) swap(a1, a2);
        st.emplace_back(a1,a2,bi);
        par[a2] = {a1, b1^b2^1};
        cnt[a1] += cnt[a2];
    }

    void revert(int n=1){
        while(n--) {
            auto [p, v, b] = st.back();
            if(v != -1)
            {
                cnt[p] -= cnt[v];
                par[v] = {-1, 0};
            }
            bi = b;
            st.pop_back();
        }
    }
}

namespace seg
{
    vector<pii> t[N<<2];

    void add(int l, int r, pii x, int i=0, int b=0, int e=q)
    {
        if(l <= b && e <= r) return t[i].push_back(x);
        if(r <= b || e <= l) return;
        add(l,r,x,2*i+1,b,(b+e)/2);
        add(l,r,x,2*i+2,(b+e)/2,e);
    }

    void dfs(int i=0, int b=0, int e=q)
    {
        for(auto [x, y] : t[i]) dsu::unite(x,y);
        if(e-b==1) cout << YN(dsu::bi) << '\n';
        else{
            dfs(2*i+1,b,(b+e)/2);
            dfs(2*i+2,(b+e)/2,e);
        }
        dsu::revert(t[i].size());
    }
}


int main()
{
    memset(dsu::par, -1, sizeof dsu::par);
    fill(dsu::cnt, dsu::cnt+N, 1);
    FAST;
    cin >> n >> q;
    map<pii,int> mp;
    Loop(i,0,q)
    {
        int v, u;
        cin >> v >> u;
        --v; --u;
        if(v > u) swap(v, u);
        pii pr = {v,u};
        if(mp.count(pr))
        {
            seg::add(mp[pr], i, pr);
            mp.erase(pr);
        } else mp[pr] = i;
    }
    for(auto [pr, l] : mp) seg::add(l, q, pr);
    seg::dfs();
}