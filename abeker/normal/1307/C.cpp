#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int N;
char s[MAXN];
int cnt[30];
ll occ[30][30];

int main() {
	scanf("%s", s);
	N = strlen(s);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 26; j++)
			occ[j][s[i] - 'a'] += cnt[j];
		cnt[s[i] - 'a']++;
	}	
	
	ll ans = *max_element(cnt, cnt + 26);
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			ans = max(ans, occ[i][j]);
	
	printf("%lld\n", ans);
	
	return 0;
}