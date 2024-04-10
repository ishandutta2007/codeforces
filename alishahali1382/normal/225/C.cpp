#include <bits/stdc++.h>

using namespace std;

const int MAXN=1010;
const int inf=99999999;

int n, m, x, y;
int A[MAXN];
int ps[MAXN];
int dp[MAXN][2];

char ch;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n>>m>>x>>y;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin>>ch;
			A[j]+=ch=='#';
		}
	}
	for (int i=1; i<=m; i++) ps[i]=ps[i-1]+A[i];
	/*
	for (int i=0; i<=m; i++) cerr<<ps[i]<<' ';
	cerr<<endl;
	*/
	for (int i=1; i<=m; i++){
		dp[i][0]=dp[i][1]=inf;
		for (int j=x; j<=y && i-j>=0; j++){
			dp[i][0]=min(dp[i][0], dp[i-j][1] + j*n-(ps[i]-ps[i-j]));
			dp[i][1]=min(dp[i][1], dp[i-j][0] + ps[i]-ps[i-j]);
		}
		//cerr<<dp[i][0]<<' '<<dp[i][1]<<endl;
	}
	cout<<min(dp[m][0], dp[m][1])<<endl;
	
	return 0;
}