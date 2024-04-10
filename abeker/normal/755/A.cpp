#include <cstdio>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	if (N > 2) 
		printf("%d\n", N - 2);
	else 
		puts("7");
		
	return 0;
}