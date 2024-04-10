#include<bits/stdc++.h>
using namespace std;
int n,mod,a[30100],buc[30100],res[30100],m,lim;
const int BBB=240;
struct Matrix{
	int a[2][2];
	int*operator[](const int &x){return a[x];}
	Matrix(){memset(a,0,sizeof(a));}
	friend Matrix operator*(register Matrix&u,register Matrix&v){
		Matrix w;
		for(register int i=0;i<2;i++)for(register int j=0;j<2;w[i][j++]%=mod)for(register int k=0;k<2;k++)w[i][j]+=u[i][k]*v[k][j];
		return w;
	}
	void print()const{for(register int i=0;i<2;i++){for(register int j=0;j<2;j++)printf("%d ",a[i][j]);puts("");}}
}F,G,I,f[30100],g[30100];
Matrix ksm(register Matrix x,register int y){register Matrix z=I;for(;y;y>>=1,x=x*x)if(y&1)z=z*x;return z;}
vector<int>v;
struct SegTree{int s[2],sz,tag;}seg[120100];
inline void MUL(register int *x,register Matrix M){
	register int z[2];z[0]=z[1]=0;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)z[j]+=x[i]*M[i][j];
	x[0]=z[0]%mod,x[1]=z[1]%mod;
}
#define lson x<<1
#define rson x<<1|1
void SUM(int&x,int&y,int&z){x=y+z;if(x>=mod)x-=mod;}
inline void MUL(register int x,register int y){MUL(seg[x].s,y>=0?f[y]:g[-y]),seg[x].tag+=y;}
inline void pushdown(register int x){if(seg[x].tag)MUL(lson,seg[x].tag),MUL(rson,seg[x].tag),seg[x].tag=0;}
inline void pushup(register int x){for(register int i=0;i<2;i++)SUM(seg[x].s[i],seg[lson].s[i],seg[rson].s[i]);seg[x].sz=seg[lson].sz+seg[rson].sz;}
inline void turnon(register int x,register int l,register int r,register int P,register int val){
	if(l==r){seg[x].s[0]=0,seg[x].s[1]=v[P-1],MUL(x,val),seg[x].sz=1;return;}
	register int mid=(l+r)>>1;pushdown(x);if(P<=mid)turnon(lson,l,mid,P,val);else turnon(rson,mid+1,r,P,val);pushup(x);
}
inline void turnoff(register int x,register int l,register int r,register int P){
	if(l==r){seg[x].s[0]=seg[x].s[1]=seg[x].sz=0;return;}
	register int mid=(l+r)>>1;pushdown(x);if(P<=mid)turnoff(lson,l,mid,P);else turnoff(rson,mid+1,r,P);pushup(x);
}
inline int querysz(register int x,register int l,register int r,register int P){
	if(l>P)return 0;if(r<=P)return seg[x].sz;
	register int mid=(l+r)>>1;return querysz(lson,l,mid,P)+querysz(rson,mid+1,r,P);
}
inline void modifymatrix(register int x,register int l,register int r,register int P,register int tp){
	if(r<P)return;if(l>=P){MUL(x,tp);return;}
	register int mid=(l+r)>>1;pushdown(x),modifymatrix(lson,l,mid,P,tp),modifymatrix(rson,mid+1,r,P,tp),pushup(x);
}
struct QUERY{int l,r,id;friend bool operator<(const QUERY&u,const QUERY&v){if(u.l/BBB!=v.l/BBB)return u.l<v.l;return(u.l/BBB)&1?u.r<v.r:u.r>v.r;}}q[30100];
inline void Push(register int x){if(!buc[a[x]]++)turnon(1,1,lim,a[x],querysz(1,1,lim,a[x])),modifymatrix(1,1,lim,a[x],1);}
inline void Pop(register int x){if(!--buc[a[x]])turnoff(1,1,lim,a[x]),modifymatrix(1,1,lim,a[x],-1);}
char buf[1<<20],*ss=buf,*tt=buf;
#define gc() (tt==ss&&(tt=(ss=buf)+fread(buf,1,1<<20,stdin),ss==tt)?EOF:*ss++)
inline void read(register int &x){x=0;register char c=gc();while(c>'9'||c<'0')c=gc();while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=gc();}
inline void print(register int x){if(x<=9)putchar('0'+x);else print(x/10),putchar('0'+x%10);}
int main(){
	read(n),read(mod);
	F[0][0]=0,F[0][1]=1,F[1][0]=1,F[1][1]=1;
	G[0][1]=1,G[0][0]=mod-1,G[1][0]=1,G[1][1]=0;
	I[0][0]=1,I[1][1]=1,I[1][0]=0,I[0][1]=0;
	f[0]=g[0]=I;for(int i=1;i<=n;i++)f[i]=f[i-1]*F,g[i]=g[i-1]*G;
	for(register int i=1;i<=n;i++)read(a[i]),v.push_back(a[i]);
	sort(v.begin(),v.end()),v.resize(lim=unique(v.begin(),v.end())-v.begin());
	for(register int i=1;i<=n;i++)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
	for(int i=0;i<v.size();i++)v[i]%=mod;
	read(m);
	for(register int i=1;i<=m;i++)read(q[i].l),read(q[i].r),q[i].id=i;
	sort(q+1,q+m+1);
	register int L=1,R=0;
	for(register int i=1;i<=m;i++){
		while(L>q[i].l)Push(--L);
		while(R<q[i].r)Push(++R);
		while(L<q[i].l)Pop(L++);
		while(R>q[i].r)Pop(R--);
//		iterate(1,1,lim);puts("");
		res[q[i].id]=seg[1].s[0];
	}
	for(int i=1;i<=m;i++)print(res[i]),putchar('\n');
	return 0;
}