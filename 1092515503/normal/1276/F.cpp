#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char s[100100];
struct SAM{
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
void clr(){memset(t,0,sizeof(t)),cnt=1;}
ll cot(){ll ret=0;for(int x=1;x<=cnt;x++)ret+=t[x].len-t[t[x].fa].len;return ret;}
}sam[2];
vector<int>u[200100],v[200100];
int dfn[200100],rev[200100],st[400100][20],LG[400100],fir[200100],dep[200100],lim,tot;
int pu[200100],pv[200100];
void dfsv(int x){
	dfn[x]=++tot,rev[tot]=x,st[++lim][0]=x,fir[x]=lim;
	for(auto y:v[x])dep[y]=dep[x]+1,dfsv(y),st[++lim][0]=x;
}
int MIN(int x,int y){return dep[x]<dep[y]?x:y;}
int LCA(int x,int y){
	x=fir[x],y=fir[y];
	if(x>y)swap(x,y);
	int k=LG[y-x+1];
	return MIN(st[x][k],st[y-(1<<k)+1][k]);
}
int rt[200100],sgc;
#define lson seg[x].ch[0]
#define rson seg[x].ch[1]
#define mid ((l+r)>>1)
struct SegTree{int ch[2],lp,rp;ll sum;}seg[10001000];
void pushup(int&x){
	if(!lson&&!rson){x=0;return;}
	if(!lson){seg[x].lp=seg[rson].lp,seg[x].rp=seg[rson].rp,seg[x].sum=seg[rson].sum;return;}
	if(!rson){seg[x].lp=seg[lson].lp,seg[x].rp=seg[lson].rp,seg[x].sum=seg[lson].sum;return;}
	seg[x].lp=seg[lson].lp,seg[x].rp=seg[rson].rp;
	seg[x].sum=seg[lson].sum+seg[rson].sum-(sam[1].t[LCA(seg[lson].rp,seg[rson].lp)].len);
}
void merge(int&x,int y){
	if(!x){x=y;return;}
	if(!y)return;
	merge(lson,seg[y].ch[0]),merge(rson,seg[y].ch[1]),pushup(x);
}
void insert(int&x,int l,int r,int P){
//	printf("INSERT:%d,%d,%d\n",l,r,P);
	x=++sgc,seg[x].lp=seg[x].rp=rev[P],seg[x].sum=sam[1].t[rev[P]].len;
	if(l!=r)P<=mid?insert(lson,l,mid,P):insert(rson,mid+1,r,P);
}
ll res;
void dfsu(int x){
	for(auto y:u[x])dfsu(y),merge(rt[x],rt[y]);
	res+=seg[rt[x]].sum*(sam[0].t[x].len-sam[0].t[sam[0].t[x].fa].len);
}
int main(){
	scanf("%s",s),n=strlen(s);
	for(int i=0,las=1;i+1<n;i++)las=sam[0].Add(las,s[i]-'a');res+=sam[0].cot();sam[0].clr();
	for(int i=n-1,las=1;i;i--)las=sam[1].Add(las,s[i]-'a');res+=sam[1].cot();sam[1].clr();
	for(int i=0,las=1;i<n;i++)pu[i]=las=sam[0].Add(las,s[i]-'a');res+=sam[0].cot();
	for(int i=n-1,las=1;i>=0;i--)pv[i]=las=sam[1].Add(las,s[i]-'a');
//	printf("%lld\n",res);
	for(int i=2;i<=sam[0].cnt;i++)u[sam[0].t[i].fa].push_back(i);
	for(int i=2;i<=sam[1].cnt;i++)v[sam[1].t[i].fa].push_back(i);
	dfsv(1);
	for(int i=2;i<=lim;i++)LG[i]=LG[i>>1]+1;
	for(int j=1;j<=LG[lim];j++)
		for(int i=1;i+(1<<j)-1<=lim;i++)st[i][j]=MIN(st[i][j-1],st[i+(1<<j-1)][j-1]);
	for(int i=0;i+2<n;i++)insert(rt[pu[i]],1,sam[1].cnt,dfn[pv[i+2]]);
	dfsu(1);
	printf("%lld\n",res+2);
	return 0;
}