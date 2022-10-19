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

vector<pair<int,pir> > koxer;
int p[N],sz[N];

int get_par(int v){
    if (p[v]==v)return v;
    return p[v]=get_par(p[v]);
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

int main(){
    fastio;
    srng;
    int n,m;
    cin>>n>>m;
    int v,u,qan;
    cin>>v>>u>>qan;
    FOR(i,m-1){
        int a,b,c;
        cin>>a>>b>>c;
        koxer.ad({c,{a,b}});
    }
    FORT(i,1,n){
        p[i]=i;
        sz[i]=1;
    }
    sort(all(koxer));
    trav(tv,koxer){
        int a=tv.sc.fr,b=tv.sc.sc;
        unite(a,b);
        if (get_par(u)==get_par(v)){
            cout<<tv.fr<<endl;
            return 0;
        }
    }
    cout<<1000000000<<endl;
    return 0;
}