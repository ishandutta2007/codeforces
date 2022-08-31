#include<cstdio>
#include<algorithm>
using namespace std;
int a, b, c, t1, t2, t3;
int main() {
	scanf("%d%d%d%d%d%d", &a, &b, &c, &t1, &t2, &t3);
	int T1 = abs(b - a)*t1;
	int T2 = t2 * (abs(c - a) + abs(a-b)) + t3*3;
	if (T2 <= T1)puts("YES");
	else puts("NO");
}