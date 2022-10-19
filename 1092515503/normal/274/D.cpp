#include<bits/stdc++.h>
using namespace std;
int n,m,num[1000100],*g[1000100],ord[1000100],cnt,head[1000100],tot,RT=500000,in[1000100],res;
struct node{
	int to,next;
}edge[5001000];
void ae(int u,int v){
//	printf("%d %d\n",u,v);
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++,in[v]++;
}
bool cmp(int x,int y){
	return num[x]<num[y];
}
bool vis[1000100];
vector<int>v;
int main(){
	scanf("%d%d",&n,&m),tot=m,memset(head,-1,sizeof(head));
	for(int i=0;i<n*m;i++)scanf("%d",&num[i]);
//	for(int i=0;i<n;i++){for(int j=0;j<m;j++)printf("%d ",g[i][j]);puts("");}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)ord[j]=i*m+j;
		sort(ord,ord+m,cmp);
		ae(RT,tot);
		for(int l=0,r=0;l<m;){
			while(r<m&&num[ord[l]]==num[ord[r]])r++;
			if(num[ord[l]]!=-1){
				for(int j=l;j<r;j++)ae(tot,ord[j]%m);
				++tot;
				for(int j=l;j<r;j++)ae(ord[j]%m,tot);
			}
			l=r;
		}
		tot++;
	}
	v.push_back(RT);
	for(int i=0;i<v.size();i++){
		int x=v[i];
		for(int e=head[x];e!=-1;e=edge[e].next){
			int y=edge[e].to;
			in[y]--;
			if(!in[y])v.push_back(y);
		}
	}
	for(int i=0;i<tot;i++)if(in[i]){puts("-1");return 0;}
	for(auto x:v)if(x<m)printf("%d ",x+1),vis[x]=true;
	for(int i=0;i<m;i++)if(!vis[i])printf("%d ",i+1);
	return 0;
}