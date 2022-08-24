#include<cstdio>
#include<algorithm>
using namespace std;
int n;
char p[110];
int Num[220];
int main() {
	int i;
	scanf("%d", &n);
	scanf("%s", p);
	Num['a'] = Num['e'] = Num['i'] = Num['o'] = Num['u'] = Num['y'] = 1;
	while (1) {
		for (i = 0; i < n - 1; i++) {
			if (Num[p[i]] && Num[p[i + 1]])break;
		}
		int x = i;
		if (x == n - 1)break;
		for (i = x + 1; i < n; i++)p[i] = p[i + 1];
		p[n - 1] = 0;
		n--;
	}
	printf("%s\n", p);
}