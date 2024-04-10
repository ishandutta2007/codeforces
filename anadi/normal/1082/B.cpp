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

int n;
char s[N];
int pref[N];

int main(){
	scanf("%d", &n);
	scanf("%s", s + 1);
	
	int gold = 0;
	for(int i = 1; i <= n; ++i){
		gold += s[i] == 'G';
		pref[i] = pref[i - 1] + (s[i] == 'S');
	}
	
	int cnt = 0;
	int longestGold = 0, cur = 0;

	for(int i = 1; i <= n; ++i){
		if(s[i] == 'S'){
			longestGold = max(longestGold, cur);
			cur = 0;
		}
		else{
			if(cur == 0)
				++cnt;
			++cur;
		}
	}

	longestGold = max(longestGold, cur);	
	if(cnt <= 1){
		printf("%d\n", gold);
		return 0;
	}
	
	if(cnt == 2){
		int wsk[2] = {0, 0};
		for(int i = 1; i <= n; ++i)
			if(s[i] == 'G' && s[i - 1] != 'G'){
				if(wsk[0] == 0)
					wsk[0] = i;
				else
					wsk[1] = i;
			}
		
		if(s[wsk[1] - 2] == 'S')
			printf("%d\n", longestGold + 1);
		else
			printf("%d\n", gold);
		return 0;
	}
	
	int wsk = 1;
	int res = longestGold + 1;
	for(int i = 1; i <= n; ++i){
		if(s[i] == 'S')
			continue;
		
		while(wsk <= n && pref[wsk] - pref[i - 1] <= 1)
			++wsk;
		res = max(res, wsk - i);
	}
	
	printf("%d\n", res);
	return 0;
}