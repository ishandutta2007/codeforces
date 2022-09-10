#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
bool leaf[N];
vector <int> G[N];

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i){
		int v;
		scanf("%d", &v);
		G[v].push_back(i);
	}
	
	for(int i = 1; i <= n; ++i)
		if(G[i].size() == 0)
			leaf[i] = true;
	
	for(int i = 1; i <= n; ++i){
		if(leaf[i])
			continue;
		
		int cur = 0;
		for(int v: G[i])
			if(leaf[v])
				++cur;

		if(cur < 3){
			puts("No");
			return 0;
		}
	}
	
	puts("Yes");
	return 0;
}