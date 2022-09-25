#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	int a = 0, b = 0, c = 0, k = 0;
	while (max(n - a, 0) + max(m - b, 0) > c) {
		k++;
		
		if (k % 6 == 0) c++;
		else if (k % 2 == 0) a++;
		else if (k % 3 == 0) b++;
	}
	
	printf("%d\n", k);
	
	return 0;
}