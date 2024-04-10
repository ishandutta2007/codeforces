#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const int INF = 0x3f3f3f3f;

int N;
char s[MAXN];
int pref[MAXN], cnt[MAXN];

int main() {
	scanf("%s", s + 1);
	N = strlen(s + 1);
	
	for (int i = 1; i <= N; i++) {
		pref[i] = pref[i - 1];
		cnt[i] = cnt[i - 1];
		if (s[i] == '(')
			pref[i]++;
		else if (s[i] == ')')
			pref[i]--;
		else
			cnt[i]++;
	}
	
	int sol = 0;
	for (int i = 1; i <= N; i++) {
		int mini1 = INF, mini2 = INF;
		for (int j = i; j <= N; j++) {
			mini1 = min(mini1, pref[j] + cnt[j]);
			mini2 = min(mini2, pref[j - 1] - cnt[j - 1]);
			sol += (j - i) % 2 && mini1 >= pref[i - 1] + cnt[i - 1] && mini2 >= pref[j] - cnt[j]; 
		}
	}
	
	printf("%d\n", sol);
	
	return 0;
}