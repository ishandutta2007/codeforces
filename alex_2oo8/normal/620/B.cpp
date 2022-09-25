#include<bits/stdc++.h>

using namespace std;

int f[1000001];

int main() {
	int l, r;
	scanf("%d %d", &l, &r);
	
	f[0] = 6;
	f[1] = 2;
	f[2] = 5;
	f[3] = 5;
	f[4] = 4;
	f[5] = 5;
	f[6] = 6;
	f[7] = 3;
	f[8] = 7;
	f[9] = 6;
	for (int i = 10; i <= r; i++) f[i] = f[i / 10] + f[i % 10];
	
	int sum = 0;
	for (int i = l; i <= r; i++) sum += f[i];
	
	printf("%d\n", sum);
	
	return 0;
}