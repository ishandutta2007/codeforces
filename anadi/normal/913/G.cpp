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
const int INF = 1e9 + 9;

LL pot(LL a, LL b){
	LL ret = 1LL;
	while(b){
		if(b & 1)
			ret *= a;
		a *= a; b /= 2LL;
	}
	
	return ret;
}

LL RS(LL a, LL b, LL m){
	if(b == 0)
		return 0LL;
	LL x = RS(a, b / 2LL, m);

	if(b & 1)
		return (x + x + a)%m;
	return (x + x)%m;
}

LL fast(LL a, LL b, LL m){
	LL ret = 1LL;
	while(b){
		if(b & 1)
			ret = RS(ret, a, m);
		a = RS(a, a, m); b /= 2LL;
	}
	
	return ret;
}

LL findlog(LL res, LL alfa){
	LL cur = 5LL, cur2 = res%5, d = 1LL;
	for(int i = 0; true; ++i){
		if(d == cur2){
			d = i;
			break;
		}
		
		d = (d + d)%5;
	}
	
	LL fi = 4LL;
	while(--alfa){
		cur *= 5LL;
		cur2 = res%cur;

		for(int j = 0; j < 5; ++j)
			if(fast(2, d + fi * j, cur) == cur2){
				d = d + fi * j;
				break;
			}
		
		fi *= 5LL;
	}
	
	return d;
}

void solve(){
	LL a; scanf("%lld", &a);
	int n = 0; LL x = a;
	
	while(x){
		++n;
		x /= 10LL;
	}
	
	x = a * LL(1e6);
	LL cur = pot(2, n + 6);
	x = x + cur - x%cur;
	
	if(x%5 == 0)
		x += cur;
	
	LL y = (x / cur) % pot(5, n + 6);
	printf("%lld\n", findlog(y, n + 6) + n + 6);
}

int main(){
	int quest; scanf("%d", &quest);
	while(quest--)
		solve();
	return 0;
}