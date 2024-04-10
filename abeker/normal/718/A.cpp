#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

int N, T;
char s[MAXN];
int len[MAXN];
char last[MAXN];

void load() {
	scanf("%d%d%s", &N, &T, s);
}

void solve() {
	int pos = 0;
	for (int i = 0; i < N; i++)
		if (s[i] == '.') pos = i;
	
	last[N] = '0';
	for (int i = N - 1; i >= 0; i--) {
		len[i] = (len[i + 1] + 1) * (s[i] == '4');
		last[i] = s[i] == '4' ? last[i + 1] : s[i];
	}
	
	int res = N;
	for (int i = pos + 1; i < N; i++) {
		if (s[i] >= '5') 
			res = min(res, i - 1);
		if (len[i] && last[i] >= '5' && len[i] < T)
			res = min(res, i - 1);
	}
	
	if (res == N) {
		s[N] = '\0';
		puts(s);
		return;
	}
	
	for (; res >= 0; res--) {
		if (res == pos) continue;
		if (s[res] != '9') {
			s[res]++;
			for (int i = 0; i <= res; i++)
				printf("%c", s[i]);
			for (int i = res + 1; i < pos; i++)
				printf("0");
			puts("");
			return;
		}
	}
	
	printf("1");
	for (int i = 0; i < pos; i++)
		printf("0");
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}