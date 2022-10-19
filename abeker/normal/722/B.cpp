#include <cstdio>
using namespace std;

const int MAXN = 105;

int N;
int p[MAXN];

bool check(char c) {
	for (int i = 0; i < 6; i++)
		if ("aeiouy"[i] == c)
			return true;
	return false;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d ", p + i);
	
	bool ok = true;
	for (int i = 0; i < N; i++) {
		char buff[MAXN];
		gets(buff);
		int cnt = 0;
		for (int j = 0; buff[j]; j++)
			cnt += check(buff[j]);
		ok &= cnt == p[i];
	}
	
	puts(ok ? "YES" : "NO");
	
	return 0;
}