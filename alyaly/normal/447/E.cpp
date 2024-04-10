//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mid (l+r)/2
#define int long long
#define N 300000
#define P 1000000009
using namespace std;
int n,Q,a[N+1],s[N+1],f[N+1],sf[N+1],q0,q1,q2,ff[N+1];
int seg[4*N+1],s0[4*N+1],s1[4*N+1];
void segdown(int u,int l,int r){
	if(!s0[u]&&!s1[u])return;
	seg[u]+=sf[r-l]*s0[u]%P+(sf[r-l+1]+P-1)*s1[u]%P,seg[u]%=P;
	if(l!=r){
		s0[u*2]+=s0[u],s0[u*2]%=P,s1[u*2]+=s1[u],s1[u*2]%=P;
		s0[u*2+1]+=f[mid-l+2]*s1[u]%P+f[mid-l+1]*s0[u]%P,s0[u*2+1]%=P;
		s1[u*2+1]+=f[mid-l+3]*s1[u]%P+f[mid-l+2]*s0[u]%P,s1[u*2+1]%=P;
	}
	s0[u]=s1[u]=0;
}
void segup(int u,int l,int r){
	segdown(u,l,r);
	if(l!=r)segdown(u*2,l,mid),segdown(u*2+1,mid+1,r),seg[u]=(seg[u*2]+seg[u*2+1])%P;
}
void segadd(int u,int l,int r,int nl,int nr,int n0,int n1){
	if(l>nr||r<nl)return;
	else if(l>=nl&&r<=nr)s0[u]=(s0[u]+n0)%P,s1[u]=(s1[u]+n1)%P;
	else{
		segdown(u,l,r);
		segadd(u*2,l,mid,nl,nr,n0,n1);
		segadd(u*2+1,mid+1,r,nl,nr,(f[mid-l+2]*n1+f[mid-l+1]*n0)%P,(f[mid-l+3]*n1+f[mid-l+2]*n0)%P);
		segup(u,l,r);
	}
}
int segreq(int u,int l,int r,int nl,int nr){
	if(l>nr||r<nl)return 0;
	else if(l>=nl&&r<=nr)return segup(u,l,r),seg[u];
	else{
		segup(u,l,r);
		return (segreq(u*2,l,mid,nl,nr)+segreq(u*2+1,mid+1,r,nl,nr))%P;
	}
}
signed main(){
//	freopen("late.in","r",stdin);
//	freopen("late.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=(s[i-1]+a[i])%P;
	f[0]=sf[0]=sf[1]=1;
	for(int i=2;i<=n;i++)f[i]=(f[i-1]+f[i-2])%P,sf[i]=(sf[i-1]+f[i])%P;
	ff[0]=ff[1]=1;
	for(int i=3;i<=n;i++)ff[i]=(ff[i-2]-ff[i-1]+P)%P;
	for(int i=1;i<=Q;i++){
		cin>>q0>>q1>>q2;
		if(q0==1)segadd(1,1,n,q1,q2,ff[q1],ff[q1-1]);
		else cout<<(segreq(1,1,n,q1,q2)+s[q2]-s[q1-1]+P)%P<<'\n';
	}
	return 0;
}
/*

*/