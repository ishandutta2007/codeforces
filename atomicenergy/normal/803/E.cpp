#include <iostream>
#include <vector>
using namespace std;

int dp[1005][2005];

vector<char> v;

int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	dp[0][1002] = 0;
	for(int j=-k; j<=k; j++){
		if(j!=0){
			dp[0][j+1002] = -5;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=-k; j<=k; j++){
			dp[i+1][j+1002] = -5; 
			if(s[i]=='D' ){
				if(dp[i][j+1002]!=-5)
				dp[i+1][j+1002] = 0; 
			}
			else if(s[i] == 'W'){
				if(j!=-k && !(j==k && i!=n-1) && dp[i][j-1+1002] != -5){
					dp[i+1][j+1002] = 1; 
				}
			}
			else if(s[i] == 'L'){
				if(j!=k && !(j==-k && i!=n-1)&& dp[i][j+1+1002] != -5){
					dp[i+1][j+1002] = -1; 
				}
			}
			else{
				if(dp[i][j+1002]!=-5){
					dp[i+1][j+1002] = 0;
				}
				if(j!=-k && !(j==k && i!=n-1) && dp[i][j-1+1002] != -5){
					dp[i+1][j+1002] = 1;
				}
				if(j!=k && !(j==-k && i!=n-1)&& dp[i][j+1+1002] != -5){
					dp[i+1][j+1002] = -1; 
				}
			}
			if(dp[i+1][j+1002]!=-5){
				//cout << i << "  " << j <<"   " << dp[i+1][j+1002] <<endl;
			} 
		}
	}
	if(dp[n][k+1002]!=-5){
		int p1 = n;
		int p2 = k;
		while(p1!=0){
			if(dp[p1][p2+1002] == 0) v.push_back('D');
			if(dp[p1][p2+1002] == 1) v.push_back('W');
			if(dp[p1][p2+1002] == -1) v.push_back('L');
			p2-=dp[p1][p2+1002];
			p1--;
		}
		for(int i=0; i<v.size(); i++){
			cout << v[v.size()-1-i];
		}
		cout << endl;
	}
	else if(dp[n][-k+1002]!=-5){
		int p1 = n;
		int p2 = -k;
		while(p1!=0){
			if(dp[p1][p2+1002] == 0) v.push_back('D');
			if(dp[p1][p2+1002] == 1) v.push_back('W');
			if(dp[p1][p2+1002] == -1) v.push_back('L');
			p2-=dp[p1][p2+1002];
			p1--;
		}
			for(int i=0; i<v.size(); i++){
			cout << v[v.size()-1-i];
		}
		cout << endl;
	}
	else{
		cout << "NO" << endl;
	}
}