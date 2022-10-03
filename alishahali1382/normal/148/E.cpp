#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int T[n];
	int L[n][102];
	for (int i=0;i<n;i++){
		cin>>T[i];
		int ps[T[i]+1];
		ps[0]=0;
		for (int j=1;j<=T[i];j++){
			cin>>ps[j];
			ps[j]+=ps[j-1];
		}
		for (int j=0;j<102;j++){
			L[i][j]=0;
		}
		for (int j=0;j<=T[i];j++){
			for (int k=0;k<=T[i] && k<=j;k++){
				L[i][j]=max(L[i][j],ps[k]+ps[T[i]]-ps[T[i]-j+k]);
			}
		}
	}
	/*
	for (int i=0;i<n;i++){
		cout<<endl;
		for (int j=0;j<=T[i];j++){
			cout<<L[i][j]<<' ';
		}
	}
	cout<<endl<<endl;*/
	
	
	
	int dp[n+1][m+1];
	for (int i=0;i<=n;i++){
		for (int j=0;j<=m;j++){
			dp[i][j]=0;
		}
	}
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			for (int k=0;k<=j && k<=T[i-1];k++){
				dp[i][j]=max(dp[i][j],dp[i-1][j-k]+L[i-1][k]);
				//cout<<i<<' '<<j<<' '<<k<<endl;
			}
		}
	}
	/*
	for (int i=0;i<=n;i++){
		cout<<endl;
		for (int j=0;j<=m;j++){
			cout<<dp[i][j]<<' ';
		}
	}
	cout<<endl<<endl;*/
	
	cout<<dp[n][m]<<endl;
	return 0;
}