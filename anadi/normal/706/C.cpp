#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define pb push_back
#define mp make_pair
#define PII pair <int, int>
#define st first
#define nd second
#define PLL pair <LL, LL>
#define PDD pair <D, D>

const int N = 1e5 + 7;
const LL INF = 100000000000000000LL;

int n;
LL cost[N];
string s[N];
string r[N];
LL dp[N][2];

void odwroc(int a){
	for(int i = s[a].size() - 1; i >= 0; --i)
		r[a].push_back(s[a][i]);
}

bool ok(string a, string b){
	return a <= b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> cost[i];
	
	for(int i = 1; i <= n; ++i)
		cin >> s[i],
		odwroc(i);
	
	dp[1][1] = cost[1];
	for(int i = 2; i <= n; ++i){
		dp[i][0] = dp[i][1] = INF;
		if(ok(s[i - 1], s[i]))
			dp[i][0] = min(dp[i - 1][0], dp[i][0]);
		if(ok(r[i - 1], s[i]))
			dp[i][0] = min(dp[i - 1][1], dp[i][0]);
		if(ok(s[i - 1], r[i]))
			dp[i][1] = min(dp[i - 1][0] + cost[i], dp[i][1]);
		if(ok(r[i - 1], r[i]))
			dp[i][1] = min(dp[i - 1][1] + cost[i], dp[i][1]);
	}
	
	if(dp[n][0] == INF && dp[n][1] == INF)
		cout << "-1";
	else
		cout << min(dp[n][0], dp[n][1]);
	cout << "\n";
	return 0;
}