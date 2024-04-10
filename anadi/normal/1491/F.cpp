#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;
const LL INF = 1LL * MOD * MOD;

int n;
bool bad[N];

void solve() {
	scanf("%d", &n); 
	for(int i = 1; i <= n; ++i)
		bad[i] = false;
	
	int k = -1, sum = 0;
	for(int i = 1; i <= n; ++i) {
		printf("? %d %d\n", 1, n - i);
		printf("%d\n", i);
		for(int j = i + 1; j <= n; ++j)
			printf("%d ", j);
		puts("");
		fflush(stdout);
		
		int t;
		scanf("%d", &t);
		
		if(t != 0) {
			k = i;
			sum = t;
			bad[k] = true;
			break;
		}
	}
	
	for(int i = k + 1; i < n; ++i) {
		printf("? %d %d\n", 1, 1);
		printf("%d\n%d\n", k, i);
		fflush(stdout);
		
		int t;
		scanf("%d", &t);
		
		if(t != 0)
			bad[i] = true;
		sum -= t;
	}
	
	if(sum != 0)
		bad[n] = true;
	
	int l = 0, r = k - 1;
	while(l < r) {
		int mid = (l + r + 1) / 2;
		printf("? %d %d\n", k - mid, 1);
		for(int i = mid; i < k; ++i)
			printf("%d ", i);
		printf("\n%d\n", k);
		fflush(stdout);
		
		int t;
		scanf("%d", &t);
		
		if(t != 0)
			l = mid;
		else
			r = mid - 1;
	}
	
	bad[l] = true;
	vector <int> ans;
	
	for(int i = 1; i <= n; ++i)
		if(!bad[i])
			ans.push_back(i);
	
	printf("! %d", (int)ans.size());
	for(auto v: ans)
		printf(" %d", v);
	puts("");
	fflush(stdout);
}

int main() {
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}