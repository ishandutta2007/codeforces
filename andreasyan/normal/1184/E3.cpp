#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


#define FOR(i,a) for (int i=0;i<(a);++i)
#define FORD(i,a) for (int i=(a)-1;i>=0;i--)
#define FORT(i,a,b) for (int i=(a);i<=(b);++i)
#define FORTD(i,b,a) for (int i=(b);i>=(a);--i)
#define trav(i,v) for (auto i : v)
#define all(v) v.begin(),v.end()
#define ad push_back
#define fr first
#define sc second
#define mpr(a,b) make_pair(a,b)
#define pir pair<int,int>
#define all(v) v.begin(),v.end()
#define make_unique(v) v.erase(unique(all(v),v.end()))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define dbg(x);
#define dbgv(v);
#define srng mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define y1 EsiHancagorcRepa



const int N=1e6+6;

vector<pair<int,pir> > koxer,pat;
int p[N],sz[N],cnt,tin[N],timer,compHam[N],sg1[4*N],n,m,par[N],subsz[N],sg2[4*N];
vector<pir> g[N];

struct TreeSegment{
    int ver,dep;
} comp[N];

int get_par(int v){
    if (p[v]==v)return v;
    return p[v]=get_par(p[v]);
}

void update1(int v,int tl,int tr,int ind,int val){
    if (tl==tr){
        sg1[v]=val;
        return;
    }
    int tm=(tl+tr)/2;
    if (ind<=tm) update1(v+v,tl,tm,ind,val);
    else update1(v+v+1,tm+1,tr,ind,val);
    sg1[v]=max(sg1[v+v],sg1[v+v+1]);
}

int query1(int v,int tl,int tr,int l,int r){
    if (l>r) return 0;
    if (tl==l && tr==r){
        return sg1[v];
    }
    int tm=(tl+tr)/2;
    return max(query1(v+v,tl,tm,l,min(r,tm)),query1(v+v+1,tm+1,tr,max(l,tm+1),r));
}

int get1(int a,int b){
    int ans=0;
    while(true){
        int ca=compHam[a],cb=compHam[b];
        if (ca==cb){
            if (tin[a]>tin[b]) swap(a,b);
            if (a!=b)
                ans=max(ans,query1(1,0,n-1,tin[a]+1,tin[b]));
            break;
        }
        if (comp[ca].dep<comp[cb].dep){
            swap(a,b);
            swap(ca,cb);
        }
        ans=max(ans,query1(1,0,n-1,tin[comp[ca].ver],tin[a]));
        a=par[comp[ca].ver];
    }
    return ans;
}

void update2(int v,int tl,int tr,int l,int r,int val){
    if (l>r)return;
    if (tl==l && tr==r){
        sg2[v]=min(sg2[v],val);
        return;
    }
    int tm=(tl+tr)/2;
    update2(v+v,tl,tm,l,min(tm,r),val);
    update2(v+v+1,tm+1,tr,max(l,tm+1),r,val);
}

void upd2(int a,int b,int val){
    while(true){
        int ca=compHam[a],cb=compHam[b];
       // cout<<ca<<" "<<cb<<" "<<a<<" "<<b<<" "<<comp[ca].dep<<" "<<comp[cb].dep<<endl;;
        if (ca==cb){
            if (tin[a]>tin[b]) swap(a,b);
            if (a!=b)
                update2(1,0,n-1,tin[a]+1,tin[b],val);
            break;
        }
        if (comp[ca].dep<comp[cb].dep){
            swap(a,b);
            swap(ca,cb);
        }
        update2(1,0,n-1,tin[comp[ca].ver],tin[a],val);
        a=par[comp[ca].ver];
    }
}

int query2(int v,int tl,int tr,int ind){
    if (tl==tr){
        return sg2[v];
    }
    int tm=(tl+tr)/2;
    if (ind<=tm)return min(sg2[v],query2(v+v,tl,tm,ind));
    return min(sg2[v],query2(v+v+1,tm+1,tr,ind));
}

void unite(int a,int b){
    a=get_par(a);
    b=get_par(b);
    if (a!=b){
        if (sz[b]>sz[a])swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
    }
}

int dfssz(int v,int prn=0){
    subsz[v]=1;
    par[v]=prn;
    trav(tv,g[v]){
        int to=tv.fr;
        if (to==prn)continue;
        subsz[v]+=dfssz(to,v);
    }
    return subsz[v];
}

void decomp(int v,int ham,int depth=0,int kox=0){
    //cout<<v<<endl;
    compHam[v]=ham;
    tin[v]=timer++;
    //cout<<"mtnel"<<endl;
    update1(1,0,n-1,tin[v],kox);
    //cout<<"dus gal"<<endl;
    pir mx={INT_MIN,INT_MIN};
    FOR(i,g[v].size()){
        int to=g[v][i].fr;
        if (to==par[v])continue;
        mx=max(mx,{subsz[to],i});
    }
    swap(g[v][0],g[v][mx.sc]);
    trav(tv,g[v]){
        int to=tv.fr;
        if (to==par[v])continue;
        if (to==g[v][0].fr){
            decomp(to,ham,depth+1,tv.sc);
        }
        else{
            comp[cnt].dep=depth+1;
            comp[cnt].ver=to;
            decomp(to,cnt++,depth+1,tv.sc);
        }
    }
}

int main(){
    fastio;
    srng;
    cin>>n>>m;
    FOR(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        koxer.ad({c,{a,b}});
        pat.ad({c,{a,b}});
    }
    FORT(i,1,n){
        p[i]=i;
        sz[i]=1;
    }
    sort(all(koxer));
    trav(tv,koxer){
        int a=tv.sc.fr,b=tv.sc.sc;
        if (get_par(a)!=get_par(b)){
            unite(a,b);
            g[a].ad({b,tv.fr});
            g[b].ad({a,tv.fr});
        }
    }
    //cout<<1<<endl;
    FOR(i,4*n){
        sg2[i]=1000000000;
    }
    dfssz(1);
    //cout<<2<<endl;
    comp[cnt].ver=1;
    comp[cnt].dep=0;
    decomp(1,cnt++);
    //cout<<3<<endl;

    FOR(i,m){
        int a=pat[i].sc.fr,b=pat[i].sc.sc;
        if (par[a]==b || par[b]==a)continue;
        upd2(a,b,pat[i].fr);
    }
    //cout<<4<<endl;
    FOR(i,m){
        int a=pat[i].sc.fr,b=pat[i].sc.sc;
        if (par[a]==b || par[b]==a){
            cout<<query2(1,0,n-1,max(tin[a],tin[b]))<<endl;
        }
        else{
            cout<<get1(a,b)<<endl;
        }
    }
    return 0;
}

/*
4 4
1 2 4
2 3 4
3 4 4
1 4 4
*/