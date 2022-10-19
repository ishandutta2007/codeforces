#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
const int inv100=ksm(100);
int n,pos[100100],vel[100100],pro[100100];
struct frac{
	int x,y,p,a,b;
	frac(int X,int Y,int P,int A,int B){x=X,y=Y,p=P,a=A,b=B;} 
	friend bool operator<(const frac&u,const frac&v){return 1ll*u.x*v.y<1ll*u.y*v.x;}
	int operator()()const{return 1ll*x*ksm(y)%mod;}
};
vector<frac>v;
struct Matrix{
	int a[2][2];
	Matrix(){a[0][0]=a[1][1]=1,a[0][1]=a[1][0]=0;}
	int*operator[](const int&x){return a[x];}
	friend Matrix operator*(Matrix u,Matrix v){
		Matrix w;
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)
			w[i][j]=(1ll*u[i][0]*v[0][j]+1ll*u[i][1]*v[1][j])%mod;
		return w;
	}
};
struct SegTree{
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
Matrix seg[400100];	
void buildl(int x,int l,int r){
	if(l==r)seg[x][0][0]=seg[x][1][0]=pro[l],seg[x][0][1]=seg[x][1][1]=(1+mod-pro[l])%mod;
	else buildl(lson,l,mid),buildl(rson,mid+1,r),seg[x]=seg[lson]*seg[rson];
}
void buildr(int x,int l,int r){
	if(l==r)seg[x][0][0]=seg[x][0][1]=pro[r],seg[x][1][0]=seg[x][1][1]=(1+mod-pro[r])%mod;
	else buildr(lson,l,mid),buildr(rson,mid+1,r),seg[x]=seg[lson]*seg[rson];
}
Matrix query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return Matrix();
	if(L<=l&&r<=R)return seg[x];
	return query(lson,l,mid,L,R)*query(rson,mid+1,r,L,R); 
}
void modify(int x,int l,int r,int P,int a,int b){
	if(l==r){seg[x][a][b]=0;return;}
	P<=mid?modify(lson,l,mid,P,a,b):modify(rson,mid+1,r,P,a,b),seg[x]=seg[lson]*seg[rson]; 
}
}s1,s2;
int res;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&pos[i],&vel[i],&pro[i]),pro[i]=1ll*pro[i]*inv100%mod;
	s1.buildl(1,1,n),s2.buildr(1,1,n);
	for(int i=1;i<n;i++){
		v.emplace_back(pos[i+1]-pos[i],vel[i]+vel[i+1],i,0,1);
		if(vel[i]>vel[i+1])v.emplace_back(pos[i+1]-pos[i],vel[i]-vel[i+1],i,0,0);
		if(vel[i]<vel[i+1])v.emplace_back(pos[i+1]-pos[i],vel[i+1]-vel[i],i,1,1);
	}
	sort(v.begin(),v.end());
	for(auto i:v){
//		printf("(%d/%d):%d[%d,%d]\n",i.x,i.y,i.p,i.a,i.b);
		int pr=1;
		pr=1ll*pr*s1.query(1,1,n,1,i.p)[0][i.a]%mod;
		pr=1ll*pr*s2.query(1,1,n,i.p+1,n)[i.b][1]%mod;
//		printf("%d\n",pr);
		pr=1ll*pr*i()%mod;
		(res+=pr)%=mod;
		s1.modify(1,1,n,i.p+1,i.a,i.b);
		s2.modify(1,1,n,i.p,i.a,i.b);
	}
	printf("%d\n",res);
	return 0;
}
/*
4
0 8 50
2 16 50
4 25 50
9 4 50
*/