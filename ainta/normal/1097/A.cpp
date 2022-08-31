#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
char p[10], q[10];
int main() {
	int i;
	scanf("%s", p);
	for (i = 0; i < 5; i++) {
		scanf("%s", q);
		if (p[0] == q[0] || p[1] == q[1]) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}