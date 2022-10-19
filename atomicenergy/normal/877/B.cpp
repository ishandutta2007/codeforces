#include <iostream>

using namespace std;

int main(){
	int dp[5001][3];
	string str;
	cin >> str;
	for(int i=0; i<=str.size(); i++){
		if(i==0){
				dp[i][0] = 0;
				dp[i][1] = 0;
				dp[i][2] = 0;
			}else{
				if(str[i-1] == 'a'){
					
					dp[i][0] = dp[i-1][0] + 1;
					dp[i][1] = max(dp[i-1][0] + 1, dp[i-1][1]);
					dp[i][2] = max(dp[i-1][0]+1, max(dp[i-1][1] + 1, dp[i-1][2] + 1));
				}else{
					dp[i][0] = dp[i-1][0];
					dp[i][1] = max(dp[i-1][0] + 1, dp[i-1][1] + 1);
					dp[i][2] = max(dp[i-1][0]+1, max(dp[i-1][1] + 1, dp[i-1][2]));
				}
			}
		}
cout << dp[str.size()][2] << endl;
}