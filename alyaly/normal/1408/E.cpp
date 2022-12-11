#include<bits/stdc++.h>
#define int long long
using namespace std;
struct bian{
	int p,q,r;
} bi[1000001];
int n,m,A[400001],B[400001],s[400001],pbi,p,q,r,pa,ans;
int fa[4000001];
vector<int> ve[400001];
void lb(int np,int nq,int nr){bi[++pbi]={np,nq,nr};ans+=nr;return;}
bool comp(bian x,bian y){
	return x.r>y.r;
}
int fnd(int x){
	if(fa[x]==x)return x;
	else return fa[x]=fnd(fa[x]);
}
void mge(int x,int y){
	if(fnd(x)==fnd(y))return;
	while(x!=fa[x]){
		int t=x;x=fa[x];fa[t]=y;
	}fa[x]=y;return;
}
void kruskal(){
	for(int i=1;i<=pa;i++)fa[i]=i;
	sort(bi+1,bi+pbi+1,comp);
	for(int i=1,ii=1;i<=pbi&&ii<pa;i++){
		if(fnd(bi[i].p)==fnd(bi[i].q))continue;
		else{
			ii++;mge(bi[i].p,bi[i].q);ans-=bi[i].r;
		}
	}
}
signed main(){
	cin>>m>>n;pa=n+m;
	for(int i=1;i<=m;i++)cin>>A[i];
	for(int j=1;j<=n;j++)cin>>B[j];
	for(int i=1;i<=m;i++){
		cin>>s[i];
		for(int j=1;j<=s[i];j++){
			cin>>p;
			++pa;lb(pa,p,999999999999);
			++pa;lb(pa,pa-1,A[i]+B[p]);lb(pa,n+i,999999999999);
			ve[i].push_back(p);
		}
	}
	kruskal();
	printf("%lld\n",ans);
	return 0;
}