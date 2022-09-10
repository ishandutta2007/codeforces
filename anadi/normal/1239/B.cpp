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
char in[N];
int prefVal[N];
int pref[3][N];

int mn = 0, best = 0;
int ox = 0, oy = 0;

void Try(int a, int b, int df){
	int cand = 0, cnt = 0;
	for(int i = 1; i <= n; ++i){
		int cv = prefVal[i];
		if(a <= i && i <= b)
			cv += df;
		
		if(cv < cand){
			cand = cv;
			cnt = 0;
		}

		if(cv == cand)
			++cnt;
	}
	
	if(cnt > best){
		best = cnt;
		ox = a, oy = b + 1;
	}
}

void firstCase(){
	int firstMn = n, lastMn = 1;
	for(int i = 1; i <= n; ++i)
		if(prefVal[i] == mn){
			firstMn = min(firstMn, i);
			lastMn = max(lastMn, i);
		}
	
	Try(firstMn, lastMn, 2);
	for(int i = 1; i <= n; ++i)
		if(prefVal[i] == mn + 1){
			firstMn = min(firstMn, i);
			lastMn = max(lastMn, i);
		}
	
	Try(firstMn, lastMn, 2);
}

void secondCase(){
	for(int i = 1; i <= n; ++i){
		if(in[i] == ')')
			continue;
		
		int sum = 0, maybe = (prefVal[i] == mn + 1);
		int lastClose = -1;
		int wsk = i;
		
		while(wsk < n){
			++wsk;
			if(in[wsk] == ')'){
				lastClose = wsk;
				sum += maybe;
				maybe = 0;
			}
			
			if(prefVal[wsk] == mn + 1)
				++maybe;

			if(prefVal[wsk] == mn)
				break;
		}
		
		if(lastClose == -1)
			break;
		
		if(sum > best){
			best = sum;
			ox = i, oy = lastClose;
		}
		
		i = wsk;
	}
}

void thirdCase(){
	for(int i = 1; i <= n; ++i){
		if(in[i] == ')' || prefVal[i] == mn + 1)
			continue;

		int sum = 0, maybe = (prefVal[i] == mn + 2);
		int lastClose = -1;
		int wsk = i;

		while(wsk < n){
			++wsk;
			if(in[wsk] == ')'){
				lastClose = wsk;
				sum += maybe;
				maybe = 0;
			}
			
			if(prefVal[wsk] == mn + 2)
				++maybe;

			if(prefVal[wsk] == mn || prefVal[wsk] == mn + 1)
				break;
		}
		
		if(lastClose == -1)
			break;
		
		if(sum + pref[0][n] > best){
			best = sum + pref[0][n];
			ox = i, oy = lastClose;
		}
		
		i = wsk;
	}
}

int main(){
	scanf("%d", &n);
	scanf("%s", in + 1);
	
	for(int i = 1; i <= n; ++i){
		prefVal[i] = prefVal[i - 1] + (in[i] == '(' ? 1 : -1);
		mn = min(mn, prefVal[i]);
	}
	
	if(prefVal[n] != 0){
		puts("0");
		puts("1 1");
		exit(0);
	}
	
	for(int t = 0; t < 3; ++t)
		for(int i = 1; i <= n; ++i)
			pref[t][i] = pref[t][i - 1] + (prefVal[i] == (mn + t));
	
	best = pref[0][n];
	ox = 1, oy = 1;
	
	firstCase();
	secondCase();
	thirdCase();
	
	printf("%d\n%d %d\n", best, ox, oy);
	return 0;
}