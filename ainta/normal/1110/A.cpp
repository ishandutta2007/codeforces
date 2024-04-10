#include<cstdio>
#include<algorithm>
using namespace std;
int B, n, i, w[101000];
int main() {
	int i;
	
	scanf("%d%d",&B, &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	reverse(w, w + n);
	B %= 2;
	int t = 1, res = 0;
	for (i = 0; i < n; i++) {
		res = (res + t*w[i]) % 2;
		t *= B;
	}
	if (!res)puts("even");
	else puts("odd");
}