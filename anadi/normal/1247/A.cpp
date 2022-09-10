#include <bits/stdc++.h>

using namespace std;

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	
	if(x == y){
		printf("%d0 %d1\n", x, y);
		exit(0);
	}
	
	if(x == 9 && y == 1){
		puts("9 10");
		exit(0);
	}
	
	if(y == x + 1)
		printf("%d9 %d0\n", x, y);
	else
		puts("-1");
	return 0;
}