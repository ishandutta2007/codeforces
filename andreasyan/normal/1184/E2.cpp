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
int p[N],sz[N],cnt,hamar[N],kox[N];
vector<int> g[N];


int get_par(int v){
    if (p[v]==v)return v;
    return p[v]=get_par(p[v]);
}


void unite(int a,int b,int erk){
    a=get_par(a);
    b=get_par(b);
    if (a!=b){
        if (sz[b]>sz[a])swap(a,b);
        g[cnt].push_back(hamar[a]);
        g[cnt].push_back(hamar[b]);
        kox[cnt]=erk;
        hamar[a]=cnt++;
        p[b]=a;
        sz[a]+=sz[b];
    }
}

int lg;
vector<vector<int> > anc;
int tin[N],tout[N],timer;

void dfs(int v,int par){
    //cout<<v<<endl;
    tin[v]=timer++;
    anc[v][0]=par;
    FORT(i,1,lg){
        anc[v][i]=anc[anc[v][i-1]][i-1];
        //cout<<anc[v][i]<<endl;
    }
    trav(to,g[v]){
        dfs(to,v);
    }
    tout[v]=timer++;
}

bool upper(int a,int b){
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a,int b){
    if (upper(a,b))return a;
    if (upper(b,a))return b;
    FORD(i,lg+1){
        if (!upper(anc[a][i],b)){
            a=anc[a][i];
        }
    }
    return anc[a][0];
}

int main(){
    fastio;
    srng;
    int n,m;
    cin>>n>>m;
    int v,u,qan;
    FOR(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        koxer.ad({c,{a,b}});
        pat.ad({c,{a,b}});
    }
    FORT(i,1,n){
        p[i]=i;
        sz[i]=1;
        hamar[i]=i;
    }
    sort(all(koxer));
    cnt=n+1;
    trav(tv,koxer){
        int a=tv.sc.fr,b=tv.sc.sc;
        if (get_par(a)!=get_par(b)){
            unite(a,b,tv.fr);
        }
    }
    //cout<<1<<endl;
    cnt--;
    while ((1<<lg) <= cnt)  ++lg;
    anc.resize(cnt+1);
    //cout<<lg<<endl;
    FORT(i,1,cnt){
        anc[i].resize(lg+2);
    }
    FORT(i,0,lg){
        anc[cnt][i]=cnt;
    }
    dfs(cnt,cnt);
    FOR(i,m){
        int ans=kox[lca(pat[i].sc.fr,pat[i].sc.sc)];
        if (ans<pat[i].fr){
            cout<<ans<<endl;
        }
    }
    return 0;
}