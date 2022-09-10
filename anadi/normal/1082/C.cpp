#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
vector <int> val[N];
vector <int> cnt[N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		int s, r;
		scanf("%d %d", &s, &r);
		val[s].push_back(r);
		cnt[val[s].size()].push_back(s);
	}
	
	for(int i = 1; i <= m; ++i){
		sort(val[i].begin(), val[i].end());
		reverse(val[i].begin(), val[i].end());

		for(int j = 1; j < val[i].size(); ++j)
			val[i][j] += val[i][j - 1];
	}
	
	int res = 0;
	for(int i = 1; i <= n; ++i){
		int cur = 0;
		for(auto v: cnt[i])
			cur += max(val[v][i - 1], 0);
		res = max(res, cur);
	}
	
	printf("%d\n", res);
	return 0;
}