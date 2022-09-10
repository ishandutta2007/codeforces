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

int n, m;
bool correct[N];

int ask(int x){
	printf("%d\n", x);
	fflush(stdout);

	int ret;
	scanf("%d", &ret);
	
	if(ret == 0)
		exit(0);
	return ret;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int t = ask(1);
		if(t == 1)
			correct[i] = true;
	}
	
	int cnt = 0;
	int p = 2, k = n;
	while(true){
		int mid = (p + k) >> 1;
		int t = ask(mid);
		++cnt;
		if(cnt > m)
			cnt -= m;

		if(!correct[cnt])
			t *= -1;

		if(t == 1)
			p = mid + 1;
		else
			k = mid - 1;
	}
	
	return 0;
}