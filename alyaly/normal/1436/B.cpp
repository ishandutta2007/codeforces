#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,K,a[101][101],ans,ng;
bool isp(int x){for(int i=2;i<=sqrt(x);i++)if(x%i==0)return 0;return 1;}
signed main(){
	cin>>T;
	while(T--){
		cin>>n;ng=401;
		for(int i=3;i<=n;i++)a[1][i]=4,ng-=4;a[1][1]=1,ng--;a[1][2]=ng;
		for(int i=2;i<=n;i++){
			for(int j=1;j<n;j++)a[i][j]=a[i-1][j+1];a[i][n]=a[i-1][1];
		}
		for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=n;j++)printf("%lld ",a[i][j]);
	}
	return 0;
}