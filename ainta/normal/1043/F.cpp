#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
int n, w[301000], chk[301000];
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int Rand() {
	return (rand() * 10000 + rand()) % n + 1;
}
int vis[301000], U[10];
bool OK(int a) {
	int i, j;
	for (i = 0; i < 1000000*5/a; i++) {
		int t = 0;
		for (j = 0; j < a; j++) {
			int x = Rand();
			if(vis[x]){
				j--;
				continue;
			}
			t = gcd(t, w[x]);
			U[j] = x;
			vis[x] = 1;
		}
		if (t == 1)return true;
		for (j = 0; j < a; j++)vis[U[j]] = 0;
	}
	return false;
}
int main() {
	srand((unsigned)time(NULL));
	int i, a, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		chk[a]|=1;
		for (j = a + a; j <= 300000; j += a)chk[j] = 2;
	}
	int c = 0;
	for (i = 1; i <= 300000; i++) {
		if (chk[i] == 1)w[++c] = i;
	}
	n = c;
	if (chk[1]) {
		printf("1\n");
		return 0;
	}
	int t = 0;
	for (i = 1; i <= n; i++)t = gcd(t, w[i]);
	if (t != 1) {
		puts("-1");
		return 0;
	}
	for (i = 2; i <= 6; i++) {
		if (OK(i)) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("%d\n", i);
}