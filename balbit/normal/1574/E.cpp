
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ALL(x) x.begin(),x.end()
#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<"- "<<#__VA_ARGS__<<"- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T && x, S && ...y) {cerr<<x<<", "; _do(y...);}
#else
#define bug(...)
#define endl '\n'
#endif // BALBIT

const int mod = 998244353;
const int maxn = 1e6+6;

#define pii pair<int, int>

ll p2[maxn];

struct yay{
    array<array<int, 2>, maxn> cnt;
    array<int, 2> ocnt; // number with overall parities
    int nbad=0; // number with bad parity
    int free = 0;

    int n,m;

    void upd(int i, int j, int old, int dir) {
        nbad -= cnt[i][0] && cnt[i][1];
        free += cnt[i][0] || cnt[i][1];
        ocnt[(i^j^old)&1]+=dir;
        cnt[i][(j^old)&1]+=dir;
        nbad += cnt[i][0] && cnt[i][1];
        free -= cnt[i][0] || cnt[i][1];
    }

    ll gt(){
//        return 2;
        if(nbad) return 0;
        return p2[free];
    }

    ll overlap(){
        if (ocnt[0] == 0 && ocnt[1] == 0) return 2;
        if(ocnt[0] ==0 || ocnt[1] == 0) return 1;
        return 0;
    }

    yay(int n, int m):n(n), m(m){
        free = n;
        fill(ALL(cnt), array<int,2>{{0,0}});
        ocnt = {{0,0}};
    }

};

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    p2[0] = 1;
    for(int i = 1; i<maxn; ++i) {
        p2[i] = (p2[i-1]<<1) % mod;
    }
    int n,m,q; cin>>n>>m>>q;
    yay A(n,m), B(m,n);
    map<pii, int> mp;

    while (q--) {
        int x,y,t; cin>>x>>y>>t;
        --x; --y;
        if(mp.count({x,y})) {
            int old = mp[{x,y}];
            A.upd(x,y,old,-1);
            B.upd(y,x,old,-1);
        }
        if(t != -1) {
            mp[{x,y}] = t;
            A.upd(x,y,t,1);
            B.upd(y,x,t,1);
        }else{
            if(mp.count({x,y}))
            mp.erase({x,y});
        }
        ll Ac = A.gt();
        ll Bc = B.gt();
        ll ov = A.overlap();
        assert(ov == B.overlap());
        cout<<(Ac+Bc-ov+mod)%mod<<endl;
    }


}