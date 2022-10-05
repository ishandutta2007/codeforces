#include<bits/stdc++.h>
using namespace std;
enum{N=200009,B=453};
char s[N];
int st[N],w[N],a[N*B];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,j,k,u,v,t=0;
	long long ans=0;
	cin>>s+1,n=strlen(s+1);
	for(i=1;i<=n;++i)w[i]=w[i-1]+(s[i]=='1');
	for(i=1;i<B;++i){
		for(j=0;j<=n;++j)k=w[j]*i-j+n,++a[k],st[++t]=k;
		for(;t;--t)if(a[j=st[t]])ans+=a[j]*(a[j]-1ll)/2,a[j]=0;
	}
	for(i=n,st[0]=n+1;i;--i){
		if(s[i]=='1')st[++t]=i;
		for(j=t,k=1;j&&k<B;--j,++k)ans+=max(0,(st[j-1]-i)/k-B+1)-max(0,(st[j]-i)/k-B+1);
	}
	cout<<ans;
	return 0;
}