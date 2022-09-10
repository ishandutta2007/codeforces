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
const LL INF = 1e18 + 9LL;

int n, q;
int in[N];
int diff[N];
vector <PII> V;

LL solve(int from, int to){
	LL ret = 0LL;
	for(int i = from; i <= to; ++i){
		int cur = i;
		while(V.size()){
			if(diff[V.back().st] > diff[i])
				break;
			
			ret += 1LL * diff[V.back().st] * (i - V.back().st) * (V.back().st - V.back().nd + 1);
			cur = V.back().nd;
			V.pop_back();
		}
		
		V.push_back({i, cur});
	}
	
	++to;
	while(V.size()){
		ret += 1LL * diff[V.back().st] * (to - V.back().st) * (V.back().st - V.back().nd + 1);
		V.pop_back();
	}

	return ret;
}

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	
	for(int i = 1; i < n; ++i)
		diff[i] = abs(in[i + 1] - in[i]);
	
	while(q--){
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%lld\n", solve(l, r - 1));
	}

	return 0;
}