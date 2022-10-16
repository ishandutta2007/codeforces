#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,f[N],f1[N],sz[N],sz1[N];
map <int,int> mp,mp2;
ll ans;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int find1(int x){return f1[x]==x?x:f1[x]=find1(f1[x]);}
void merge(int x,int y){
	int xx=find(x),yy=find(y);
	if(xx==yy)return;
	f[xx]=yy,sz[yy]+=sz[xx];
}
void merge1(int x,int y){
	int xx=find1(x),yy=find1(y);
	if(xx==yy)return;
	f1[xx]=yy,sz1[yy]+=sz1[xx];
}
struct node{
	int to,w;
};
vector <node> e[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)sz[i]=sz1[i]=1,f[i]=f1[i]=i;
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(w)merge1(u,v);
		else merge(u,v);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++)ans+=1ll*(find(i)==i)*sz[i]*(sz[i]-1)+1ll*(find1(i)==i)*sz1[i]*(sz1[i]-1);
	for(int i=1;i<=n;i++){
		int a=0,b=0;
		mp.clear();
		mp2.clear(); 
		for(int j=0;j<e[i].size();j++){
			int v=e[i][j].w?find1(e[i][j].to):find(e[i][j].to);
			if(e[i][j].w)a+=!mp[v]*sz1[v],mp[v]=1;
			else b+=!mp2[v]*sz[v],mp2[v]=1;
		}
		if(a&&b)ans+=1ll*(a-1)*(b-1);
	}
	cout<<ans<<endl;
	return 0;
}
/*
3
1 2 0
2 3 1
*/