#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;
              
struct line{
    ll k,b;
    double L,R;
};          
bool cmp(line a, line b){
    return a.k<b.k;  
}
vector< pair< int, line > > g[maxn];
vector< line > ans;
int n,m;
int sz[maxn];     
bool was[maxn];
double intersect( line a,line b){
    return 1.0*(b.b-a.b)/(a.k-b.k);
}
vector< line > cvh( vector< line > vl, bool sorted){// build convex hull
    if(!sorted)
        sort(vl.begin(),vl.end(),cmp);
    vector< line > v;
    
    for(auto x:vl){
        while( !v.empty() && (v.back().k==x.k && v.back().b<=x.b) )
            v.pop_back();
        if( v.empty() || v.back().k<x.k )
            v.pb(x);
    }
    
    vector< line > res;
    
    for(int i=0;i<v.size();i++){
        line x=v[i];
        while( res.size()>1 && intersect(x,res[res.size()-1])<res[res.size()-1].L )
            res.pop_back(); 
        if( !res.empty() ){
            x.R=1e9;
            res[res.size()-1].R=x.L=intersect(x,res.back());
        }else
            x.L=-1e9,x.R=1e9;
        res.pb(x);
    
    }
    
    return res;
}              
vector< line > Merge1( vector<line>  a, vector<line> b){ // merge convex hulls  a and b
    vector<line> c;
    
    int i=0,j=0;
    while( i<a.size() || j<b.size() ){
        line x;
        if( i<a.size() && ( j==b.size() || b[j].k>a[i].k) )
            x=a[i++];
        else
            x=b[j++];
        c.pb(x);             
    }
    return cvh(c,1);
}
void Merge2( vector<line>  a, vector<line> b){ // merge convex hulls  a+b
    
    int i=0,j=0;
    while( true ){
        ans.pb({a[i].k+b[j].k,a[i].b+b[j].b});
        
        if(i+1==a.size() && j+1==b.size())
            break;

        if(i+1==a.size()){
            j++;
            continue;
        }
        if(j+1==b.size()){
            i++;
            continue;
        }
        if( a[i].R<b[j].R)
            i++;
        else
            j++;
    }               

}
vector< line >  getmx( vector< vector<line> > v ){ // divide and conquer
    if(v.size()==1)
        return cvh(v[0],0);
    vector< vector<line> > vl,vr;
    int m=v.size()/2;
    for(int i=0;i<m;i++)
        vl.pb(v[i]);
    for(int i=m;i<v.size();i++)
        vr.pb(v[i]);
    vector< line > a,b;
    a=getmx(vl);
    b=getmx(vr);
    Merge2(a,b);
    return Merge1(a,b);
}
    
void dfs(int v,int p){// calc subtree size
    sz[v]=1;
    for(auto it:g[v]){
        int to=it.f;
        if(!was[to] && to!=p){
            dfs(to,v);
            sz[v]+=sz[to];
        }
    }
}
int get_centroid(int v,int p,int SZ){// get centroid 
    for(auto it:g[v]){
        int to=it.f;
        if(!was[to] && to!=p && 2*sz[to]>SZ)
            return get_centroid(to,v,SZ);
    }
    return v;
}
void get_paths(int v, int p, line cur, vector<line> &vcvh){// get all paths to centroid
    vcvh.pb(cur);
    for(auto it:g[v]){
        int to=it.f;
        if(!was[to] && to!=p){
            get_paths(to,v,{cur.k+it.s.k,cur.b+it.s.b},vcvh);
        }
    }
}     
void solve(int v){
    dfs(v,v);
    v=get_centroid(v,v,sz[v]);
    was[v]=1;

    vector< vector<line> > vcvh;
    vector< line > mxcvh;
    for(auto it:g[v]){
        int to=it.f;
        if(was[to])
            continue;
        vector< line > cur;
        get_paths(to,v,it.s,cur);
        vcvh.pb( cvh(cur,0) );    
    }
    if( !vcvh.empty() ){
        mxcvh=getmx(vcvh);
        for( auto x:mxcvh )
            ans.pb(x);
    }
    
    for(auto it:g[v]){
        int to=it.f;
        if(!was[to])
            solve(to);
    }
}                 
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
        freopen ("test.out", "w", stdout);
    #endif                                     
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int v,u,k,b;
        scanf("%d%d%d%d",&u,&v,&k,&b);
        g[v].pb({u,{k,b}});
        g[u].pb({v,{k,b}});
    }
    solve(1);
    ans.pb({0,0,0,0});
    ans=cvh(ans,0);
    
    for(int i=0,j=0;i<m;i++){
        while(ans[j].R<i)
            j++;
        printf("%lld ",1ll*ans[j].k*i+ans[j].b);            
    }
}