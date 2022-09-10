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

int n, s;
int dg[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &dg[i]);
		s += dg[i];
	}
	
	if(s < 2 * n - 2){
		puts("NO");
		exit(0);
	}
	
	vector <int> t[2];
	for(int i = 1; i <= n; ++i)
		if(dg[i] > 1)
			t[0].push_back(i);
		else
			t[1].push_back(i);
	
	if(t[1].size() <= 2){
		while(t[1].size() < 2){
			t[1].push_back(t[0].back());
			t[0].pop_back();
		}
		
		printf("YES %d\n", n - 1);
		printf("%d\n", n - 1);
		printf("%d %d\n", t[1][0], t[0][0]);

		for(int i = 1; i < t[0].size(); ++i)
			printf("%d %d\n", t[0][i - 1], t[0][i]);

		printf("%d %d\n", t[0].back(), t[1][1]);
		return 0;
	}
	
	printf("YES %d\n", t[0].size() + 1);
	printf("%d\n", n - 1);
	
	for(int i = 1; i < t[0].size(); ++i)
		printf("%d %d\n", t[0][i - 1], t[0][i]);
	
	printf("%d %d\n", t[1].back(), t[0][0]);
	t[1].pop_back();
	
	printf("%d %d\n", t[0].back(), t[1].back());
	t[1].pop_back();
	
	for(auto v: t[0])
		dg[v] -= 2;
	
	for(auto v: t[1]){
		for(auto u: t[0]){
			if(dg[u] == 0)
				continue;
			
			dg[u] -= 1;
			printf("%d %d\n", v, u);
			break;
		}
	}

	return 0;
}