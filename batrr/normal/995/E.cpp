#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=2e5+123,inf=1e18,mod=1e9+7,N=360360;
int v,u,m;
map<int,int> used,p;
queue<int>q;
vector<int>path;
int binpow(int n,int p,int mod){
    int res=1;
    while(p){
        if(p&1)
            res=1ll*res*n%mod;
        n=1ll*n*n%mod;
        p/=2;
    }
    return res;
}
void check(int x,int y){
    if( used[y]==0 ){
        used[y]=used[x];
        p[y]=x;
        q.push(y);
        return;
    }
    if(used[y]==used[x])
        return;
    //u-x-y-v
    if(used[x]==2)
        swap(x,y);
    while(true){
        path.pb(x);
        if(x==u)
            break;
        x=p[x];
    }    
    reverse(path.begin(),path.end());
    while(true){
        path.pb(y);
        if(y==v)
            break;
        y=p[y];
    }    
    
    cout<<path.size()-1<<endl;
    for(int i=0;i+1<path.size();i++){
        int c=3;
        if((path[i]+1)%m==path[i+1])
            c=1;
        if((path[i]-1+m)%m==path[i+1])
            c=2;
        cout<<c<<" ";
    }
    exit(0);
}
int main(){
    #ifdef LOCAL
    //    freopen ("test.in", "r", stdin);
    #endif
    cin>>u>>v>>m;
    if(v==u)
        cout<<0,exit(0);
    q.push(v);
    q.push(u);
    used[u]=1;
    used[v]=2;
    while(true){
        int x=q.front(),y;
        q.pop();
        
        y=(x+1)%m;
        check(x,y); 
        y=(x-1+m)%m;
        check(x,y); 
        y=binpow(x,m-2,m);
        check(x,y); 
    
    }               
}