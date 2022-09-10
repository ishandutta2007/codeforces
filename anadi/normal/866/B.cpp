#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

LL n, S;
LL x = 0LL;
LL cnt = 0LL;

PLL tab[N];
LL ile = 0LL;
LL res = 0LL;
LL waste = 0LL;
LL startRes = 0LL;

void check(LL pizzy){
	if(pizzy > ile || pizzy < 0)
		return;
	
	pizzy *= S;
	LL result = startRes;
	for(int i = n; i >= 1; --i){
		LL x;
		if(tab[i].st < 0)
			x = max(0LL, min(pizzy - waste, tab[i].nd));
		else
			x = min(pizzy, tab[i].nd);
		
		pizzy -= x;
		result += x * tab[i].st;
	}
	
	res = max(res, result);
}

int main(){
	scanf("%lld %lld", &n, &S);
	for(int i = 1; i <= n; ++i){
		int a, b, c;
		scanf("%d %d %d", &c, &a, &b);
		tab[i] = {b - a, c};
		res += 1LL * a * c;
		if(b > a)
			cnt += c;
		x += c;
	}
	
	startRes = res;
	ile = (x + S - 1) / S;
	sort(tab + 1, tab + n + 1);
	waste = ile * S - x;
	
	check(cnt / S);
	check(cnt / S + 1);
	check(cnt / S - 1);
	
	printf("%lld\n", res);
	return 0;
}