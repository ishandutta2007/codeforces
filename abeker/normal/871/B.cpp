#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 5005;

int N;
int ask_p[MAXN], ask_b[MAXN];
int p[MAXN], b[MAXN];
int sol[MAXN];

int ask(int i, int j) {
	printf("? %d %d\n", i, j);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}

int main() {
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		ask_p[i] = ask(i, 0);
		ask_b[i] = ask(0, i);
	}
	
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			b[j] = i ^ ask_b[j];
		for (int j = 0; j < N; j++)
			p[j] = b[0] ^ ask_p[j];
		bool ok = true;
		for (int j = 0; j < N; j++)
			ok &= p[j] < N && b[j] < N && p[b[j]] == j;
		if (ok) {
			memcpy(sol, p, sizeof sol);
			cnt++;
		}
	}
	
	printf("!\n%d\n", cnt);
	for (int i = 0; i < N; i++)
		printf("%d ", sol[i]);
	puts("");
	fflush(stdout);
	
	return 0;
}