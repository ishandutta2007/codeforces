// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e5+123,N=1e7+1,LOG=18,mod=1e9+7;

vector< pair< pair<int ,int >  , pair<int , int> > >q[N];// q1+get    q2-get q3+add
// pw,id, v,u
vector<int>g[maxn];
ll n,m,ans[maxn];
int tin[maxn],tout[maxn],timer,up[maxn][LOG];
int ld[N];
ll t[4*maxn][2],add[4*maxn][2],val[maxn][2];
void dfs(int v,int p){
	tin[v]=++timer;	
	up[v][0]=p;
	for(int i=1;i<LOG;i++)
		up[v][i]=up[up[v][i-1]][i-1];
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if(to!=p){
			dfs(to,v);
		}
	}
	tout[v]=timer;
}
bool upper(int v,int u){
	return (tin[v]<=tin[u] && tin[u]<=tout[v]);
}
int lca(int v,int u){
	if(upper(v,u))
		return v;
	if(upper(u,v))
		return u;
	for(int i=LOG-1;i>=0;i--)
		if(!upper(up[v][i],u))
			v=up[v][i];
	return up[v][0];
}     
void upd(int v,int tl, int tr, int l,int r,int val,int k){
	if(l>r)
		return;
	if(tl==l && tr==r){
		add[v][k]+=val;
		t[v][k]+=val*(r-l+1);
		return;
	}
	int tm=(tl+tr)/2;                
	upd(v+v,tl,tm,l,min(tm,r),val,k);
	upd(v+v+1,tm+1,tr,max(tm+1,l),r,val,k);
	t[v][k]=t[v+v][k]+t[v+v+1][k]+add[v][k]*(r-l+1);
}
int get(int v,int tl, int tr ,int pos,int k){
	if(tl==tr)
		return t[v][k];
	int tm=(tl+tr)/2;
	if( pos<=tm )             
		return get(v+v,tl,tm,pos,k)+add[v][k];
	else
		return get(v+v+1,tm+1,tr,pos,k)+add[v][k];
}
ll binpow(ll n,ll p){
	if(p==0)
		return 1;
	ll c=binpow(n,p/2);
	if(p%2==0)          
		return c*c%mod;
    return c*c%mod*n%mod;
}          
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
    #endif
    for(int i=2;i<N;i+=2)
    	ld[i]=2;
    for(int i=3;i<N;i+=2){
    	if(ld[i]==0){
    		ld[i]=i;
    		for(ll j=1ll*i*i;j< N;j+=i+i)
    			ld[j]=i;
    	}
    }
    cin>>n;
    for(int i=1;i<n;i++){
    	int u,v;
    	cin>>v>>u; 
    	g[v].pb(u);
    	g[u].pb(v);
    }
    dfs(1,1);
    for(int i=1;i<=n;i++){
    	int x;
    	cin>>x;
    	while(x!=1){
   			int p=ld[x],pw=0;
   			while(x%p==0)
   				pw++,x/=p;        
   			q[p].pb(mp(mp(pw,0),mp(i,i)));
   		}
   	}
   	cin>>m;
   	for(int i=1;i<=m;i++){
   		ans[i]=1;
   		int u,v,x,l;
   		cin>>u>>v>>x;
   		l=lca(u,v);
   		while(x!=1){
   			int p=ld[x],pw=0;
   			while(x%p==0)
   				pw++,x/=p;           
   	  		q[p].pb(mp(mp(pw,i),mp(v,u)));
   		}
   	}
   	
   	for(int p=2;p<N;p++){
   		
   		if(q[p].empty())
   			continue;
   		sort(q[p].begin(),q[p].end());
   		for(int i=0;i<q[p].size();i++){
   			int id=q[p][i].f.s;
            int v=q[p][i].s.f;
            if(id==0){            
           		upd(1,1,n,tin[v],tout[v],1,1);
           		val[v][1]++;
           	}
        }
        for(int i=0;i<q[p].size();i++){
   			int pw=q[p][i].f.f;
            int id=q[p][i].f.s;
            int v=q[p][i].s.f;
            int u=q[p][i].s.s;
            int a,b;
            int l=lca(v,u);
            if(id==0){            
           		upd(1,1,n,tin[v],tout[v],pw,0);
            	upd(1,1,n,tin[v],tout[v],-1,1);
            	val[v][0]+=pw;
                val[v][1]--;
            }else{                                                                                            
            	a= get(1,1,n,tin[v],0) + get(1,1,n,tin[u],0) - 2*get(1,1,n,tin[l],0) + val[l][0];
            	b= get(1,1,n,tin[v],1) + get(1,1,n,tin[u],1) - 2*get(1,1,n,tin[l],1) + val[l][1];
               	ans[id]*=binpow(p,a+b*pw);
            	ans[id]%=mod;
            }
        }
        
        for(int i=0;i<q[p].size();i++){
   			int id=q[p][i].f.s;
            int v=q[p][i].s.f;
            int pw=q[p][i].f.f;
            if(id==0){            
           		upd(1,1,n,tin[v],tout[v],-pw,0);
        		val[v][0]-=pw;
        	}
        }

   	}                      
   	for(int i=1;i<=m;i++)
   		cout<<ans[i]<<endl;
}