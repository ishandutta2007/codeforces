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
set <int> ids[N];

void transfer(int v, int p){
	int o = in[v] | in[p];
	int a = in[v] & in[p];
	
	for(int i = 0; i < 20; ++i)
		if((a >> i & 1) != (in[p] >> i & 1))
			ids[i].erase(p);
	
	in[p] = a;
	in[v] = o;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	sort(in + 1, in + n + 1);
	
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < 20; ++j)
			if(in[i] >> j & 1)
				ids[j].insert(i);
	
	long long ans = 0;
	for(int i = n; i >= 1; --i){
		int cur = in[i];
		for(int j = 0; j < 20; ++j)
			if(cur >> j & 1)
				ids[j].erase(i);
		
		for(int j = 0; j < 20; ++j)
			if(cur >> j & 1)
				continue;
			else if(ids[j].size()){
				auto p = *ids[j].begin();
				cur |= in[p];
				transfer(i, p);
			}

		ans += 1LL * cur * cur;
	}
	
	printf("%lld\n", ans);
	return 0;
}