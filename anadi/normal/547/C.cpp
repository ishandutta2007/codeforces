#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 5e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 7LL;

int n, q;
int val[N];
int cnt[N];

bool is[N];
vector <int> dv[N];

void add(int v, int d){
	int m = dv[v].size();
	for(int i = 0; i < (1 << m); ++i){
		int rt = 1;
		for(int j = 0; j < m; ++j)
			if(i & (1 << j))
				rt *= dv[v][j];
		
		cnt[rt] += d;
	}
}

int get(int v){
	int m = dv[v].size(), ret = 0;
	for(int i = 0; i < (1 << m); ++i){
		int rt = 1;
		for(int j = 0; j < m; ++j)
			if(i & (1 << j))
				rt *= dv[v][j];
		
		if(__builtin_popcount(i) & 1)
			ret -= cnt[rt];
		else
			ret += cnt[rt];
	}
	
	return ret;
}

int main(){
	for(int i = 2; i < N; ++i)
		if(dv[i].size() == 0)
			for(int j = i; j < N; j += i)
				dv[j].push_back(i);
	
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &val[i]);
	
	LL res = 0LL;
	while(q--){
		int x;
		scanf("%d", &x);
		
		if(!is[x]){
			res += get(val[x]);
			add(val[x], 1);
		}
		else{
			add(val[x], -1);
			res -= get(val[x]);
		}

		is[x] ^= 1;
		printf("%lld\n", res);
	}

	return 0;
}