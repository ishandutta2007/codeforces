#include<bits/stdc++.h>
using namespace std;
const int N=3409,P=1e9+7;
char s[N];
long long a[N],f[N][2][2],g[N][2][2];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int alpha,p,n,m=1,i,j,v0,v1,v2,v3,v4,v5;
	long long f0,f1,f2,f3;
	cin>>p>>alpha>>s+1,n=strlen(s+1);
	if(n==1&&s[1]=='0')cout<<0,exit(0);
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j)a[j]=a[j]*10ll;
		for(a[1]+=s[i]-48,j=1;j<=m;++j){
			a[j+1]+=a[j]/p,a[j]%=p;
			if(a[m+1])++m;
		}
	}
	f[0][1][0]=1;
	for(i=m;i;--i){
		v0=p*(p+1ll)/2%P,v1=p*(p-1ll)/2%P;
		v2=a[i]*(a[i]+1ll)/2%P,v3=a[i]*(a[i]-1ll)/2%P;
		v4=a[i]*(p+p-a[i]-1ll)/2%P,v5=a[i]*(p+p-a[i]+1ll)/2%P;
		memset(g,0,sizeof g);
		for(j=0;j<=m-i;++j){
			f0=f[j][0][0],f1=f[j][0][1],f2=f[j][1][0],f3=f[j][1][1];
			(g[j][0][0]+=f0*v0+f2*v2)%=P;
			(g[j][0][1]+=f0*v1+f2*v3)%=P;
			(g[j][1][0]+=f2*(a[i]+1))%=P;
			(g[j][1][1]+=f2*a[i])%=P;
			(g[j+1][0][0]+=f1*v1+f3*v4)%=P;
			(g[j+1][0][1]+=f1*v0+f3*v5)%=P;
			(g[j+1][1][0]+=f3*(p-a[i]-1))%=P;
			(g[j+1][1][1]+=f3*(p-a[i]))%=P;
		}
		memcpy(f,g,sizeof g);
	}
	for(i=alpha,j=0;i<=m;++i)j=(j+f[i][1][0]+f[i][0][0])%P;
	cout<<j;
	return 0;
}