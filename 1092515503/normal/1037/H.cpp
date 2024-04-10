#include<bits/stdc++.h>
using namespace std;
int n,m,num[100100];
char s[100100];

int cnt=1;
struct Suffix_Automaton{int ch[26],len,fa;}t[200100];
int Add(int x,int c){
	int xx=++cnt;t[xx].len=t[x].len+1;
	for(;x&&!t[x].ch[c];x=t[x].fa)t[x].ch[c]=xx;
	if(!x){t[xx].fa=1;return xx;}
	int y=t[x].ch[c];
	if(t[y].len==t[x].len+1){t[xx].fa=y;return xx;}
	int yy=++cnt;t[yy]=t[y],t[yy].len=t[x].len+1;
	t[xx].fa=t[y].fa=yy;
	for(;x&&t[x].ch[c]==y;x=t[x].fa)t[x].ch[c]=yy;
	return xx;
}

int dfn[200100],rev[200100],sz[200100],tot;
vector<int>v[200100];
void dfs(int x){dfn[x]=++tot,rev[tot]=x,sz[x]=1;for(auto y:v[x])dfs(y),sz[x]+=sz[y];}
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int mx[800100];
void pushup(int x){mx[x]=max(mx[lson],mx[rson]);}
void modify(int x,int l,int r,int P,int val){
	if(l>P||r<P)return;
	if(l==r){mx[x]=val;return;}
	modify(lson,l,mid,P,val),modify(rson,mid+1,r,P,val),pushup(x);
}
int query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return -1;
	if(L<=l&&r<=R)return mx[x];
	return max(query(lson,l,mid,L,R),query(rson,mid+1,r,L,R));
}

int L[200100],R[200100],len[200100],ord[200100],res[200100];
char ss[200100],*q[200100];
bool func(int id,int pos,int x){
//	printf("%d %d %d\n",id,pos,x);
	if(pos<len[id]&&t[x].ch[q[id][pos]-'a']&&func(id,pos+1,t[x].ch[q[id][pos]-'a']))return true;
	for(int i=(pos<len[id]?q[id][pos]-'a'+1:0),y;i<26;i++)if((y=t[x].ch[i])&&(res[id]=query(1,1,tot,dfn[y],dfn[y]+sz[y]-1)-pos)>=L[id])return true;
	return false;
}
int main(){
	scanf("%s%d",s,&m),n=strlen(s);
	for(int i=0,las=1;i<n;i++)num[i]=las=Add(las,s[i]-'a');
	for(int i=2;i<=cnt;i++)v[t[i].fa].push_back(i);
//	for(int i=2;i<=cnt;i++)printf("%d %d\n",t[i].fa,i);
//	for(int i=0;i<n;i++)printf("%d ",num[i]);puts("");
	dfs(1),memset(mx,-1,sizeof(mx));
	q[1]=ss;
	for(int i=1;i<=m;i++){
		scanf("%d%d%s",&L[i],&R[i],q[i]),L[i]--,R[i]--,len[i]=strlen(q[i]);
		q[i+1]=q[i]+len[i];
		ord[i]=i;
	}
//	for(int i=1;i<=m;i++)printf("%d %d %s\n",L[i],R[i],q[i]);
	sort(ord+1,ord+m+1,[](int x,int y){return R[x]<R[y];});
	for(int i=0,j=1;i<n;i++){
		modify(1,1,tot,dfn[num[i]],i);
//		printf("RRR:%d\n",i);
		for(;j<=m&&R[ord[j]]==i;j++){
//			printf("QQQ:%d\n",ord[j]);
			if(!func(ord[j],0,1))res[ord[j]]=-1;
		}
	}
	for(int i=1;i<=m;i++){
		if(res[i]==-1){puts("-1");continue;}
		for(int j=0;j<=len[i];j++){
			printf("%c",s[res[i]+j]);
			if(s[res[i]+j]!=q[i][j])break;
		}
		puts("");
	}
	return 0;
}