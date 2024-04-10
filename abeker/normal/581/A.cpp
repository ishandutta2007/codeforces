#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d %d\n", min(a, b), (max(a, b) - min(a, b)) / 2);
	return 0;
}