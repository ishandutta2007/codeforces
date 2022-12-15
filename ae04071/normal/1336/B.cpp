#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;

int n[3], arr[3][100001];

long long get(int a,int b) {
	return 1ll*(a-b)*(a-b);
}
long long solve(int a,int b,int c) {
	return get(a,b) + get(b,c) + get(c,a);
}
long long f(int a,int b,int c) {
	long long ans = 4000000000000000000ll;
	for(int i=0;i<n[a];i++) {
		int j=lower_bound(arr[b],arr[b]+n[b],arr[a][i])-arr[b];
		int k=lower_bound(arr[c],arr[c]+n[c],arr[a][i])-arr[c];
		
		if(j<n[b] && k<n[c]) ans = min(ans, solve(arr[a][i], arr[b][j], arr[c][k]));
		if(j && k<n[c]) ans = min(ans, solve(arr[a][i], arr[b][j-1], arr[c][k]));
		if(j<n[b] && k) ans = min(ans, solve(arr[a][i], arr[b][j], arr[c][k-1]));
		if(j && k) ans = min(ans, solve(arr[a][i], arr[b][j-1], arr[c][k-1]));
	}
	return ans;
}
int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		for(int i=0;i<3;i++) scanf("%d",n+i);
		for(int i=0;i<3;i++) for(int j=0;j<n[i];j++) scanf("%d",&arr[i][j]);

		for(int i=0;i<3;i++) sort(arr[i], arr[i]+n[i]);

		printf("%lld\n", min({f(0,1,2), f(1,0,2), f(2,0,1)}));
	}
	return 0;
}