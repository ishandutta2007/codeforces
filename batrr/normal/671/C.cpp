#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,INF=1e9,mod=1e9+7,N=2e5+123;
int n,a[maxn],pre[maxn],suf[maxn],last[maxn];
vector< int > v[maxn];
ll t[4*maxn];
int val[4*maxn],mx[4*maxn],mn[4*maxn];
bool was[maxn];
ll ans;
void push(int v,int tl,int tr,int tm){
	if( val[v]==-1 )
		return;
	mn[v+v]=mx[v+v]=val[v+v]=val[v];
	mn[v+v+1]=mx[v+v+1]=val[v+v+1]=val[v];
	t[v+v]=1ll*(tm-tl+1)*val[v];
	t[v+v+1]=1ll*(tr-tm)*val[v];
	val[v]=-1;
}
void upd(int v,int tl,int tr,int l,int r,int x){
	if(l>r)
		return ;
	if( mn[v] >= x )
		return ;
	if(tl==l && tr==r){
		if( mx[v] <= x ){
			mx[v] = x;
			mn[v] = x;
			val[v] = x;
			t[v] = 1ll*x*(tr-tl+1);
			return;
		}	
	}
	int tm=(tl+tr)/2;
	push(v,tl,tr,tm);                     
	upd(v+v,tl,tm,l,min(tm,r),x);
	upd(v+v+1,tm+1,tr,max(tm+1,l),r,x);
	t[v] = t[v+v] + t[v+v+1];     
	mx[v] = max(mx[v+v],mx[v+v+1]);
	mn[v] = min(mn[v+v],mn[v+v+1]);
}
ll get(int v,int tl,int tr,int l,int r){
	if( l>r)
		return 0;
	if( tl==l && tr==r )
		return t[v];
	int tm=(tl+tr)/2;
	push(v,tl,tr,tm);
	return get(v+v,tl,tm,l,min(tm,r))+get(v+v+1,tm+1,tr,max(tm+1,l),r);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=1;j*j<=a[i];j++)
			if(a[i]%j==0){
				v[i].pb(j);
				if(j*j!=a[i])
                	v[i].pb(a[i]/j);
			}
		sort(v[i].begin(),v[i].end());
		for( auto x:v[i] )
			last[x]=i;
	}	         

	for(int i=n;i>=1;i--){
		suf[i]=suf[i+1];
		for( auto x:v[i] ){
			if( was[x] )
				suf[i] = max(suf[i],x) ;
		  	was[x] = 1;
		}
		upd(1,1,n,1,i,suf[i]);
		ans+=suf[i];
	}
	for(int i=1;i<N;i++)
		was[i]=0;
    for(int i=1;i<=n;i++){
		pre[i]=pre[i-1];
		for( auto x:v[i] ){
			if( was[x] )
				pre[i] = max(pre[i],x) ;
		  	was[x]=1;
		}
		ans+=pre[i];
	}

	for(int i=1;i<=n;i++){
		upd(1,1,n,1,n,pre[i]);
		for( auto x:v[i] )
			upd(1,1,n,1,last[x],x);
		ans+=get(1,1,n,i+2,n);
	}
	
	printf("%lld",ans - 2*pre[n] );
}