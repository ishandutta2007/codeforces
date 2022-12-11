#include<bits/stdc++.h>
using namespace std;
int n,m,K,t[200001];
int a[200001],b[400001],nxt[400001],ls[200001],p,q,pb;
int fa[200001],dpt[200001],dfn[200001],pdfn,ldfn[200001];
void lb(int np,int nq){
	if(!a[np]) a[np]=++pb;
	else nxt[ls[np]]=++pb;
	b[pb]=nq;
	ls[np]=pb;
	return;
}
void putin(){
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>p>>q;
		lb(p,q);
		lb(q,p);
	}
	return;
}
void tttree(int x,int ndpt){
	dpt[x]=ndpt;
	dfn[x]=++pdfn;
	ldfn[x]=dfn[x];
	for(int i=a[x];i;i=nxt[i]){
		if(fa[x]!=b[i]){
			fa[b[i]]=x;
			tttree(b[i],ndpt+1);
			ldfn[x]=max(ldfn[x],ldfn[b[i]]);
		}
	}
	return;
}
bool comp(int x,int y){
	return dpt[x]<dpt[y];
}
signed main(){
	putin();
	tttree(1,1);
	fa[1]=1;
	for(int i=1;i<=m;i++){
		cin>>K;
		for(int j=1;j<=K;j++){
			cin>>t[j];
			t[j]=fa[t[j]];
		}
		sort(t+1,t+K+1,comp);
		bool nfl=1;
		for(int j=1;j<K;j++){
			if(dfn[t[j+1]]>ldfn[t[j]]||dfn[t[j+1]]<dfn[t[j]]){
				nfl=0;
				break;
			}
		}
		if(!nfl) printf("NO\n");
		else printf("YES\n");
	}
	
	return 0;
}