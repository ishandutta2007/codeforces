# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 100051;
int n, m;
char s[MAXN];
int cnt[6];
int cc[1 << 6];
int lm[MAXN];
int cl[1 << 6];
int lg[1 << 6];
bool check(){
	for (int i = 1; i < (1 << 6); i++){
		if (i == (1 << lg[i])) cc[i] = cnt[lg[i]];
		else cc[i] = cc[i ^ (i & (-i))] + cnt[lg[i & (-i)]];
		// printf("cc %d %d %d\n", i, cl[i], cc[i]);
		if (cl[i] < cc[i]) return false;
	}
	return true;
}
int calc(){
	int s1 = (1 << 6) - 1;
	for (int i = 1; i < (1 << 6); i++){
		if (i == (1 << lg[i])) cc[i] = cnt[lg[i]];
		else cc[i] = cc[i ^ (i & (-i))] + cnt[lg[i & (-i)]];
		if (cl[i] < cc[i]) s1 &= i;
	}
	return s1;
}
int main(){
	lg[1] = 0;
	for (int i = 2; i < (1 << 6); i++) lg[i] = (1 << (lg[i - 1] + 1)) <= i ? lg[i - 1] + 1 : lg[i - 1];
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) cnt[s[i] - 'a']++;
	for (int i = 1; i <= n; i++) lm[i] = (1 << 6) - 1;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++){
		int pos;
		scanf("%d%s", &pos, s + 1);
		int len = strlen(s + 1);
		lm[pos] = 0;
		for (int j = 1; j <= len; j++) lm[pos] |= (1 << (s[j] - 'a'));
	}
	for (int i = 1; i <= n; i++){
		// printf("lm %d %d\n", i, lm[i]);
		for (int s1 = 1; s1 < (1 << 6); s1++){
			if (s1 & lm[i]){
				cl[s1]++;
				// printf("s1 %d\n", s1);
			}
		}
	}
	if (!check()){
		printf("Impossible\n");
		return 0;
	}
	for (int i = 1; i <= n; i++){
		for (int s1 = 1; s1 < (1 << 6); s1++) if (s1 & lm[i]) cl[s1]--;
		int s1 = calc() & lm[i];
		cnt[lg[s1 & (-s1)]]--;
		printf("%c", 'a' + lg[s1 & (-s1)]);
	}
	putchar('\n');
	return 0;
}