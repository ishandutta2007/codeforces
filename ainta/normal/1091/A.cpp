#include<cstdio>
#include<algorithm>
using namespace std;
int A, B, C;
int main() {
	scanf("%d%d%d", &A, &B, &C);
	printf("%d\n", min(min(A - 1, B - 2), C - 3) * 3 + 6);
}