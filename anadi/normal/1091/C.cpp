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
set <int> dv;
set <LL> res;

int main(){
	scanf("%d", &n);
	for(int i = 1; i * i <= n; ++i)
		if(n%i == 0){
			dv.insert(i);
			dv.insert(n / i);
		}
	
	for(auto v: dv){
		LL cur = n / v;
		cur = cur * (cur - 1) / 2;
		cur *= v;
		cur += n / v;
		res.insert(cur);
	}

	for(auto v: res)
		printf("%lld ", v);
	return 0;
}