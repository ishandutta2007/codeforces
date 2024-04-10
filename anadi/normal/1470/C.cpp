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

int n, k;

int ask(int x) {
	if(x > n)
		x -= n;
	if(x < 1)
		x += n;
	
	printf("? %d\n", x);
	fflush(stdout);
	
	int a;
	scanf("%d", &a);
	return a;
}

void answer(int x) {
	printf("! %d\n", x);
	fflush(stdout);
	exit(0);
}

int main() {
	scanf("%d %d", &n, &k);
	ask(1);

	if(n <= 30) {
		for(int i = 1; i <= 2 * n; ++i)
			ask(i);

		for(int i = 1; i <= n; ++i)
			if(ask(i) == k and ask(i - 1) < k and ask(i + 1) > k)
				answer(i);
	}	
	
	int checked = 0;
	int from = -1, to = -1;
	for(int i = 1; true; ++i) {
		int r = checked + i;
		if(r > n)
			r = n;
		
		int v = ask(r + 1);
		if(v == k) {
			checked = r;
			continue;
		}
		
		if(v > k)
			from = checked + 1, to = r;
		else
			from = r + 2, to = r + i + 1;
		break;
	}
	
	assert(from != -1 and to != -1);
	for(int i = from; i <= to; ++i)
		if(ask(i) == k) {
			answer(i);
			break;
		}
	
	assert(false);
	return 0;
}