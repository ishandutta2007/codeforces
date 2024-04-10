#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

long long n,m;
long long dp[64][2][2][2]={0};
long long solve(int i,int c,int d,int l){
	if(i<0){
		return d==1;
	}
	if(dp[i][c][d][l]>=0){
		return dp[i][c][d][l];
	}
	long long ans=0;
	int a=(m>>i)&1,b=(n>>i)&1;
	for(int j=0;j<2;j++){
		if(l && j==1 && a==0){
			continue;
		}
		if(j==0){
			if(b==0){
				ans+=solve(i-1,0,d,l&(j==a));
			}
			else{
				ans+=solve(i-1,c^1,d^1,l&(j==a));
			}
		}
		else{
			if(b==0){
				ans+=solve(i-1,c^1,d,l);
			}
			else{
				ans+=solve(i-1,0,d^c,l);
			}
		}	
	}
	return dp[i][c][d][l]=ans;
}
int main(){
    AquA;
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		m--;
		for(int i=0;i<64;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					for(int l=0;l<2;l++){
						dp[i][j][k][l]=-1;
					}
				}
			}
		}
		cout << solve(63,0,0,1) << "\n";
	}
    return 0;
}