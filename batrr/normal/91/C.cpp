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
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e6+123,inf=1e9+123,LOG=18,block=450,mod=1e9+7,N=1e6+123;
int n,m,sz[maxn],p[maxn],ans;
int getp(int v){
	if(p[v]==v)
		return v;
	return p[v]=getp(p[v]);
}
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
	#endif
	IOS
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		sz[i]=1,p[i]=i;
	ans=1;
	while(m--){
		int v,u;
		cin>>v>>u;
		v=getp(v);
		u=getp(u);
		if(v!=u){
			if(sz[v]<sz[u])
				swap(v,u);
		 	sz[v]+=sz[u];
		 	p[u]=v;
		}else
			ans=ans*2%(mod+2);
		cout<<ans-1<<endl;
	}                     
}