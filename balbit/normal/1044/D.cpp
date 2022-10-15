#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mod;
        a = a*a %mod;
        n>>=1;
    }
    return re;
}

ll inv (ll b){
    if (b==1) return b;
    return (mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 1e5+5;

struct DSU{
    vector<int> pxor, par, rnk;
    vector<vector<pii> > g; // To, weight
    int mx;
    DSU(int sz){
        mx = sz; 
        pxor.resize(sz); par.resize(sz); rnk.resize(sz,1);
        g.resize(sz);
        REP(i,sz) par[i] = i;
    }

    int find(int x){
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void dfs(int v, int p){
        for (pii xx : g[v]){
            if (xx.f != p){
                pxor[xx.f] = pxor[v] ^ xx.s;
                dfs(xx.f, v);
            }
        }
    }

    void merge(int a, int b, int w){
        int A = find(a), B = find(b);
        if (A==B) return;
        g[a].pb({b,w}); g[b].pb({a,w});
        if (rnk[A] < rnk[B]) {
            swap(a,b); swap(A,B);
        }
        pxor[b] = w ^ pxor[a];
        dfs(b,a);
        rnk[A] += rnk[B];
        par[B] = A;

    }

    int que(int a, int b){
        int A = find(a), B = find(b);
        if (A!=B) return -1;
        return pxor[a] ^ pxor[b];
    }

};

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int q; cin>>q;
    map<int, int> mp;
    DSU dd(4e5+100);
    int id = 1;
    int last = 0;
    REP(i,q){
        int tp; cin>>tp;
        int l, r; cin>>l>>r; l^=last; r ^= last; if (l>r) swap(l,r);
        r++;
        // cout<<tp<<' '<<l<<' '<<r<<'\n';
        int L = mp[l], R = mp[r];  

        if (L==0) L = mp[l] = id++; 
        if (R==0) R = mp[r] = id++; 

        if (tp==2){
            int ans = dd.que(L,R);
            cout<<ans<<'\n';
            last = abs(ans);
        }else{
            int x; cin>>x; x^=last;
            dd.merge(L,R,x);
        }
    }
}