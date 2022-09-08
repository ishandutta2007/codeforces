#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
 
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned ll;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

#define N_ 201000
vi E[N_];
int vis[N_];
int n, m, par[N_], Dep[N_];
void DFS(int a){
    vis[a]=1;
    for(auto &x: E[a]){
        if(!vis[x]){
            par[x] = a;
            Dep[x] = Dep[a]+1;
            DFS(x);
        }
    }
}
pii Ed[N_];
void Blue(vc<pii> &Z){
    vi res(m);
    for(auto [a,b] : Z){
        rep(j,m){
            if((Ed[j].fi == a && Ed[j].se == b) || (Ed[j].fi == b && Ed[j].se == a)){
                res[j]=1;
            }
        }
    }
    rep(i,m)printf("%d",res[i]);
    puts("");
}
void Solve(){
    scanf("%d%d",&n,&m);
    rng(i,1,n){
        par[i] = 0;
        vis[i]=0;
        Dep[i]=0;
        E[i].clear();
    }
    rep(i,m){
        int a, b;
        scanf("%d%d",&a,&b);
        Ed[i] = {a,b};
        E[a].pb(b);
        E[b].pb(a);
    }
    DFS(1);
    vc<pii>Z;
    rng(i,1,n){
        for(auto &x : E[i]){
            if(i<x){
                if(par[i] != x && par[x] != i){
                    Z.pb({i,x});
                }
            }
        }
    }
    if(si(Z) != 3){
        Blue(Z);
        return;
    }
    map<int,int>MM;
    for(auto [a,b] : Z){
        MM[a]+=1;
        MM[b]+=1;
    }
    int ck =0;
    for(auto [a,c] : MM){
        if(c!=2)ck=1;
    }
    if(ck==1){
        Blue(Z);
        return;
    }
    int a = Z[0].fi, b = Z[0].se;
    if(Dep[a] > Dep[b]){
        Z[0].se = par[a];
    }
    else{
        Z[0].fi = par[b];
    }
    Blue(Z);
}

int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}