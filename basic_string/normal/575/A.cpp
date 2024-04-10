#include<bits/stdc++.h>
using namespace std;
const int N=5e4+3,M=2e5+3,O=1e5+3;
#define ll long long
struct mat{
	int a[2][2];
	int*operator[](int x){return a[x];}
	mat(){memset(a,0,sizeof a);}
}tr[M],a[N];
struct Q{
	ll j;
	int u,v;
	bool operator<(Q a)const{return j<a.j;}
}q[O],q2[O];
int p,s[N],u,n;
mat operator*(mat a,mat b){
	mat r;
	int i,j,k;
	for(i=0;i<2;++i)for(j=0;j<2;++j)for(k=0;k<2;++k)r[i][k]=(r[i][k]+a[i][j]*1ll*b[j][k])%p;
	return r;
}
void build(int k,int l,int r){
	if(l==r)return tr[k]=a[l],void();
	int m=l+r>>1;
	build(k*2,l,m),build(k*2+1,m+1,r),tr[k]=tr[k*2]*tr[k*2+1];
}
void upd(int k,int l,int r){
	if(l==r)return tr[k]=a[l],void();
	int m=l+r>>1;
	u>m?upd(k*2+1,m+1,r):upd(k*2,l,m),tr[k]=tr[k*2]*tr[k*2+1];
}
void mdf(Q q){a[u=q.j%n][q.u][1]=q.v,upd(1,0,n-1);}
mat qp(mat a,ll b){
	mat r;
	for(r[0][0]=r[1][1]=1;b;b>>=1,a=a*a)if(b&1)r=r*a;
	return r;
}
int main(){
	ll o,w,pr=0,r;
	int m,i,k,l,t=0;
	mat ans;
	scanf("%lld%d%d",&o,&p,&n),ans[0][0]=ans[1][1]=1;
	if(o<2)return printf("%lld",o%p),0;
	for(i=0;i<n;++i)scanf("%d",s+i);
	o-=2,scanf("%d",&m);
	for(i=0;i<n;++i)a[i][1][0]=1,a[i][0][1]=s[i],a[i][1][1]=s[(i+1)%n];
	for(i=1;i<=m;++i){
		scanf("%lld%d",&w,&k);
		q[++t]={w-1,1,k},q2[t]={w-1,1,s[w%n]};
		q[++t]={w,0,k},q2[t]={w,0,s[w%n]};
	}
	sort(q+1,q+t+1),sort(q2+1,q2+t+1),k=1,build(1,0,n-1);
	while(1){
		if(k>t||q[k].j/n>=o/n)break;
		r=q[k].j/n,l=k,ans=ans*qp(tr[1],r-pr),pr=r+1;
		while(k<=t&&q[k].j/n==r)++k;
		for(i=l;i<k;++i)mdf(q[i]);
		ans=ans*tr[1];
		for(i=l;i<k;++i)mdf(q2[i]);
	}
	r=o/n,ans=ans*qp(tr[1],r-pr),l=o%n;
	while(k<=t&&q[k].j/n==r)mdf(q[k++]);
	for(i=0;i<=l;++i)ans=ans*a[i];
	printf("%d",ans[1][1]);
	return 0;
}