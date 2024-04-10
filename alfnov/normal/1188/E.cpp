#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int a[100005];
int mp[1000005],D[1000005];
int powdv(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int wz=0,mx=a[n];
	D[0]=1;
	for(int i=1;i<=mx;++i){
		D[i]=1ll*D[i-1]*(i+n-1)%mod;
		D[i]=1ll*D[i]*powdv(i,mod-2)%mod;
	}
	long long ans=0;
	long long he=0;
	for(int s=0;s<=mx;++s){
		while(wz+1<=n&&a[wz+1]<s){
			++wz;
			++mp[a[wz]%n];
		}
		he+=mp[(s+n-1)%n];
		if(s>=he){
			ans+=D[s-he];
			if(s-he>=n-wz)ans-=D[s-he-n+wz];
		}
		else break;
	}
	cout<<(ans%mod+mod)%mod<<endl;
	return 0;
}