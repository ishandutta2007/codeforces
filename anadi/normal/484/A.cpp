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

LL l, r;
void solve(){
	scanf("%I64d %I64d", &l, &r);
	LL cur = 0, opt = 0LL;
	
	int res = 0, cnt = 0;
	bool common = true;

	for(int i = 59; i >= 0; --i){
		bool L = l & (1LL << i);
		bool R = r & (1LL << i);
		
		if(L != R)
			common = false;
		
		if(R){
			cur += 1LL << i;
			++cnt;

			if(!common)
				if(cnt + i > res + 1){
					opt = cur - 1;
					res = cnt + i - 1;
				}
		}
	}
	
	if(cnt > res)
		printf("%I64d\n", r);
	else
		printf("%I64d\n", opt);
}

int main(){
	int quest;
	scanf("%d", &quest);
	
	while(quest--)
		solve();
	return 0;
}