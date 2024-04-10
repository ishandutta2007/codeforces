#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

LL dp[20][700][2];

LL solve(string a){
	a = "#" + a;
	dp[0][0][1] = 1;
	
	for(int i = 1; i < (int)a.size(); ++i)
		for(int v = 0; v < 4; ++v)
			dp[i][v][0] = dp[i][v][1] = 0;
	
	for(int i = 0; i + 1 < (int)a.size(); ++i){
		for(int v = 0; v < 4; ++v){
			dp[i + 1][v][0] += dp[i][v][0];
			if(a[i + 1] == '0')
				dp[i + 1][v][1] += dp[i][v][1];
			else
				dp[i + 1][v][0] += dp[i][v][1];

			for(int c = 1; c <= 9; ++c){
				dp[i + 1][v + 1][0] += dp[i][v][0];
				if(c + '0' < a[i + 1])
					dp[i + 1][v + 1][0] += dp[i][v][1];
				else if(c + '0' == a[i + 1])
					dp[i + 1][v + 1][1] += dp[i][v][1];
			}
		}
	}
	
	LL ret = 0LL;
	for(int v = 0; v < 4; ++v)
		ret += dp[(int)a.size() - 1][v][0] + dp[(int)a.size() - 1][v][1];	
	return ret;
}

bool elegant(string a){
	int mask = 0;
	for(auto v: a)
		if(v != '0')
			++mask;
	return mask < 4;
}

int main(){
	int quest;
	cin >> quest;
	while(quest--){
		string a, b;
		cin >> a >> b;
		cout << solve(b) - solve(a) + elegant(a) << "\n";
	}

	return 0;
}