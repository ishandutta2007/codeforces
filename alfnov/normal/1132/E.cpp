#include<bits/stdc++.h>
#define n 8
#define L 840
using namespace std;
long long f[n+1][L*n+5],a[n+1],W,ans=0;
int main(){
	cin>>W;
	memset(f,-63,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		int gs=L/i,mn=min(a[i],0ll+gs);
		for(int j=0;j<=(i-1)*L;++j)
			for(int k=0;k<=mn;++k){
				long long zz=f[i-1][j]+(a[i]-k)/gs;
				f[i][j+k*i]=max(f[i][j+k*i],zz);
			}
	}
	for(int i=0;i<=n*L&&i<=W;++i){
		ans=max(ans,min(f[n][i],(W-i)/L)*L+i);
	}
	cout<<ans<<endl;
	return 0;
}