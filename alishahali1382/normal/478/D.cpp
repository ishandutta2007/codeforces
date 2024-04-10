#include <iostream>
#include <cmath>

using namespace std;

int mod=1e9+7;

int main(){
	int r,g,h,t;
	cin>>r>>g;
	t=r+g;
	h=sqrt(t*2);
	if ((h*(h+1))/2>t){
		h--;
	}
	
	int dp[2][r+1];
	for (int j=0;j<=r;j++){
		dp[0][j]=0;
		dp[1][j]=0;
	}
	dp[0][0]=1;
	//dp[0][1]=1;
	
	
	int x=0;
	for (int i=1;i<=h;i++){
		x+=i;
		for (int j=0;j<=r;j++){
			if (x-j<=g){
				dp[1][j]+=dp[0][j];
			}
			if (j-i>=0){
				dp[1][j]+=dp[0][j-i];
			}
			dp[1][j]=dp[1][j]%mod;
		}
		for (int j=0;j<=r;j++){
			dp[0][j]=dp[1][j];
			dp[1][j]=0;
		}
		/*
		for (int j=0;j<=r;j++){
			cout<<dp[0][j]<<' ';
		}
		cout<<endl;*/
	}
	/*
	for (int i=0;i<=h;i++){
		for (int j=0;j<=r;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}*/
	
	int out=0;
	for (int i=0;i<=r;i++){
		out=(out+dp[0][i])%mod;
	}
	cout<<out<<endl;
	return 0;
}