#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int N = 1e5 + 7;
const LL mx = 1e9 + 7LL;

int n;
int deg[N];

LL pot(LL a, LL b){
	if(b == 0)
		return 1LL;

	LL x = pot(a, b / 2LL);
	if(b & 1)
		return (((x * x)%mx) * a)%mx;
	return (x * x)%mx;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		deg[u] += 1, deg[v] += 1;
	}
	
	int ile = 0;
	for(int i = 1; i <= n; ++i)
		ile += deg[i] == 1;
	
	long long int res = 1LL * pot(2, n - ile) * (n - ile) + 1LL * pot(2, n - ile + 1) * ile;
	printf("%lld\n", res%mx);
	return 0;
}