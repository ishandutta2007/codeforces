#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[1010000], BIT[1010000];
void Add(int a, int b) {
	while (a <= n) {
		BIT[a] += b;
		a += (a&-a);
	}
}
int Sum(int a) {
	int r = 0;
	while (a) {
		r += BIT[a];
		a -= (a&-a);
	}
	return r;
}
int main() {
	int i;
	long long r = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		r += Sum(n) - Sum(w[i]);
		Add(w[i], 1);
	}
	if (((r & 1) != 0) == (n % 2 == 1) ){
		puts("Petr");
	}
	else puts("Um_nik");
}