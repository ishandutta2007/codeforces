#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[101000];
int P[101000], T[101000], s;
int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &w[i]);
		T[i] = w[i] / 2;
		if (abs(w[i]) % 2) {
			if (w[i] < 0)T[i] = -((-w[i] + 1) / 2);
			else T[i] = w[i] / 2;
			P[i] = 1;
		}
		s += T[i];
	}
	for (i = 0; i < n; i++) {
		if (s < 0 && P[i]) {
			T[i]++;
			s++;
		}
		printf("%d\n", T[i]);
	}
}