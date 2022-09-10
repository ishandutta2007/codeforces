#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int inf = 500;

int n;
deque <int> Q;

int main(){
	scanf("%d", &n);
	int cur = 0, res = 0;
	int curSpeed = 0;
	Q.push_back(inf);
	
	for(int i = 1; i <= n; ++i){
		int x, y;
		scanf("%d", &x);
		if(x == 1 || x == 3)
			scanf("%d", &y);
		
		if(x == 1){
			while(Q.back() < y)
				Q.pop_back(),
				++res;
			curSpeed = y;
		}
		
		if(x == 2 && cur > 0){
			res += cur;
			cur = 0;
		}
		
		if(x == 3){
			if(y >= curSpeed)
				Q.push_back(y);
			else
				++res;
		}

		if(x == 4)
			cur = 0;
		if(x == 5)
			Q.push_back(inf);
		if(x == 6)
			++cur;
	}
	
	printf("%d\n", res);
	return 0;
}