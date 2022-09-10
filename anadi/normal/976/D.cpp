#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1007;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int deg[N];
vector <PII> res;

int main(){
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &deg[i]);
	n = deg[m] + 1;
	
	int wsk = 1;
	while(n){
		for(int i = 1; i < n; ++i)
			res.pb({i, n});
		for(int i = wsk; i <= m; ++i)
			deg[i]--;
		
		if(deg[wsk] == 0){
			--m;
			if(wsk > m)
				n = 0;
			else
				n = deg[m] + 1;
			++wsk;
		}
		else
			--n;
	}
	
	printf("%d\n", int(res.size()));
	for(auto v: res)
		printf("%d %d\n", v.st, v.nd);
	return 0;
}