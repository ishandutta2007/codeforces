# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 105;
int T;
int cnt[26];
char s[MAXN], t[MAXN], p[MAXN];
bool check(){
	memset(cnt, 0, sizeof(cnt));
	int ssz = strlen(s + 1), tsz = strlen(t + 1), psz = strlen(p + 1);
	int np = 1;
	for (int i = 1; i <= ssz; i++){
		while (np <= tsz && t[np] != s[i]) cnt[t[np++] - 'a']++;
		if (np > tsz) return false;
		np++;
	}
	// printf("np %d\n", np);
	while (np <= tsz) cnt[t[np++] - 'a']++;
	for (int i = 1; i <= psz; i++){
		cnt[p[i] - 'a']--;
		// printf("cnt %d %d\n", i, cnt[p[i] - 'a']);
	}
	for (int i = 0; i < 26; i++) if (cnt[i] > 0) return false;
	return true;
}
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%s%s%s", s + 1, t + 1, p + 1);
		if (check()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}