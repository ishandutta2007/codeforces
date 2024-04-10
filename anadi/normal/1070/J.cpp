#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 30 * 1000 + 7;

int n, m, k;
char s[7 * N];

bool dp[N];
int cnt[30];

int ask(int a){
	if(cnt[a] == 0)
		return n * m;

	for(int i = 0; i <= n; ++i)
		dp[i] = false;
	dp[0] = true;
	
	for(int i = 0; i < 26; ++i){
		if(a == i || cnt[i] == 0)
			continue;
		
		for(int j = n; j >= cnt[i]; --j)
			dp[j] |= dp[j - cnt[i]];
	}
	
	int ret = n * m;
	for(int i = max(n - cnt[a], 0); i <= n; ++i){
		if(!dp[i])
			continue;
		
		if(k - i - cnt[a] >= m)
			return 0;
		ret = min(ret, (n - i) * (m - k + i + cnt[a]));
	}
	
//	printf("%d :: %d\n", a, ret);
	return ret;
}

void solve(){
	for(int i = 0; i < 26; ++i)
		cnt[i] = 0;

	scanf("%d %d %d", &n, &m, &k);
	scanf("%s", s + 1);
	
	for(int i = 1; i <= k; ++i)
		cnt[s[i] - 'A']++;
	
	int res = n * m;
	for(int i = 0; i < 26; ++i)
		res = min(res, ask(i));
	printf("%d\n", res);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}