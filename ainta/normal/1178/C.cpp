#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, Mod = 998244353, res=1;
int main() {
	int i;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n + m; i++) {
		res = res * 2 % Mod;
	}
	printf("%d\n", res);
}