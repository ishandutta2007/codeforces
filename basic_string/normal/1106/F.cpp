#include<bits/stdc++.h>
using namespace std;
enum{P=998244353,P2=P-1,N=109};
int o,y,n,m;
struct M{
	int a[N][N];
}a,_;
M mul(M a,M b){
	M r=_;
	int i,j,k;
	for(i=1;i<=o;++i)for(j=1;j<=o;++j)for(k=1;k<=o;++k)r.a[i][k]=(r.a[i][k]+a.a[i][j]*1ll*b.a[j][k])%P2;
	return r;
}
M qp(M a,int b){
	M r=_;
	for(int i=1;i<=o;++i)r.a[i][i]=1;
	for(;b;b>>=1,a=mul(a,a))if(b&1)r=mul(r,a);
	return r;
}
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
map<int,int>mp;
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i,j,b;
	for(cin>>o,i=1;i<o;++i)a.a[i+1][i]=1;
	for(i=o;i;--i)cin>>a.a[i][o];
	cin>>n>>m,y=qp(a,n-o).a[o][o],b=sqrt(P*1.)+2,y=qp(3,y);
	for(i=1;i<=b;++i)m=m*1ll*y%P,mp[m]=i;
	for(i=j=1,y=qp(y,b);i<=b;++i)if(j=j*1ll*y%P,mp[j])cout<<qp(3,i*b-mp[j]),exit(0);
	cout<<-1;
	return 0;
}