#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;
const LL bigInf = 1LL * inf * inf;

int n;
LL x, y, z;
LL res = bigInf;
LL pref[2 * N], supPref[2 * N];

LL add1(LL p, LL k){
	LL cnt = pref[k] - pref[p - 1];
	return (k * cnt - (supPref[k] - supPref[p - 1])) * x;
}

LL add2(LL p, LL k){
	return (pref[k] - pref[p - 1]) * y;
}

LL add(LL p, LL k){
	if(k - p < z)
		return add1(p, k);
	return add1(k - z + 1, k) + add2(p, k - z);
}

int main(){
	scanf("%d %lld %lld", &n, &y, &x);
	z = (y + x - 1) / x;
	
	for(int i = 1; i <= n; ++i){
		LL a;
		scanf("%lld", &a);
		pref[a] += 1LL;
		supPref[a] += a;
	}
	
	for(int i = 1; i < 2 * N; ++i)
		pref[i] += pref[i - 1],
		supPref[i] += supPref[i - 1];
	
	res = n * y;
	for(int i = 2; i < N; ++i){
		LL cur = 0LL;
		for(int j = 0; j < N; j += i)
			cur += add(j + 1, j + i);
		res = min(res, cur);
	}
	
	printf("%lld\n", res);
	return 0;
}