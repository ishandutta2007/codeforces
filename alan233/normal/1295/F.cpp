// naive problem
#include<bits/stdc++.h>
#define MAXN 110
#define p 998244353
#define int long long
using namespace std;
int n,l[MAXN],r[MAXN],s[MAXN];
int b[MAXN],tot;
int qpow(int x,int y){
	int ret=1;
	for(;y;y>>=1,x=x*x%p)if(y&1)ret=ret*x%p;
	return ret;
}
int C(int x,int y){
	int ret=1;
	for(int i=x;i>=x-y+1;i--)ret=ret*i%p;
	for(int i=y;i;i--)ret=ret*qpow(i,p-2)%p;
	return ret;
}
int f[MAXN][MAXN];
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&l[i],&r[i]);r[i]++;
		b[++tot]=l[i];b[++tot]=r[i];s[i]=r[i]-l[i];
	}sort(b+1,b+tot+1);tot=unique(b+1,b+tot+1)-b-1;
	for(int i=1;i<=n;i++){
		l[i]=lower_bound(b+1,b+tot+1,l[i])-b;
		r[i]=lower_bound(b+1,b+tot+1,r[i])-b;
	}
	f[0][tot]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<tot;j++)
			for(int k=i-1;k>=0;k--){
				if(!(l[k+1]<=j&&j+1<=r[k+1]))break;
				int now=0;
				for(int t=j+1;t<=tot;t++)now=(now+f[k][t])%p;
				now=now*C(b[j+1]-b[j]-1+i-k,i-k)%p;
				f[i][j]=(f[i][j]+now)%p;
			}
	int ans=0;
	for(int i=1;i<tot;i++)ans=(ans+f[n][i])%p;
	for(int i=1;i<=n;i++)ans=ans*qpow(s[i],p-2)%p;
	printf("%lld",ans);
	return 0;
}