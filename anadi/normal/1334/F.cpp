#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int T = 1 << 19;

const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
int a[N], p[N];

LL dp[N];
vector <int> ids[N];

int m;
int b[N];

bool check(){
	int it = 1;
	for(int i = 1; i <= m; ++i){
		while(it <= n && a[it] != b[i])
			++it;
		
		if(it > n)
			return false;
		++it;
	}
	
	return true;
}

void solve(int t){
	int it = 0;
	LL cur = INF;
	
	LL sum = 0;
	vector <int> all;
	
	for(int i = b[t - 1] + 1; i <= b[t]; ++i)
		for(auto v: ids[i]){
			if(p[v] < 0)
				continue;

			sum += p[v];
			all.push_back(v);
		}
	
	int ptr = 0;
	sort(all.begin(), all.end());

	for(auto v: ids[b[t]]){
		while(it < (int)ids[b[t - 1]].size() && ids[b[t - 1]][it] < v){
			int pos = ids[b[t - 1]][it];
			cur = min(cur, dp[pos]);
			++it;
		}
		
		while(ptr < (int)all.size() && all[ptr] <=	 v)
			sum -= p[all[ptr++]];
		
		dp[v] = cur - sum - p[v];
//		printf("dp[%d] = %lld\n", v, dp[v]);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		ids[a[i]].push_back(i);
	}

	for(int i = 1; i <= n; ++i)
		scanf("%d", &p[i]);
	
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &b[i]);
	
	if(!check()){
		puts("NO");
		return 0;
	}
	
	puts("YES");
	for(int i = 1; i <= n; ++i){
		dp[i] = INF;
		dp[0] += p[i];
	}
	
	b[++m] = n + 1;
	a[n + 1] = n + 1;

	ids[0].push_back(0);
	ids[n + 1].push_back(n + 1);
	
	int it = 1;
	for(int i = 1; i <= n + 1; ++i){
		if(b[it] != i)
			continue;
		
		solve(it);
		++it;
	}
	
	printf("%lld\n", dp[n + 1]);
	return 0;
}