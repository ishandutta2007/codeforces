#include <bits/stdc++.h>
using namespace std;

int N;
int a[15];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	
	printf("%d\n", 2 + (a[2] ^ *min_element(a, a + N)));
	
	return 0;
}