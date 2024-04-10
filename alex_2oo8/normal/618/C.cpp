#include<bits/stdc++.h>

using namespace std;

int x[4], y[4], p[3];

int cross_product(int a, int b, int c) {
	long long cp = (x[b] - x[a]) * 1ll * (y[c] - y[a]) - (y[b] - y[a]) * 1ll * (x[c] - x[a]);
	
	if (cp < 0) return -1;
	if (cp > 0) return 1;
	return 0;
}

bool inside(int a, int b, int c) {
	if (cross_product(a, b, c) != 0) return false;
	
	return 	min(x[a], x[b]) <= x[c] && x[c] <= max(x[a], x[b]) &&
			min(y[a], y[b]) <= y[c] && y[c] <= max(y[a], y[b]);
}

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < 2; i++) {
		scanf("%d %d", x + i, y + i);
		p[i] = i;
	}
	
	int i = 2;
	while (true) {
		scanf("%d %d", x + 2, y + 2);
		
		if (cross_product(0, 1, 2) != 0) {
			p[2] = i++;
			
			break;
		}
		
		if (inside(0, 1, 2)) {
			x[0] = x[2];
			y[0] = y[2];
			p[0] = i;
		}
		
		i++;
	}
	
	for (; i < n; i++) {
		scanf("%d %d", x + 3, y + 3);
		
		if (inside(0, 1, 3) || inside(0, 2, 3)) {
			x[0] = x[3];
			y[0] = y[3];
			p[0] = i;
		}
		else if (inside(1, 2, 3)) {
			x[1] = x[3];
			y[1] = y[3];
			p[1] = i;
		}
		else if (cross_product(3, 0, 1) == cross_product(3, 1, 2) && cross_product(3, 1, 2) == cross_product(3, 2, 0)) {
			x[1] = x[3];
			y[1] = y[3];
			p[1] = i;
		}
	}
	
	printf("%d %d %d\n", p[0] + 1, p[1] + 1, p[2] + 1);
	
	return 0;
}