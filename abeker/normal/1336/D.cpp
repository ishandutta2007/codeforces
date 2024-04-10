#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e2 + 5;

int N;
int a[MAXN];
int inverse[MAXN * MAXN];
int triplets, straights;
pii delta;

void get_info() {
	int t, s;
	scanf("%d%d", &t, &s);
	delta = {t - triplets, s - straights};
	triplets = t;
	straights = s;
}

void ask(int x) {
	printf("+ %d\n", x);
	fflush(stdout);
	get_info(); 
	a[x]++;
}

int main() {
	scanf("%d", &N);
	get_info();
	
	for (int i = 1; i <= N + 1; i++)
		inverse[i * (i - 1) / 2] = i;
		
	ask(2);
	ask(1);
	int product = delta.second;
	ask(3);
	int up = delta.second;
	ask(1);
	a[1] += inverse[delta.first] - 1;
	a[2] = delta.second - product;
	a[3] = delta.second / a[2];
	up -= (a[1] - 1) * a[2];
	bool nonzero = up;
	for (int i = 4; i <= N - 1; i++) {
		ask(i);
		a[i] += delta.first ? inverse[delta.first] : nonzero;
		nonzero = delta.second - a[i - 1] * a[i - 2];
	}
	
	for (int i = 1; i <= N - 3; i++)
		straights -= a[i] * a[i + 1] * a[i + 2];
	a[N] = straights / (a[N - 1] * a[N - 2]);
	
	printf("!");
	for (int i = 1; i <= N; i++)
		printf(" %d", a[i] - (i < N) - (i == 1));
	puts("");
	fflush(stdout);
	
	return 0;
}