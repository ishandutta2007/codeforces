#include<bits/stdc++.h>
using namespace std;
int n,m,q;
struct Matrix{
	int a[2][2];
	Matrix(){memset(a,0x3f,sizeof(a));}
	int*operator[](const int&x){return a[x];}
	friend Matrix operator*(Matrix&u,Matrix&v){
		Matrix w;
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)w[i][j]=min(w[i][j],u[i][k]+v[k][j]);
		return w;
	}
};
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
#define LSON lson,l,mid
#define RSON rson,mid+1,r
#define X x,l,r
struct SEGTREE{
	int sum[400100];
	bool rev[400100];
	void REV(int x,int l,int r){sum[x]=(r-l+1)-sum[x],rev[x]^=1;}
	void pushdown(int x,int l,int r){if(rev[x])REV(LSON),REV(RSON),rev[x]=false;}
	void pushup(int x){sum[x]=sum[lson]+sum[rson];}
	void build(char*s,int x,int l,int r){if(l==r)sum[x]=(s[l]=='R');else build(s,LSON),build(s,RSON),pushup(x);}
	void modify(int x,int l,int r,int L,int R){
		if(l>R||r<L)return;
		if(L<=l&&r<=R)REV(X);
		else pushdown(X),modify(LSON,L,R),modify(RSON,L,R),pushup(x);
	}
	int query(int x,int l,int r,int P){
		if(l==r)return sum[x];
		pushdown(X);if(P<=mid)return query(LSON,P);else return query(RSON,P);
	}
}ss[2],tt[2];
#undef RSON
#define RSON rson,mid,r
struct SegTree{Matrix tr[2][2];bool tag[2];}S[400100],T[400100];
void pushup(SegTree*seg,int x){for(int i=0;i<2;i++)for(int j=0;j<2;j++)seg[x].tr[i][j]=seg[lson].tr[i][j]*seg[rson].tr[i][j];}
void REV(SegTree*seg,int x,int sd){
	if(sd==0){seg[x].tag[0]^=1;for(int i=0;i<2;i++)swap(seg[x].tr[0][i],seg[x].tr[1][i]);}
	if(sd==1){seg[x].tag[1]^=1;for(int i=0;i<2;i++)swap(seg[x].tr[i][0],seg[x].tr[i][1]);}
}
void pushdown(SegTree*seg,int x){for(int i=0;i<2;i++)if(seg[x].tag[i])REV(seg,lson,i),REV(seg,rson,i),seg[x].tag[i]=false;}
void build(SegTree*seg,SEGTREE*ges,int x,int l,int r,int N,int M){
	if(l+1==r){
		int _0=ges[0].query(1,1,N,r),_1=ges[1].query(1,1,N,r);
		for(int i=0;i<2;i++)for(int j=0;j<2;j++){
			for(int I=0;I<2;I++)for(int J=0;J<2;J++)seg[x].tr[i][j][I][J]=(I==J?0:M);
			for(int k=0;k<2;k++)seg[x].tr[i][j][k][_0^i]++;
			for(int k=0;k<2;k++)seg[x].tr[i][j][k][_1^j]++;
		}
	}else build(seg,ges,LSON,N,M),build(seg,ges,RSON,N,M),pushup(seg,x);
}
void modify(SegTree*seg,int x,int l,int r,int L,int R,int sd){
	if(L>r||R<=l)return;
	if(L<=l+1&&r<=R)REV(seg,x,sd);
	else pushdown(seg,x),modify(seg,LSON,L,R,sd),modify(seg,RSON,L,R,sd),pushup(seg,x);
}
char STR[100100];
int calc(){
	int res=0x3f3f3f3f;
	static int f[2],g[2];
	f[1]=tt[0].sum[1];
	f[0]=m-f[1];
	f[ss[0].query(1,1,n,1)]++;
	f[ss[1].query(1,1,n,1)]++;
	if(n!=1)g[0]=min(f[0]+S[1].tr[0][0][0][0],f[1]+S[1].tr[0][0][1][0]);else g[0]=f[0];
	if(n!=1)g[1]=min(f[0]+S[1].tr[0][0][0][1],f[1]+S[1].tr[0][0][1][1]);else g[1]=f[1];
	g[1]+=tt[1].sum[1];
	g[0]+=m-tt[1].sum[1];
	res=min(res,min(g[0],g[1]));
	
	f[1]=ss[0].sum[1];
	f[0]=n-f[1];
	f[tt[0].query(1,1,m,1)]++;
	f[tt[1].query(1,1,m,1)]++;
	if(m!=1)g[0]=min(f[0]+T[1].tr[0][0][0][0],f[1]+T[1].tr[0][0][1][0]);else g[0]=f[0];
	if(m!=1)g[1]=min(f[0]+T[1].tr[0][0][0][1],f[1]+T[1].tr[0][0][1][1]);else g[1]=f[1];
	g[1]+=ss[1].sum[1];
	g[0]+=n-ss[1].sum[1];
	res=min(res,min(g[0],g[1]));
	return res;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s",STR+1),ss[0].build(STR,1,1,n);
	scanf("%s",STR+1),ss[1].build(STR,1,1,n);
	scanf("%s",STR+1),tt[0].build(STR,1,1,m);
	scanf("%s",STR+1),tt[1].build(STR,1,1,m);
	if(n!=1)build(S,ss,1,1,n,n,m);
	if(m!=1)build(T,tt,1,1,m,m,n);
	printf("%d\n",calc());
	for(int i=1,l,r;i<=q;i++){
		scanf("%s%d%d",STR,&l,&r);
		if(STR[0]=='L')ss[0].modify(1,1,n,l,r),modify(S,1,1,n,l,r,0);
		if(STR[0]=='R')ss[1].modify(1,1,n,l,r),modify(S,1,1,n,l,r,1);
		if(STR[0]=='U')tt[0].modify(1,1,m,l,r),modify(T,1,1,m,l,r,0);
		if(STR[0]=='D')tt[1].modify(1,1,m,l,r),modify(T,1,1,m,l,r,1);
		printf("%d\n",calc());
	}
	return 0;
}