#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int T,n,k,a[1003];
long long f[1003],inv[1003];
long long mypow(long long x,long long times){
	if(times==0)return 1;
	long long ret=mypow(x,times/2);ret=ret*ret%mod;
	if(times%2)ret=ret*x%mod;return ret;
}
bool cmp(int a,int b){return a>b;}
int main(){
	cin>>T;
	f[0]=1;for(int i=1;i<1003;i++)f[i]=f[i-1]*i%mod;
	for(int i=0;i<1003;i++)inv[i]=mypow(f[i],mod-2);
	while(T--){
		cin>>n>>k;
		for(int i=0;i<n;i++)scanf("%d",a+i);
		sort(a,a+n,cmp);int i,cnt=0;
		for(int i=0;i<n;i++)
			if(a[k-1]==a[i])cnt++;
		for(i=k-1;i>0;i--)
			if(a[i]!=a[i-1])break;
		cout<<(f[cnt]*inv[k-i]%mod)*inv[cnt-k+i]%mod<<endl;
	}
}