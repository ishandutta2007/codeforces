#include<bits/stdc++.h>
#define N 1000000
#define int long long
#define P 1000000007
using namespace std;
int n,A,jc[N+1],njc[N+1],ans,aa;
int ksm(int x,int y){int nans=1;for(;y;y>>=1,x=x*x%P)if(y&1)nans=nans*x%P;return nans;}
int qny(int x){return ksm(x,P-2);}
int C(int x,int y){if(y>x||y<0)return 0;return jc[x]*njc[y]%P*njc[x-y]%P;}
void ycl(){
	jc[0]=njc[0]=1;for(int i=1;i<=N;i++)jc[i]=jc[i-1]*i%P;
	njc[N]=qny(jc[N]);for(int i=N-1;i>=1;i--)njc[i]=njc[i+1]*(i+1)%P;
}
void cal0(){
	for(int i=0;i<=n;i++)ans=ans+ksm(P-1,i)*C(n,i)%P*ksm(P+1-ksm(aa,i),n),ans%=P;
//	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)ans=(ans+ksm(P-1,i+j)*C(n,i)%P*C(n,j)%P*ksm(aa,i*j))%P;
	ans=ans*ksm(A-1,n*n)%P;
	cout<<ans<<endl;
}
signed main(){
 //	freopen("flow.in","r",stdin);
//	freopen("flow.out","w",stdout);
	cin>>n>>A;
	if(n==1||A==1){
		cout<<1<<endl;return 0;
	}
	ycl();
	aa=A*qny(A-1)%P;
	cal0();
	return 0;
}
/*

*/