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

bool ask(int x, int y){
	printf("%d %d\n", x, y);
	fflush(stdout);
	
	char s[10];
	scanf("%s", s);

	if(s[0] == 'w')
		return false;
	return true;
}

int main(){
	scanf("%d", &n);
	int last = 5, nxt = 1e9 - 5;
	while(last + 1 < nxt && n > 0){
		int mid = (last + nxt) / 2;
		bool ret = ask(mid, mid);
		
		if(ret)
			nxt = mid;
		else
			last = mid;
		--n;
	}

	assert(n <= 1);
	if(n == 0){
		int x1 = (last + nxt) / 2;
		int x2 = x1 + 1;
		
		printf("%d %d %d %d\n", x1, x1 + 1, x2, x2 - 1);
		fflush(stdout);
	}
	else{
		bool t = ask(last, last + 1);
		if(t)
			printf("%d %d %d %d\n", last - 1, last + 1, nxt, nxt - 1);
		else
			printf("%d %d %d %d\n", last, last + 2, nxt, nxt - 1);
		fflush(stdout);
	}

	return 0;
}