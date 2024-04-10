#include<bits/stdc++.h>

using namespace std;

int a[100];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	
	sort(a, a + n);
	
	int i = n - 1;
	while (i >= 0 && m > 0) m -= a[i--];
	
	if (m > 0) printf("-1\n");
	else printf("%d\n", n - i - 1);
	
	return 0;
}