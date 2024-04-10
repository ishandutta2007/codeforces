#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const string outcome[] = {"tokitsukaze", "quailty", "once again"};

int N, K;
char s[MAXN];
int mini[2], maks[2];

void load() {
	scanf("%d%d%s", &N, &K, s);
}

int solve() {
	for (int i = 0; i < 2; i++) {
		mini[i] = N;
		maks[i] = -1;
	}
	
	for (int i = 0; i < N; i++) {
		int bit = s[i] - '0';
		mini[bit] = min(mini[bit], i);
		maks[bit] = max(maks[bit], i);
	}
	
	bool sec = true;
	for (int i = 0; i < 2; i++) {
		int span = maks[i] - mini[i];
		if (span < K)
			return 0;
		sec &= span == K;
	}
	
	if (sec && N < 2 * (K + 1))
		return 1;
	
	return 2;
}

int main() {
	load();
	puts(outcome[solve()].c_str());
	return 0;
}