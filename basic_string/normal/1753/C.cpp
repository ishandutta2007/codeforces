#include<bits/stdc++.h>
using namespace std;
enum{N=200009,P=998244353};
int w[N];
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	int n,a,b,c,i;
	while(T--){
		cin>>n;a=b=c=0;
		for(i=1;i<=n;++i){
			cin>>w[i];
			if(w[i])++b;else ++a;
		}
		for(i=1;i<=a;++i)if(w[i])++c; 
		int u=n*1ll*(n-1)/2%P,ans=0;
		for(i=1;i<=c;++i)ans=(ans+u*1ll*qp(i,P-2)%P
		*qp(i,P-2))%P;
		cout<<ans<<'\n';
	}
}/*
f[c]=0
f[i]=f[i+1]+
a=2 b=1 c=1
3*(3-1)/2=3
c*c=1
1/3
x=p+(1-p)p*2+(1-p)(1-p)p*3...
(1-p)x=(1-p)p+(1-p)(1-p)p*2...

(1-p)x+p=x */