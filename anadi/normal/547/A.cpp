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
const LL INF = 1e18 + 7LL;

namespace go{
	int m;
	int h1, a1, x1, y1;
	int h2, a2, x2, y2;

	PII get(int h, int a, int x, int y){
		int st = h; 
		int length = 0, place = -1;
		do{
			if(h == a)
				place = length;

			h = (1LL * x * h + y)%m;
			++length;
		}while(h != st);
		
		return {length, place};
	}

	LL simulate(int cl, int cp, int cl2, int cp2){
		if(cp == cp2)
			return cp;
		
		int x = (cp + cl)%cl2, ile = 1;
		while(x != cp){
			if(x == cp2)
				return 1LL * ile * cl + cp;
			
			++ile;
			x = (x + cl)%cl2;
		}
		
		return -1;
	}

	int main(){
		scanf("%d", &m);
		scanf("%d %d %d %d", &h1, &a1, &x1, &y1);
		scanf("%d %d %d %d", &h2, &a2, &x2, &y2);
		
		LL res = 0;
		while(res < m){
			++res;
			h1 = (1LL * x1 * h1 + y1)%m;
			h2 = (1LL * x2 * h2 + y2)%m;
			
			if(h1 == a1 && h2 == a2){
				printf("%lld\n", res);
				return 0;
			}
		}
		
		PII cycle = get(h1, a1, x1, y1);
		PII cycle2 = get(h2, a2, x2, y2);
		
		if(cycle.nd == -1 || cycle2.nd == -1){
			puts("-1");
			return 0;
		}
		
		if(cycle.st > cycle2.st)
			swap(cycle, cycle2);
		
		LL ret = simulate(cycle.st, cycle.nd, cycle2.st, cycle2.nd);
		if(ret == -1)
			puts("-1");
		else
			printf("%lld\n", res + ret);
		return 0;
	}
}

int main(){
	go::main();
	return 0;
}