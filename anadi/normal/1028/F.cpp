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

int q;
int cnt;
set <PLL> S[N];
map <LL, int> M;
map <PII, int> sub;

void add(int t, PLL a, int val){
	LL d = __gcd(a.st, a.nd);
	sub[{a.st / d, a.nd / d}] += val;
	
	if(val < 0)
		S[t].erase(a);
	
	for(auto v: S[t]){
		LL d2 = __gcd(v.st + a.st, v.nd + a.nd);
		sub[{(v.st + a.st) / d2, (v.nd + a.nd) / d2}] += 2 * val;
	}
	
	if(val > 0)
		S[t].insert(a);
}

int main(){
	scanf("%d", &q);
	int cur = 0;
	while(q--){
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		if(t == 1){
			++cur;
			if(!M.count(1LL * x * x + 1LL * y * y))
				M[1LL * x * x + 1LL * y * y] = ++cnt;
			add(M[1LL * x * x + 1LL * y * y], {x, y}, 1);
		}
		else if(t == 2){
			add(M[1LL * x * x + 1LL * y * y], {x, y}, -1);
			--cur;
		}
		else{
			int d = __gcd(x, y);
			x /= d, y /= d;
			
			if(!sub.count({x, y})){
				printf("%d\n", cur);
				continue;
			}
			
			printf("%d\n", cur - sub[{x, y}]);
		}
	}

	return 0;
}