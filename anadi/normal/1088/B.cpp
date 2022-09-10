#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, k;
set <int> S;

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i){
		int v;
		scanf("%d", &v);
		S.insert(v);
	}

	int sb = 0;
	while(k--){
		if(S.size() == 0){
			printf("0\n");
			continue;
		}
		
		printf("%d\n", *S.begin() - sb);
		sb = *S.begin();
		S.erase(S.begin());
	}

	return 0;
}