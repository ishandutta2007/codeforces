#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
char s[N];
long long int cnt[N];
long long ans[30][30];

int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	
	for(int i = 1; i <= n; ++i){
		int cur = s[i] - 'a';
		for(int j = 0; j < 26; ++j)
			ans[j][cur] += cnt[j];
		cnt[cur]++;
	}
	
	long long int ret = 0;
	for(int i = 0; i < 26; ++i){
		for(int j = 0; j < 26; ++j)
			ret = max(ret, ans[i][j]);
		ret = max(ret, cnt[i]);
	}

	printf("%lld\n", ret);
	return 0;
}