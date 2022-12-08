#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2+5;
 
int n,k;
int a[N],b[N];
ll f[N][N];
ll ans,tot;
 
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
	}
	memset(f,-1,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<k;++j)
		if(f[i][j]>=0){
			int wa=j+a[i+1];
			int wb=tot-f[i][j]*k-j+b[i+1];
			f[i+1][wa%k]=max(f[i+1][wa%k],f[i][j]+wa/k+wb/k);
			for(int a1=0;a1<k;++a1){
				if(a1>a[i+1]||k-a1>b[i+1])continue;
				int ca=wa-a1;
				int cb=wb-k+a1;
				f[i+1][ca%k]=max(f[i+1][ca%k],f[i][j]+ca/k+cb/k+1);
			}
		}
		tot+=a[i+1]+b[i+1];
	}
//	for(int i=1;i<=n;++i){
//		for(int j=0;j<k;++j){
//			cout<<f[i][j].first<<" "<<f[i][j].second<<endl;
//		}
//		cout<<endl;
//	}
	ll ans=0;
	for(int i=0;i<k;++i)ans=max(ans,f[n][i]);
	cout<<ans<<endl;
}