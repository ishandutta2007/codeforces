#include<bits/stdc++.h>
#define int long long
#define N 100
using namespace std;
int T,n,m,a[N+1][N+1],kx,ky;
void putin(){
	cin>>n>>m;
	kx=ky=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		cin>>a[i][j];
		if(a[i][j]>a[kx][ky])kx=i,ky=j;
	}
}
signed main(){
	a[0][0]=-999999999999ll;
	cin>>T;
	while(T--){
		putin();
		cout<<max(kx,n-kx+1)*max(ky,m-ky+1)<<endl;
	}
	return 0;
}