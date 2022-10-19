#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;



int main() {
	long long  n;
	long long p, q, r;
	cin >> n;
	cin >> p >> q >> r;
	
	long long dp[100005][4];
	for(int i=0; i<n; i++){
		long long x;
		cin >> x;
		dp[i][0] = 0;
		dp[i][1] = p*x;
		dp[i][2] = (p+q)*x;
		dp[i][3] = (p+q+r)*x;
		if(i!=0){
			dp[i][1] = max(dp[i-1][1], dp[i][0] + p*x);
			dp[i][2] = max(dp[i-1][2], dp[i][1] + q*x);
			dp[i][3] = max(dp[i-1][3], dp[i][2] + r*x);
		}
		
	}
	cout << dp[n-1][3] << endl;
}