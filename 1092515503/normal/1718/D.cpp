/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,q,a[300100],m,b[300100],p[300100],c[300100],d[600100],D,L,R;
bool sp[600100];
int stk[300100],ch[300100][2],tp;
vector<int>v[600100];
int dfs(int x,int fav){
	if(!x)return 0;
	if(!a[x]){
		int ret=max(dfs(ch[x][0],fav),dfs(ch[x][1],fav));
		int l=lower_bound(d+1,d+D+1,ret)-d;
		int r=lower_bound(d+1,d+D+1,fav)-d-1;
		// printf("[%d,%d]->[%d,%d]\n",ret,fav,l,r);
		if(l>r)L=0x3f3f3f3f,R=0;
		v[r].push_back(l);
		return ret;
	}
	int ter=max(dfs(ch[x][0],a[x]),dfs(ch[x][1],a[x]));
	if(ter>a[x])L=0x3f3f3f3f,R=0;
	return a[x];
}
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
struct SegTree{int mn,tag;}seg[2400100];
void ADD(int x,int y){seg[x].mn+=y,seg[x].tag+=y;}
void pushdown(int x){ADD(lson,seg[x].tag),ADD(rson,seg[x].tag),seg[x].tag=0;}
void pushup(int x){seg[x].mn=min(seg[lson].mn,seg[rson].mn);}
void modify(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return;
	if(L<=l&&r<=R)return ADD(x,val);
	pushdown(x),modify(lson,l,mid,L,R,val),modify(rson,mid+1,r,L,R,val),pushup(x);
}
int retrieve(int x,int l,int r){
	if(l==r)return r;
	pushdown(x);
	return seg[rson].mn==-1?retrieve(rson,mid+1,r):retrieve(lson,l,mid);
}
void build(int x,int l,int r){seg[x].mn=seg[x].tag=0;if(l!=r)build(lson,l,mid),build(rson,mid+1,r);}
void mina(){
	scanf("%d%d",&n,&q),m=D=0,L=0,R=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]),ch[i][0]=ch[i][1]=0;
		while(tp&&p[stk[tp]]<p[i])ch[i][0]=stk[tp--];
		if(tp)ch[stk[tp]][1]=i;stk[++tp]=i;
	}tp=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),m+=!a[i];
	for(int i=1;i<m;i++)scanf("%d",&b[i]),d[++D]=b[i];
	for(int i=1;i<=q;i++)scanf("%d",&c[i]),d[++D]=c[i];
	sort(d+1,d+D+1),D=unique(d+1,d+D+1)-d-1;
	// for(int i=1;i<=D;i++)printf("%d ",d[i]);puts("");
	dfs(stk[1],0x3f3f3f3f);
	build(1,1,D);
	for(int i=1;i<m;i++)sp[lower_bound(d+1,d+D+1,b[i])-d]=true;
	for(int i=1;i<=D;i++){
		if(sp[i])modify(1,1,D,1,i,1);
		for(auto j:v[i])modify(1,1,D,1,j,-1);
		if(seg[1].mn<-1)L=0x3f3f3f3f,R=0;
		if(seg[1].mn==-1)L=max(L,retrieve(1,1,D)),R=min(R,i);
		sp[i]=false,v[i].clear();
	}
	sp[0]=sp[D+1]=false,v[0].clear(),v[D+1].clear();
	for(int i=1;i<=q;i++){
		int x=lower_bound(d+1,d+D+1,c[i])-d;
		puts(L<=x&&x<=R?"YES":"NO");
	}
}
int T;
int main(){scanf("%d",&T);while(T--)mina();return 0;}
/*
1
4 2
4 1 3 2
0 5 3 0
2
4
6
*/