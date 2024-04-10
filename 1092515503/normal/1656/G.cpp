#include<bits/stdc++.h>
using namespace std;
int T,n,pos[200100],a[200100],p[200100],h,dsu[200100];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
void merge(int x,int y){x=find(x),y=find(y);if(x!=y)dsu[x]=y;}
void mina(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)pos[i]=p[i]=0;
	for(int i=1,j=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(pos[a[i]])p[j]=pos[a[i]],p[n-j+1]=i,j++,pos[a[i]]=0;
		else pos[a[i]]=i;
	}
	h=(n>>1)+1;
	for(int i=1;i<=n;i++)if(pos[i]){
		if(p[h]){puts("NO");return;}
		p[h]=pos[i];
	}
	if((n&1)&&p[h]==h){
		for(int i=1;i<=n;i++)if(i!=h&&a[p[i]]==a[h]){swap(p[i],p[h]);break;}
		if(p[h]==h){puts("NO");return;}
	}
//	for(int i=1;i<=n;i++)printf("%d ",p[i]);puts("");
	for(int i=1;i<=n;i++)dsu[i]=i;
	for(int i=1;i<=n;i++)merge(i,p[i]);
	for(int i=1;i<h;i++)if(find(i)!=find(n-i+1))
		swap(p[i],p[n-i+1]),merge(i,p[i]),merge(n-i+1,p[n-i+1]);
	vector<int>v;
	for(int i=1;i<=n;i++){
		if(dsu[i]!=i)continue;
		if((n&1)&&i==h){for(int j=1;j<=n;j++)if(j!=h&&find(j)==i){v.push_back(j);break;}}
		else v.push_back(i);
	}
	int p1=p[v[0]],p2=p[n-v[0]+1];
	for(int i=0;i+1<v.size();i++)p[v[i]]=p[n-v[i+1]+1],p[n-v[i]+1]=p[v[i+1]];
	p[v.back()]=p1,p[n-v.back()+1]=p2;
	puts("YES");
	for(int i=1;i<=n;i++)printf("%d ",p[i]);puts("");
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
} 
/*
1
5
2 1 2 1 1 
*/