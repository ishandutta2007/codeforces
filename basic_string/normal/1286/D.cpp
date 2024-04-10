#include<bits/stdc++.h>
using namespace std;
enum{N=100009,iv=828542813,P=998244353};
struct M{
	int a[2][2];
	M operator*(const M&b){
		return{int((a[0][0]*1ll*b.a[0][0]+a[0][1]*1ll*b.a[1][0])%P),
		int((a[0][0]*1ll*b.a[0][1]+a[0][1]*1ll*b.a[1][1])%P),
		int((a[1][0]*1ll*b.a[0][0]+a[1][1]*1ll*b.a[1][0])%P),
		int((a[1][0]*1ll*b.a[0][1]+a[1][1]*1ll*b.a[1][1])%P)};
	}
}a[N],s[N*4],w;
int x[N],v[N],p[N],u;
struct Q{
	int v,s,i;bool a,b;
	bool operator<(Q a)const{return s*1ll*a.v<a.s*1ll*v;}
}q[N*2];
int qp(int a,int b){int r=1;for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;return r;}
void bd(int k,int l,int r){
	if(l==r){s[k]=a[l];return;}
	int m=l+r>>1;
	bd(k*2,l,m),bd(k*2+1,m+1,r),s[k]=s[k*2]*s[k*2+1];
}
void upd(int k,int l,int r){
	if(l==r){s[k]=w;return;}
	int m=l+r>>1;
	u>m?upd(k*2+1,m+1,r):upd(k*2,l,m),s[k]=s[k*2]*s[k*2+1];
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,t=0,ans=0;
	for(cin>>n,i=1;i<=n;++i){
		cin>>x[i]>>v[i]>>p[i],p[i]=p[i]*1ll*iv%P;
		a[i]={1-p[i],p[i],1-p[i],p[i]};
	}
	for(i=2;i<=n;++i){
		q[++t]={v[i-1]+v[i],x[i]-x[i-1],i,1,0};
		if(v[i-1]<v[i])q[++t]={v[i]-v[i-1],x[i]-x[i-1],i,0,0};
		else if(v[i-1]>v[i])q[++t]={v[i-1]-v[i],x[i]-x[i-1],i,1,1};
	}
	sort(q+1,q+t+1),bd(1,1,n);
	for(i=1;i<=t;++i){
		u=q[i].i,w={},w.a[q[i].a][q[i].b]=a[u].a[q[i].a][q[i].b],upd(1,1,n);
		ans=(ans+(s[1].a[0][0]+s[1].a[0][1])*1ll*q[i].s%P*qp(q[i].v,P-2))%P;
		a[u].a[q[i].a][q[i].b]=0,w=a[u],upd(1,1,n);
	}
	cout<<(ans+P)%P;
	return 0;
}