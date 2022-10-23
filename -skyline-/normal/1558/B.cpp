#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
using namespace std;
int n;
ll m,dp[4000005];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	dp[n]=1;
	for(int i=n-1;i;--i){
		dp[i]=(dp[i+1]*2)%m;
		for(int j=2;j<=n/i;++j){
			(dp[i]+=dp[i*j]-dp[min((i+1)*j,n+1)])%=m;
		}
	}
	cout<<((dp[1]-dp[2])%m+m)%m<<endl;
    return 0;
}