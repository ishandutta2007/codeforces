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

int n;
int in[N];
vector <int> cnt[N];

void solve(int p){
	printf("%d ", in[p]);
	for(int i = 1; i <= n; ++i)
		if(i != p)
			printf("%d ", in[i]);
	puts("");
	exit(0);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		for(int j = 0; j < 30; ++j)
			if(in[i] & (1 << j))
				cnt[j].push_back(i);
	}
	
	for(int i = 29; i >= 0; --i)
		if(cnt[i].size() == 1)
			solve(cnt[i].back());
	solve(1);
	return 0;
}