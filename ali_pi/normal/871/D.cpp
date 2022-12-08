#include <bits/stdc++.h>

using namespace std;
const int N=1E7+5;
long long n,m,T,phi[N],f[N],prim[N],tot,sum,o[N],t1,t2;
long long ans,ans2;

int main(){
	cin>>n;
	phi[1]=1;
	for (int i=2;i<=n;i++) {
		if (!o[i]) {
			if ((long long)i*i>n) t1++;
			if (i*2>n) t2++;
			prim[++tot]=i; phi[i]=i-1;
			o[i]=i;
		}
		for (int j=1;j<=tot&&(long long)i*prim[j]<=n;j++){
			o[i*prim[j]]=prim[j];
			if (i%prim[j]==0) { phi[i*prim[j]]=phi[i]*prim[j]; break; } else phi[i*prim[j]]=phi[i]*(prim[j]-1); 
		}
		ans+=i-phi[i]-1;
		if (o[i]*o[i]<=n) ans+=(phi[i]-1-t1)*2;
		f[o[i]]++;
	}
	for (int i=1;i<=n;i++) f[i]+=f[i-1];
	for (int i=2;2*i<=n;i++) if (o[i]*o[i]>n){
		sum=n/i-1;
		ans+=2*sum+2*(f[n/i]-sum)+3*(n-f[n/i]-2-t2);
	}
	t1-=t2;
	cout<<ans-(long long)3*(t1-1)*t1/2;
}