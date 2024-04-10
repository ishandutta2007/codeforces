#include<bits/stdc++.h>
using namespace std;
const int N=500100;
int f[N],res;
namespace Suffix_Array{
	int x[N],y[N],buc[N],sa[N],ht[N],rk[N],n,m,mn[N][20],LG[N];
	char s[N];
	bool mat(int a,int b,int k){
		if(y[a]!=y[b])return false;
		if((a+k<n)^(b+k<n))return false;
		if((a+k<n)&&(b+k<n))return y[a+k]==y[b+k];
		return true;
	}
	void SA(){
		for(int i=0;i<n;i++)buc[x[i]=s[i]]++;
		for(int i=1;i<=m;i++)buc[i]+=buc[i-1];
		for(int i=n-1;i>=0;i--)sa[--buc[x[i]]]=i;
		for(int k=1;k<n;k<<=1){
			int num=0;
			for(int i=n-k;i<n;i++)y[num++]=i;
			for(int i=0;i<n;i++)if(sa[i]>=k)y[num++]=sa[i]-k;
			for(int i=0;i<=m;i++)buc[i]=0;
			for(int i=0;i<n;i++)buc[x[y[i]]]++;
			for(int i=1;i<=m;i++)buc[i]+=buc[i-1];
			for(int i=n-1;i>=0;i--)sa[--buc[x[y[i]]]]=y[i];
			swap(x,y);
			x[sa[0]]=num=0;
			for(int i=1;i<n;i++)x[sa[i]]=mat(sa[i],sa[i-1],k)?num:++num;
			if(num>=n-1)break;
			m=num;
		}
		for(int i=0;i<n;i++)rk[sa[i]]=i;
		for(int i=0,k=0;i<n;i++){
			if(!rk[i])continue;
			if(k)k--;
			int j=sa[rk[i]-1];
			while(i+k<n&&j+k<n&&s[i+k]==s[j+k])k++;
			ht[rk[i]]=k;
		}
	}
}
using namespace Suffix_Array;
//-------------------SegMentTree Below-----------------
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
#define pushdown(x) tag[lson]=max(tag[lson],tag[x]),tag[rson]=max(tag[rson],tag[x]),tag[x]=0
int tag[N<<2];
void modify(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return;
	if(L<=l&&r<=R){tag[x]=max(tag[x],val);return;}
	pushdown(x),modify(lson,l,mid,L,R,val),modify(rson,mid+1,r,L,R,val);
}
int query(int x,int l,int r,int P){
	if(l==r)return tag[x];
	pushdown(x);
	return P<=mid?query(lson,l,mid,P):query(rson,mid+1,r,P); 
}
vector<pair<int,int> >v[N];
#undef lson
#undef rson
#undef mid
int L[N],R[N],lson[N],rson[N],anc[N][20],stk[N],tp,pos[N],mx[N];
void dfs(int x,int fa){
	anc[x][0]=fa;
	if(lson[x])dfs(lson[x],x);
	else pos[L[x]]=x;
	if(rson[x])dfs(rson[x],x);
	else pos[R[x]-1]=x;
}
void func(int u){
	int x=pos[rk[u]];
//	printf("FUNC:%d:%d\n",x,f[u]);
	for(int i=19;i>=0;i--)if(ht[anc[x][i]]>=f[u])x=anc[x][i];
	int y=f[u];
	while(x){
		y=min(y,ht[x]);
		if(mx[x]>=y)break;
//		printf("%d,%d\n",x,y);
		mx[x]=y;
		if(u-y-1>=0)v[u-y-1].push_back(make_pair(x,y));
		x=anc[x][0];
	}
}
int main(){
	scanf("%d%s",&n,s),m='z';
	SA();
//	for(int i=0;i<n;i++)printf("%d ",rk[i]);puts("");
//	for(int i=0;i<n;i++)printf("%d ",sa[i]);puts("");

	for(int i=1;i<n;i++){
		while(tp&&ht[stk[tp]]>ht[i])lson[i]=stk[tp],R[stk[tp]]=i,tp--;
		if(tp)rson[stk[tp]]=i;
		L[i]=stk[tp];
		stk[++tp]=i;
	}
	while(tp)R[stk[tp--]]=n;
	
	dfs(stk[1],0);
	for(int j=1;j<=19;j++)for(int i=1;i<n;i++)anc[i][j]=anc[anc[i][j-1]][j-1];
	
//	for(int i=1;i<n;i++)printf("%d[%d,%d]:%d %d[%d,%d]:%d\n",anc[i][0],L[anc[i][0]],R[anc[i][0]]-1,ht[anc[i][0]],i,L[i],R[i]-1,ht[i]);
	
	for(int i=n-1;i>=0;i--){
		for(auto j:v[i])modify(1,0,n-1,L[j.first],R[j.first]-1,j.second);
		f[i]=query(1,0,n-1,rk[i]);
		if(i+1<n)f[i]=max(f[i],query(1,0,n-1,rk[i+1]));
		f[i]++;
		res=max(res,f[i]);
		func(i);
	}
	printf("%d\n",res);
	return 0;
}
/*
10
cbccacbaaa
*/