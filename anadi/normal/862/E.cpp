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

int n, m, q;
LL a[N], b[N];

LL suf[N];
LL curAdd;
set <LL> S;

LL answer(){
	auto x = S.lower_bound(-curAdd);
	LL ret = 1LL * INF * INF;
	if(x != S.end())
		ret = min(ret, abs((*x) + curAdd));
	if(x != S.begin()){
		--x;
		ret = min(ret, abs((*x) + curAdd));
	}
	
	return ret;
}

int main(){
	scanf("%d %d %d", &n, &m, &q);

	LL s = 0LL;
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &a[i]);
		s += (i & 1) ? a[i] : -a[i];
	}
	
	for(int i = 1; i <= m; ++i)
		scanf("%lld", &b[i]);
	
	for(int i = m; i >= 1; --i)
		suf[i] = b[i] - suf[i + 1];
	
	for(int j = 0; j <= m - n; ++j)
		S.insert(s - suf[j + 1] - suf[j + n + 1] * ((n & 1) ? 1 : -1));
	
	printf("%lld\n", answer());
	while(q--){
		LL l, r, x;
		scanf("%lld %lld %lld", &l, &r, &x);
		l %= 2; r %= 2;
		
		curAdd += (l + r - 1) * x;
		printf("%lld\n", answer());
	}

	return 0;
}