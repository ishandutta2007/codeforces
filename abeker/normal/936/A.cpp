#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main() {
	ld K, D, T;
	scanf("%Lf%Lf%Lf", &K, &D, &T);

	ld rem = D * ceil(K / D) - K;
	 
	ld c = floor(2 * T / (2 * K + rem));
	
	ld rest = 1 - c * (K / T + rem / (2 * T));
	
	ld sol = c * D * ceil(K / D);
	
	if (rest <= K / T)
		sol += rest * T;
	else
		sol += K + (rest - K / T) * 2 * T;
	
	printf("%.20Lf\n", sol);
				
	return 0;
}