#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-14;
int cmp(ld x){if(x>eps)return 1;if(x<-eps)return -1;return 0;}
ld M;
ll T;
int n,m;
struct Matrix{
ld a[3][3];
Matrix(){for(int i=0;i<3;i++)for(int j=0;j<3;j++)a[i][j]=0;}
ld*operator[](const int&x){return a[x];}
friend Matrix operator*(Matrix&u,Matrix&v){
	Matrix w;
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)for(int k=0;k<3;k++)w[i][j]+=u[i][k]*v[k][j];
	return w;
}
};
struct Point{
	ld p,A;
	friend bool operator<(const Point&u,const Point&v){return cmp(u.p-v.p)==0?u.A>v.A:u.p<v.p;}
	ld DP(ll i,ld f,ll j){
		Matrix x,z;
		x[0][0]=1-p;
		x[1][0]=p*M,x[1][1]=1;
		x[2][0]=A,x[2][1]=1,x[2][2]=1;
		z[0][0]=z[1][1]=z[2][2]=1;
		for(j-=i;j;j>>=1,x=x*x)if(j&1)z=z*x;
		return z[0][0]*f+z[1][0]*i+z[2][0];
	}
}p[100100],c[100100];
ll tim;ld f;
int main(){
	scanf("%d%lld",&n,&T);
	for(int i=1,a,b;i<=n;i++){
		scanf("%d%d%Lf",&a,&b,&p[i].p);
		p[i].A=a*p[i].p,M=max(M,b*p[i].p);
	}
	sort(p+1,p+n+1);
	c[m=1]=p[1];
	for(int i=2;i<=n;i++){
		if(cmp(p[i].p-p[i-1].p)==0)continue;
//		printf("%Lf\n",(p[i].p-c[m-1].p)*(c[m].A-c[m-1].A)-(c[m].p-c[m-1].p)*(p[i].A-c[m-1].A));
		while(m>=2&&cmp((p[i].p-c[m-1].p)*(c[m].A-c[m-1].A)-(c[m].p-c[m-1].p)*(p[i].A-c[m-1].A))!=1)
			m--;
		c[++m]=p[i];
	}
//	for(int i=1;i<=m;i++)printf("[%Lf,%Lf]",c[i].p,c[i].A);
	for(int i=1;i<m;i++){
		ll l=tim,r=T;
		while(l<r){
			ll mid=(l+r+1)>>1;
			ld S=M*(mid-1)-c[i].DP(tim,f,mid-1);
			if(cmp((S*c[i].p+c[i].A)-(S*c[i+1].p+c[i+1].A))==1)l=mid;else r=mid-1;
		}
//		printf("QWQ:%lld\n",l);
		f=c[i].DP(tim,f,l),tim=l;
	}
	printf("%Lf\n",c[m].DP(tim,f,T));
	return 0;
}