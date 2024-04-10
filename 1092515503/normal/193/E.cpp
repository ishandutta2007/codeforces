#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N=1000,M=1e13,P=1500;
ll n;
ll mod;
ll ksc(ll x,ll y){
	ll z=0;
	for(;y;y>>=1,(x<<=1)%=mod)if(y&1)(z+=x)%=mod;
	return z;
}
struct Matrix{
	ll a[2][2];
	Matrix(){memset(a,0,sizeof(a));}
	ll*operator[](const int&x){return a[x];}
	friend Matrix operator*(Matrix&u,Matrix&v){
		Matrix w;
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)(w[i][j]+=ksc(u[i][k],v[k][j]))%=mod;
		return w;
	}
};
ll kth(ll k){
	Matrix p,q;
	p[0][0]=p[1][1]=1;
	q[0][1]=1,q[1][1]=1,q[1][0]=1;
	for(;k;k>>=1,q=q*q)if(k&1)p=p*q;
	return p[1][0];
}
vector<ll>u,v;
ll res=0x3f3f3f3f3f3f3f3f;
int main(){
	scanf("%lld",&n);
	if(n%N==0)u.push_back(0);
	if(n%N==1)u.push_back(1);
	for(int i=2,x=1,y=1;i<P;i++,swap(x,y),(y+=x)%=N)if(y==n%N)u.push_back(i);
//	for(int i=0;i<N;i++)printf("%d ",f[i]);puts("");
	while(N<M){
		if(u.empty()){puts("-1");return 0;}
		mod=N*=10;
		bool ok=false;
		for(auto r:u)for(int i=0;i<10;i++)if(kth(P*i+r)==n%N)v.push_back(r+P*i);
		u=v,v.clear();
		P*=10;
	}
	if(u.empty()){puts("-1");return 0;}
	for(auto i:u)res=min(res,i);
	printf("%lld\n",res);
	return 0;
}