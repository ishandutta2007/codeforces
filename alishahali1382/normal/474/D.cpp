#include <iostream>

using namespace std;

const int mod=1e9+7;
int dp[100001];

int main(){
	int t,k;
	cin>>t>>k;
	dp[0]=1;
	for (int i=1;i<=100000;i++){
		dp[i]=dp[i-1];
		if (i>=k){
			dp[i]=(dp[i]+dp[i-k])%mod;
		}
	}
	int ps[100001];
	ps[0]=0;
	for (int i=1;i<=100000;i++){
		ps[i]=(ps[i-1]+dp[i])%mod;
	}
	
	for (int i=0;i<t;i++){
		int a,b;
		cin>>a>>b;
		cout<<(ps[b]-ps[a-1]+mod)%mod<<endl;
	}
	
	cout<<endl;
	return 0;
}