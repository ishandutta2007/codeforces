#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int powdv(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return ans;
}
int p[5005];
int ss[5005][5005];
int main(){
	int T=1;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)scanf("%d",&p[i]);
		for(int i=1;i<=n+1;++i)for(int j=1;j<=n+1;++j)
			ss[i][j]=0;
		for(int b=1;b<=n;++b){
			for(int d=b+1;d<=n;++d){
				if(p[b]>p[d])++ss[b][d];
			}
		}
		for(int b=n;b>=1;--b)for(int d=n;d>=1;--d)
			ss[b][d]+=ss[b+1][d]+ss[b][d+1]-ss[b+1][d+1];
		long long ans=0;
		for(int b=1;b<=n;++b){
			for(int d=b+1;d<=n;++d){
				if(p[b]<p[d]){
					ans+=ss[b+1][d+1]-ss[d][d+1];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}