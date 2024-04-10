#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

int n, k;

bool check(int a, int b){
	string s;
	printf("1 %d %d\n", a, b);
	fflush(stdout);
	cin >> s;
	if(s == "TAK")
		return true;
	return false;
}

int solve(int p, int k){
	while(p < k){
		int m = (p + k) / 2;
		if(check(m, m + 1))
			k = m;
		else
			p = m + 1;
	}
	
	if(p > k)
		return 1;
	return p;
}

int main(){
	scanf("%d %d", &n, &k);
	if(n == 2){
		printf("%d %d %d\n", 2, 1, 2);
		fflush(stdout);
		return 0;
	}

	int x = solve(1, n);
	int y = solve(1, x - 1);
	int z = solve(x + 1, n);
	
	if(x == 1){
		printf("2 %d %d\n", x, z);
		fflush(stdout);
		return 0;
	}
	
	if(x == n){
		printf("2 %d %d\n", x, y);
		fflush(stdout);
		return 0;
	}
	
	if(!check(y, z))
		y = z;
	printf("2 %d %d\n", x, y);
	fflush(stdout);
	return 0;
}