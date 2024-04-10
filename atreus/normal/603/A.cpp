#include <math.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 500;
int dp[maxn];


int main(){
	int n;
	string s;
	cin >> n >> s;
	dp[0] = 1;
	for (int i = 1; i < n; i++){
		if (s[i] == s[i - 1])
			dp[i] = dp[i - 1];
		else
			dp[i] = dp[i - 1] + 1;
	}
	int k = 0;
	for (int i = 0; i < n - 1; i++)
		if (s[i] == s[i + 1])
			k ++;
	cout << min(dp[n - 1] + min(k, 2), n) << endl;
	return 0;
}