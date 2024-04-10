#include <bits/stdc++.h>

using namespace std;

typedef long double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

const int L = 10;
int cnt[11]; LL k;
string s = "codeforces";

bool good(){
	LL ans = 1;
	for(int i = 0; i < L; ++i)
		ans = ans * cnt[i];
	return ans >= k;
}

int main(){
	scanf("%lld", &k);
	
	for(int i = 0; i < L; ++i)
		cnt[i] = 1;
	
	while(!good()){
		int id = 0;
		for(int i = 1; i < L; ++i)
			if(cnt[i] < cnt[id])
				id = i;
		
		cnt[id]++;
	}
	
	for(int i = 0; i < L; ++i)
		while(cnt[i]--)
			printf("%c", s[i]);
	return 0;
}