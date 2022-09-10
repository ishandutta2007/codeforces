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

int MA = 4524, MB = 24;

int ask(int a, int b){
	printf("? %d %d\n", a, b);
	fflush(stdout);
	
	int ret = (MA ^ a) - (MB ^ b);
//	if(ret > 0)
//		return 1;
//	else
//		return ret == 0 ? 0 : -1;
	scanf("%d", &ret);
	return ret;
}

void write(int a, int b){
	printf("! %d %d\n", a, b);
	fflush(stdout);
	exit(0);
}

int main(){
	int t = ask(0, 0);
	int ans[2] = {0, 0};

	for(int i = 29; i >= 0; --i){
		int t2 = ask(ans[0] ^ (1 << i), ans[1] ^ (1 << i));
		if(t2 != t){
			if(t == -1)
				ans[1] ^= 1 << i;
			else
				ans[0] ^= 1 << i;

			t = ask(ans[0], ans[1]);
			if(t == 0)
				break;
		}
	}
	
	for(int i = 29; i >= 0; --i){
		if((ans[0] & (1 << i)) || (ans[1] & (1 << i)))
			continue;

		if(ask(ans[0] ^ (1 << i), ans[1]) == -1){
			ans[0] ^= 1 << i;
			ans[1] ^= 1 << i;
		}
	}
	
	write(ans[0], ans[1]);
	return 0;
}