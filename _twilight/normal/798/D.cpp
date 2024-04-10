#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

typedef class Pair3 {
	public:
		int x, y, z;
} Pair3;

int n;
Pair3 a[N];
boolean vis1[N], vis2[N];

int main() {
	scanf("%d", &n);
	printf("%d\n", (n >> 1) + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i].x);	
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i].y);
	for (int i = 1; i <= n; i++)
		a[i].z = i;
	int r = (n & 1), s = 2;
	sort(a + 1, a + n + 1, [&] (Pair3 x, Pair3 y) {	return x.x > y.x;	});
	if (r) {
		printf("%d ", a[1].z);
	} else {
		printf("%d %d ", a[1].z, a[2].z);
		s = 3;
	}
	for (int i = s; i <= n; i += 2) {
		if (a[i].y > a[i + 1].y) {
			printf("%d ", a[i].z);
		} else {
			printf("%d ", a[i + 1].z);
		}
	}	
	return 0;
}