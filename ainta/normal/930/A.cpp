#include<cstdio>
#include<algorithm>
using namespace std;
int Dep[101000], C[101000], n, p[101000], res;
int main() {
	int i;
	scanf("%d", &n);
	C[0]++;
	for (i = 2; i <= n; i++) {
		scanf("%d", &p[i]);
		Dep[i] = Dep[p[i]] + 1;
		C[Dep[i]]++;
	}
	for (i = 0; i < n; i++) {
		res += C[i] % 2;
	}
	printf("%d\n", res);
}