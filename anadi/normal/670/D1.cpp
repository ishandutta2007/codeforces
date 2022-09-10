#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int mxn = 1e5 + 7;
const LL INF = 1e9 + 7LL;
const LL MX = 2e9;

int n;
LL k;
LL a[mxn];
LL b[mxn];

bool ok(LL val){
	LL x = 0LL;
	for(int i = 1; i <= n; ++i){
		LL K = val * a[i];
		x += max(K - b[i], 0LL);
		if(x > k)
			return false;
	}
	
	return true;
}

LL BS(){
	LL pocz = 0LL, kon = MX;
	while(pocz < kon){
		LL mid = (pocz + kon + 1LL)/2LL;
		if(ok(mid))
			pocz = mid;
		else
			kon = mid - 1;
	}
	
	return pocz;
}

int main(){
	scanf("%d %I64d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%I64d", &a[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%I64d", &b[i]);
	printf("%I64d\n", BS());
	return 0;
}