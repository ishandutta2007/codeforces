#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=3e4+3,M=12e4+3;
struct A{
	ll w;
	int id;
	bool operator<(A a)const{return w<a.w;}
}a[N];
struct B{
	ll h;
	int id;
	bool operator<(B b)const{return h<b.h;}
}b[N];
struct mat{
	ll a[3][3];
	mat(){memset(a,-9,sizeof a);}
	ll*operator[](int x){return a[x];}
	mat operator*(mat b){
		mat r;
		for(int i=0;i<3;++i)for(int j=0;j<3;++j)for(int k=0;k<3;++k)r[i][k]=max(r[i][k],a[i][j]+b[j][k]);
		return r;
	}
}s[M];
int p[N],g[N],u,o[3];
mat get(int x){
	int i;
	mat r;
	do{
		for(i=0;i<3;++i)if(g[x+i]==x+o[i])goto gg;
		r[0][2]=max(r[0][2],a[x].w*b[x+o[0]].h+a[x+1].w*b[x+o[1]].h+a[x+2].w*b[x+o[2]].h);
		gg:;
	}while(next_permutation(o,o+3));
	r[0][0]=g[x]==x?-1e18:a[x].w*b[x].h;
	r[0][1]=(g[x]==x||g[x+1]==x+1)?a[x].w*b[x+1].h+a[x+1].w*b[x].h:a[x].w*b[x].h+a[x+1].w*b[x+1].h;
	r[1][0]=0;
	r[1][1]=g[x+1]==x+1?-1e18:a[x+1].w*b[x+1].h;
	r[1][2]=(g[x+1]==x+1||g[x+2]==x+2)?a[x+1].w*b[x+2].h+a[x+2].w*b[x+1].h:a[x+1].w*b[x+1].h+a[x+2].w*b[x+2].h;
	r[2][1]=0;
	r[2][2]=g[x+2]==x+2?-1e18:a[x+2].w*b[x+2].h;
	return r;
}
void build(int k,int l,int r){
	if(l==r)return s[k]=get(l-2),void();
	int m=l+r>>1;
	build(k*2,l,m),build(k*2+1,m+1,r),s[k]=s[k*2]*s[k*2+1];
}
void upd(int k,int l,int r){
	if(l==r)return s[k]=get(l-2),void();
	int m=l+r>>1;
	u>m?upd(k*2+1,m+1,r):upd(k*2,l,m),s[k]=s[k*2]*s[k*2+1];
}
int main(){
	int n,q,i,j,k;
	scanf("%d%d",&n,&q),o[1]=1,o[2]=2;
	for(i=1;i<=n;++i)scanf("%d",&a[i].w),a[i].id=i;
	sort(a+1,a+n+1);
	for(i=1;i<=n;++i)p[a[i].id]=i,scanf("%d",&b[i].h),b[i].id=i;
	sort(b+1,b+n+1);
	for(i=1;i<=n;++i)g[p[b[i].id]]=i;
	if(n==2){
		while(q--){
			scanf("%*d%*d"),swap(g[1],g[2]);
			if(g[1]==1)printf("%lld\n",a[1].w*b[2].h+a[2].w*b[1].h);
			else printf("%lld\n",a[1].w*b[1].h+a[2].w*b[2].h);
		}
		return 0;
	}
	build(1,3,n);
	while(q--){
		scanf("%d%d",&i,&j),i=p[i],j=p[j],swap(g[i],g[j]);
		for(u=max(i,3);u<=min(i+2,n);++u)upd(1,3,n);
		for(u=max(j,3);u<=min(j+2,n);++u)upd(1,3,n);
		printf("%lld\n",s[1].a[0][2]);
	}
	return 0;
}