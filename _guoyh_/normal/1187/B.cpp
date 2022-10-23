# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
int n, m;
char s0[MAXN], s1[MAXN];
int p[26][MAXN];
int cnt0[26], cnt1[26];
int main(){
	scanf("%d", &n);
	scanf("%s", s0 + 1);
	for (int i = 1; i <= n; i++){
		p[s0[i] - 'a'][++cnt0[s0[i] - 'a']] = i;
		// printf("%d %d %d\n", s0[i] - 'a', cnt0[s0[i] - 'a'], i);
	}
	scanf("%d", &m);
	while (m--){
		scanf("%s", s1 + 1);
		int sz = strlen(s1 + 1);
		int ans = 0;
		for (int i = 1; i <= sz; i++) cnt1[s1[i] - 'a']++;
		for (int i = 0; i < 26; i++) ans = max(ans, p[i][cnt1[i]]);
		printf("%d\n", ans);
		for (int i = 1; i <= sz; i++) cnt1[s1[i] - 'a']--;
	}
	return 0;
}