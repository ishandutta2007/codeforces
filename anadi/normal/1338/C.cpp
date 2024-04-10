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

const int d[2][4] = {{0, 2, 3, 1}, {0, 3, 1, 2}};
/*
bool is[N];

void prepro(int n){
	int it = 1;
	vector <int> ans;

	while((int)ans.size() < n){
		while(is[it])
			++it;
		
		int v;
		for(v = it + 1; true; ++v)
			if(!is[v] && !is[v ^ it])
				break;
		
		is[it] = is[v] = is[v ^ it] = true;
		ans.push_back(it);
		ans.push_back(v);
		ans.push_back(v ^ it);
	}
	
	for(int i = 15; i < n; ++i){
		printf("%d%d ", ans[i] >> 1 & 1, ans[i] >> 0 & 1);
	}

	puts("");
}
*/

LL get(LL a){
	LL t = 1;
	while(t * 4 <= a)
		t *= 4;
	
	a -= t - 1;
	return (a + 2) / 3 + t - 1;
}

LL solve(int r, LL a){
	if(r == -1)
		return a;
	
	LL ans = 0;
	for(int i = 0; i < 30; ++i){
		LL tmp = a;
		if(i)
			tmp >>= i + i;
		
		LL add = d[r][tmp & 3];
		if(i)
			add <<= i + i;
		ans += add;
	}
	
	return ans;
}

int main(){
/*	int n;
	scanf("%d", &n);
	prepro(n);*/
	
	int cases;
	scanf("%d", &cases);
	
	while(cases--){
		LL n;
		scanf("%lld", &n);
		printf("%lld\n", solve((n - 1) % 3 - 1, get(n - (n - 1) % 3)));
	}

	return 0;
}