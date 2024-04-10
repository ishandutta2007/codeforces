#pragma GCC optimize(3)
////
#include<bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define ld long double
#define ull unsigned long long

#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))

const int N=2e5+5;
int n,f[N],sz[N],buc[N];
ll res[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x,int y){
	if(!buc[x]||!buc[y])return;
	x=find(x),y=find(y);
	if(x==y)return;
	f[y]=x,sz[x]+=sz[y];
}
vector <int> e[N],node[N];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a; cin>>a;
		for(int j=1;j*j<=a;j++)
			if(a%j==0){
				node[j].pb(i);
				if(j*j!=a)node[a/j].pb(i);
			}
	} for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		e[u].pb(v),e[v].pb(u);
	}
	for(int i=1;i<=2e5;i++){
		for(int it:node[i])f[it]=it,sz[it]=buc[it]=1;
		for(int it:node[i])for(int to:e[it])merge(it,to);
		for(int it:node[i])if(f[it]==it)res[i]+=1ll*sz[it]*(sz[it]+1)/2;
		for(int it:node[i])buc[it]=0;
	}
	for(int i=2e5;i;i--)for(int j=i+i;j<=2e5;j+=i)res[i]-=res[j];
	for(int i=1;i<=2e5;i++)if(res[i])cout<<i<<" "<<res[i]<<endl;
	return 0;
}