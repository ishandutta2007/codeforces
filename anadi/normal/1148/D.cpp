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
vector <PII> ord[2];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		
		if(a < b)
			ord[0].push_back({b, i});
		else
			ord[1].push_back({a, i});
	}
	
	sort(ord[0].begin(), ord[0].end());
	sort(ord[1].begin(), ord[1].end());
	
	if(ord[0].size() < ord[1].size()){
		printf("%d\n", (int)ord[1].size());
		for(auto v: ord[1])
			printf("%d ", v.nd);
		puts("");
	}
	else{
		printf("%d\n", (int)ord[0].size());
		reverse(ord[0].begin(), ord[0].end());

		for(auto v: ord[0])
			printf("%d ", v.nd);
	}

	return 0;
}