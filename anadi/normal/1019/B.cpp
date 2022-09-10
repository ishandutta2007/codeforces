#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;

int ask(int v){
	printf("? %d\n", v);
	fflush(stdout);
	
	int ret;
	scanf("%d", &ret);
	return ret;
}

int main(){
	scanf("%d", &n);
	if(n%4 == 2){
		puts("! -1");
		fflush(stdout);
		return 0;
	}
	
	int m = n / 2;
	int sub = ask(1);
	int val = ask(m + 1);
	
	if(val - sub == 0){
		puts("! 1");
		fflush(stdout);
		return 0;
	}
	
	int mult = val - sub < 0 ? 1 : -1;
	int from = 2, to = m;
	
	while(from < to){
		int mid = (from + to) >> 1;
		int diff = ask(mid) - ask(mid + m);
		
		if(diff == 0){
			printf("! %d\n", mid);
			fflush(stdout);
			return 0;
		}
		
		if(diff * mult > 0)
			from = mid + 1;
		else
			to = mid - 1;
	}
	
	printf("! %d\n", from);
	fflush(stdout);
	return 0;
}