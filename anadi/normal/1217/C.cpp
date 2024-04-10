#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
char s[N];

void solve(){
	scanf("%s", s + 1);
	n = strlen(s + 1);

	int ans = 0;
	for(int i = 1; i <= n; ++i){
		if(s[i] == '0')
			continue;
		
		int prvZero = 0;
		for(int j = i - 1; j >= 1; --j){
			if(s[j] == '1')
				break;
			++prvZero;
		}
		
		int cur = 0;
		for(int j = i; j <= n && cur < N; ++j){
			cur = cur * 2 + s[j] - '0';
			if(cur <= j - i + prvZero + 1)
				++ans;
		}
	}
	
	printf("%d\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}