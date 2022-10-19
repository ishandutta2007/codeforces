#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
char s[MAXN];
int pref[MAXN];

void load() {
	scanf("%d%s", &N, s + 1);
}

bool solve() {
	for (int i = 1; i <= N; i++)
		pref[i] = pref[i - 1] + (s[i] == '(' ? 1 : -1);
	
	if (pref[N])
		return false;
	
	int mn = N + 1, mx = 0;
	for (int i = 1; i <= N; i++)
		if (pref[i] < 0) {
			mn = min(mn, i);
			mx = max(mx, i);
			if (pref[i] < -1)
				return false;
		}
	
	if (!mx)
		return true;
	
	for (int i = mx + 1; i <= N; i++)
		if (s[i] == '(')
			return true;
	
	for (int i = 1; i <= mn; i++)
		if (s[i] == ')')
			return true;
		
	return false;
}

int main() {
	load();
	puts(solve() ? "Yes" : "No");
	return 0;
}