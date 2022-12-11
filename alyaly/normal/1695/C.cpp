#include<bits/stdc++.h>
#define int long long
#define N 1000
#define inf 999999999999
using namespace std;
int T,n,m,a[N+1][N+1],mi[N+1][N+1],mx[N+1][N+1];
void putin(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
}
signed main(){
	cin>>T;
	for(int i=2;i<=N;i++)mi[0][i]=mi[i][0]=inf,mx[0][i]=mx[i][0]=-inf;
	while(T--){
		putin();
		if((n+m)%2==0)cout<<"NO\n";
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					mi[i][j]=min(mi[i-1][j],mi[i][j-1])+a[i][j];
					mx[i][j]=max(mx[i-1][j],mx[i][j-1])+a[i][j];
				}
			}
			if(mi[n][m]<=0&&mx[n][m]>=0)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}