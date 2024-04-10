#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
char c[300005],d[300005];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int powdv(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return ans;
}
int S[300005],D[300005],mu[300005],tot=0;
void print(){
	S[1]=1,mu[1]=1;
	for(int i=2;i<=300000;++i){
		if(!S[i])D[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&i*D[j]<=300000;++j){
			S[i*D[j]]=1;
			mu[i*D[j]]=-mu[i];
			if(i%D[j]==0){
				mu[i*D[j]]=0;
				break;
			}
		}
	}
}
int main(){
	int n;
	scanf("%s%s%d",c+1,d+1,&n);
	int S=strlen(c+1),T=strlen(d+1);
	print();
	int x=0,y=0;
	int a=0,b=0;
	for(int i=1;i<=S;++i){
		if(c[i]=='A')++a;
		else if(c[i]=='B')--b;
		else ++x;
	}
	for(int i=1;i<=T;++i){
		if(d[i]=='A')--a;
		else if(d[i]=='B')++b;
		else ++y;
	}
	int r=S==T;
	for(int i=1;i<=S&&i<=T;++i){
		if(!r)break;
		if(c[i]==d[i]){
			if(c[i]=='?'&&d[i]=='?')r=(r+r)%mod;
		}else if(c[i]!='?'&&d[i]!='?')r=0;
	}
	int xs=1,ans=0,gs=0;
	for(int k=0;k<=x+y;++k){
		int A=a-y+k,B=b-x+k;
		if(1ll*A*B>0){
			A=abs(A),B=abs(B);
			int rr=1ll*n*gcd(A,B)/max(A,B);
			ans=(ans+1ll*xs*(powdv(2,rr+1)-2))%mod;
		}else if(A==0&&B==0)gs=(gs+xs)%mod;
		xs=1ll*xs*(x+y-k)%mod*powdv(k+1,mod-2)%mod;
	}
	ans=(ans+1ll*(powdv(2,n+1)-2)*(powdv(2,n+1)-2)%mod*r)%mod;
	gs=(gs-r+mod)%mod;
	int he=0;
	for(int i=1;i<=n;++i){
		int hh=0,gs=n/i;
		for(int j=1;j<=gs;++j){
			hh=(hh+1ll*mu[j]*(gs/j)*(gs/j))%mod;
		}
		he=(he+1ll*powdv(2,i)*hh)%mod;
	}
	ans=(ans+1ll*he*gs)%mod;
	ans=(ans+mod)%mod;
	cout<<ans<<endl;
	return 0;
}