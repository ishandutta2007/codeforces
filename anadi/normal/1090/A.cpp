#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int N = 2e5 + 7;

int n;
int mx;
int sz[N];
int MX[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int m;
		scanf("%d", &m);
		for(int j = 1; j <= m; ++j){
			int a;
			scanf("%d", &a);
			MX[i] = max(MX[i], a);
		}
		
		sz[i] = m;
		mx = max(mx, MX[i]);
	}
	
	LL res = 0LL;
	for(int i = 1; i <= n; ++i)
		res += 1LL * (mx - MX[i]) * sz[i];
	printf("%lld\n", res);
	return 0;
}