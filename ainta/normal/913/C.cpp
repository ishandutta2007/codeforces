#include<cstdio>
#include<algorithm>
using namespace std;
int n, L;
long long w[32], a, res = 1e18, s;
int main() {
	int i;
	scanf("%d%d", &n,&L);
	for (i = 0; i < 31; i++) {
		if(i<n)scanf("%lld", &a);
		if(!i)w[i] = a;
		else if (i >= n)w[i] = w[i - 1] * 2;
		else w[i] = min(a, w[i - 1] * 2);
	}
	for (i = 30; i >= 0; i--) {
		if (L > (1 << i)) {
			L -= (1 << i);
			s += w[i];
		}
		else {
			res = min(res, s + w[i]);
		}
	}
	printf("%lld\n", res);
}