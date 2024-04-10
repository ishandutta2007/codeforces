#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
using namespace std;

const int MAXN = 50005;

int N, S, X;
int val[MAXN], nxt[MAXN];

void load() {
	scanf("%d%d%d", &N, &S, &X);
}

void ask(int id) {
	printf("? %d\n", id);
	fflush(stdout);
	scanf("%d%d", val + id, nxt + id);
}

void finish(int ans) {
	printf("! %d\n", ans);
	fflush(stdout);
	exit(0);
}

void solve() {
	srand(time(0) * getpid());
	
	ask(S);
	if (val[S] >= X)
		finish(val[S]);
		
	long long seed = 0;
	for (int i = 0; i < 999; i++) {
		seed = (seed * 1000003 + 10007) % 1000000007;
		int pos = seed % N + 1;
		ask(pos);
		if (val[pos] <= X && val[pos] > val[S])
			S = pos;
	}
	
	for (int i = 0; i < 999; i++) {
		if (S == -1)
			break;
		ask(S);
		if (val[S] >= X)
			finish(val[S]);
		S = nxt[S];
	}
	
	finish(-1);
}

int main() {
	load();
	solve();
	return 0;
}