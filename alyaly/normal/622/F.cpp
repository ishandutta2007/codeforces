#include<bits/stdc++.h>
#define int long long
#define N 1000010
#define P 1000000007
using namespace std;
int n,K,f0[N+1],jc[N+1],njc[N+1],ans;
int ksm(int x,int y){int nans=1;for(;y;y>>=1,x=x*x%P)if(y&1)nans=nans*x%P;return nans;}
int qny(int x){return ksm(x,P-2);}
void ycl(){
	jc[0]=njc[0]=1;for(int i=1;i<=K+1;i++)jc[i]=jc[i-1]*i%P;
	njc[K+1]=qny(jc[K+1]);for(int i=K;i>=1;i--)njc[i]=njc[i+1]*(i+1)%P;
	f0[0]=0;for(int i=1;i<=K+1;i++)f0[i]=(f0[i-1]+ksm(i,K))%P;
}

signed main(){
	cin>>n>>K;
	ycl();
	if(n<=K+1)cout<<f0[n]<<endl;
	else{
		int na=1;for(int i=0;i<=K+1;i++)na=na*(n-i)%P;
		for(int i=0;i<=K+1;i++){
			ans=(ans+f0[i]*na%P*qny(n-i)%P*njc[i]%P*njc[K+1-i]%P*ksm(P-1,K+1-i))%P;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*

*/