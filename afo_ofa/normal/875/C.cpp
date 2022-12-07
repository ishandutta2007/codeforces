#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

namespace ts{
	const int tsv=400800,tse=5202333;
	int n,ans[tsv];
	struct R{
		int to,nex;
	}r[tse];
	int hea[tsv<<1],cnt,bel[tsv<<1],blt,st[tsv<<1],top,dfn[tsv<<1],dft,low[tsv<<1];
	
	void RE(){
		memset(hea,0,sizeof hea);cnt=0;
		memset(bel,0,sizeof bel);blt=0;
		memset(dfn,0,sizeof dfn);dft=0;
	}
	void A(int u,int v){
		r[++cnt]=(R){v,hea[u]};hea[u]=cnt;
	}
	void must(int x,int x2,int y,int y2){
		A(x<<1|x2,y<<1|y2);
	}
	void XX(int x,int x2,int y,int y2){ // can't be together
		//printf("XX::%d %d %d %d\n",x,x2,y,y2);
		must(x,x2,y,y2^1);
		must(y,y2,x,x2^1);
	}
	void oorr(int x,int x2,int y,int y2){ 
		XX(x,x2^1,y,y2^1);
	}
	void dfs(int x){
		low[x]=dfn[x]=++dft;
		st[++top]=x;
		int y;
		for (int i=hea[x];i>0;i=r[i].nex){
			y=r[i].to;
			if (!dfn[y]){
				dfs(y);
				low[x]=min(low[x],low[y]);
			}else{
				if (!bel[y]){
					low[x]=min(low[x],dfn[y]);
				}
			}
		}
		if (low[x]==dfn[x]){
			bel[x]=++blt;
			while (st[top]!=x){
				bel[st[top]]=blt;
				top--;
			}
			top--;
		}
	}
	bool realmain(){
		int u,v;
		for (int i=2;i<=(n<<1|1);i++){
			if (!bel[i]){
				top=0;
				dfs(i);
			}
		}
		for (int i=1;i<=n;i++){
			if (bel[i<<1|0]==bel[i<<1|1]) return 0;
			ans[i]=bel[i<<1|0]>bel[i<<1|1]?1:0;
		}
		
		return 1;
	}
}

int n,m,x,l,sz1,sz2;
vector<int>v[101000];

void doit(vector<int>v1,vector<int>v2){
	sz1=v1.size();
	sz2=v2.size();
	for (int i=0;i<min(sz1,sz2);i++){
		if (v1[i]==v2[i]) continue;
		if (v1[i]<v2[i]){
			ts::oorr(v1[i],1,v2[i],0);
		}else{
			ts::oorr(v1[i],1,v1[i],1);
			ts::oorr(v2[i],0,v2[i],0);
		}
		return;
	}
	if (sz1<=sz2) return;
	puts("No");
	exit(0);
}

int main(){
	scanf("%d%d",&n,&m);
	ts::RE();ts::n=m;
	for (int i=1;i<=n;i++){
		scanf("%d",&l);
		for (;l--;){
			scanf("%d",&x);
			v[i].push_back(x);
		}
		if (i>1) doit(v[i-1],v[i]);
	}
	if (!ts::realmain()) puts("No");
	else{
		int tot=0;
		for (int i=1;i<=ts::n;i++){
			if (ts::ans[i]) tot++;
		}
		printf("Yes\n%d\n",tot);
		for (int i=1;i<=ts::n;i++){
			if (ts::ans[i]) printf("%d ",i);
		}
	}
}