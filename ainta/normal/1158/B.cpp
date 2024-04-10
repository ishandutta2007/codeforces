#include<cstdio>
#include<algorithm>
using namespace std;
int n, K, T;
int main() {
	int i;
	scanf("%d%d", &n, &K);
	T = (n - K)/2 + 1;
	for (i = 1; i <= n; i++) {
		printf("%d", ((i-1)%T) == T-1);
	}
}