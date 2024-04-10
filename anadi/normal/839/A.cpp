#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

const int N = 1e5 + 7;
const int inf  = 1e9 + 7;

int n, k;

int main(){
	scanf("%d %d", &n, &k);
	int cur = 0;
	for(int i = 1; i <= n; ++i){
		int a;	scanf("%d", &a);
		cur += a;
		k -= min(cur, 8);
		cur = max(cur - 8, 0);
		if(k <= 0){
			printf("%d\n", i);
			return 0;
		}
	}
	
	puts("-1");
	return 0;
}