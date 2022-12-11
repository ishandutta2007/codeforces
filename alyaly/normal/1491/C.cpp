#include<bits/stdc++.h>
#define int long long
#define N 200000
using namespace std;
int T,n,a[N+1],ans,fl[N+1];
signed main(){
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){int na=a[i];
			a[i]=max(1ll,a[i]-fl[i]);
			if(a[i]>1)ans+=a[i]-1,fl[i]+=a[i]-1;
			for(int j=min(n,i+na);j>=i+1;j--)fl[j]++;fl[i+1]+=fl[i]-na;
		}
		cout<<ans<<endl;
		for(int i=1;i<=n+1;i++)a[i]=fl[i]=0;
	}
	return 0;
}
/*

*/