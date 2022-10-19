#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int N;
char s[MAXN];
int pref[MAXN];
int pos[MAXN], neg[MAXN];
int good;

int main() {
	scanf("%d", &N);
	while (N--) {
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		for (int i = 1; i <= len; i++)
			pref[i] = pref[i - 1] + (s[i] == '(' ? 1 : -1);
		
		bool first = true, second = true;
		for (int i = 1; i <= len; i++) {
			first &= pref[i] >= 0;
			second &= pref[i] >= pref[len];
		}
		
		if (pref[len] > 0)
			pos[pref[len]] += first;
		else if (pref[len] < 0)	
			neg[-pref[len]] += second;
		else
			good += first;
	}
	
	int ans = good / 2;
	for (int i = 0; i < MAXN; i++)
		ans += min(pos[i], neg[i]);
	
	printf("%d\n", ans);
	
	return 0;
}