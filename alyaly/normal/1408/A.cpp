#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[3][100001],ans[100001];
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[0][i];
		for(int i=1;i<=n;i++)cin>>a[1][i];
		for(int i=1;i<=n;i++)cin>>a[2][i];
		ans[1]=a[0][1];
		for(int i=2;i<=n;i++){
			for(int j=0;j<=2;j++)if(a[j][i]!=ans[i-1])if(i!=n||a[j][i]!=ans[1])ans[i]=a[j][i];
		}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
	}
	return 0;
}