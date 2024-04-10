#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", min(a - b, max(1,b)));
}