#include <iostream>

using namespace std;

long long dp[100001];
int L[100001];

int main(){
	int n,ai;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>ai;
		L[ai]++;
	}
	dp[1]=L[1];
	for (int i=2;i<1e5+1;i++){
		dp[i]=max(dp[i-1],dp[i-2]+(long long)L[i]*i);
	}
	cout<<dp[100000]<<endl;
}