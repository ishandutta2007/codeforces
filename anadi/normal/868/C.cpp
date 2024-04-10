#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, k, ile;
bool mask[20];

bool ok(int u){
	int cur[10];
	for(int i = 0; i < k; ++i)
		cur[i] = 0;
	
	for(int j = 0; j < ile; ++j)
		if(u & (1 << j)){
			if(!mask[j + 1])
				return false;
			
			for(int i = 0; i < k; ++i)
				if((j + 1) & (1 << i))
					cur[i]++;
		}

	for(int i = 0; i < k; ++i)
		if(2 * cur[i] > __builtin_popcount(u))
			return false;
	return true;
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i){
		int cur = 0;
		for(int j = 0; j < k; ++j){
			int a;
			scanf("%d", &a);
			cur *= 2;
			cur += a;
		}
		
		mask[cur] = true;
	}
	
	if(mask[0]){
		puts("YES");
		return 0;
	}
	
	ile = (1 << k) - 1;
	for(int i = 1; i < (1 << ile); ++i)
		if(ok(i)){
			puts("YES");
			return 0;
		}
	
	puts("NO");
	return 0;
}