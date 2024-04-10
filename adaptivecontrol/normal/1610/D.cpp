#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,a[200003],dp[2][2][31];
vector<int>v;
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int main(){
	cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		if(a[i]%2==0){
			int cnt=0;
			while(a[i]%2==0)
				a[i]/=2,cnt++;
			v.push_back(cnt);
		}
	}
	int m=v.size();
	dp[0][0][30]=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<31;j++)
			dp[i+1&1][0][j]=dp[i&1][0][j],
			dp[i+1&1][1][j]=dp[i&1][1][j];
		for(int j=0;j<31;j++){
			if(j>v[i]){
				add(dp[i+1&1][0][v[i]],dp[i&1][0][j]);
				add(dp[i+1&1][0][v[i]],dp[i&1][1][j]);
			}
			if(j==v[i]){
				add(dp[i+1&1][1][j],dp[i&1][0][j]);
				add(dp[i+1&1][0][j],dp[i&1][1][j]);
			}
			if(j<v[i]){
				add(dp[i+1&1][0][j],dp[i&1][0][j]);
				add(dp[i+1&1][1][j],dp[i&1][1][j]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<31;i++)
		add(ans,dp[m&1][0][i]);	
	long long nw=1;
	while(n--)nw=nw*2%mod;
	cout<<(nw-ans+mod)%mod;
}