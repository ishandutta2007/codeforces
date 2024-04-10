#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

LL n, x, y;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> x >> y;
	cin >> s;
	
	int cnt = 0, last = 1;
	for(auto v: s){
		if(last == 1 && v - '0' == 0)
			++cnt;
		last = v - '0';
	}
	
	if(cnt == 0){
		puts("0");
		return 0;
	}
	
	LL res = y + min(x, y) * (cnt - 1);
	printf("%lld\n", res);
	return 0;
}