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
const int inf = 1e9 + 9;

int cnt = 0;
inline PII ask(int nr){
	++cnt;
	assert(cnt <= 1999);
	printf("? %d\n", nr);
	fflush(stdout);

	PII ret;
	scanf("%d %d", &ret.st, &ret.nd);
	return ret;
}

inline int los(){
	return rand() * (1 << 15) + rand();
}

int n, start, x;

int main(){
	srand(69 * 69 - 42 + 198);

	scanf("%d %d %d", &n, &start, &x);
	PII res = ask(start);
	if(res.st >= x){
		printf("! %d\n", res.st);
		return 0;
	}

	for(int i = 1; i <= 500; ++i){
		int v = los()%n + 1;
		PII cur = ask(v);
		if(cur.st <= x && cur.st > res.st)
			res = cur;
	}
	
	while(res.st < x && res.nd != -1)
		res = ask(res.nd);

	if(res.st < x)
		puts("! -1");
	else
		printf("! %d\n", res.st);
	return 0;
}