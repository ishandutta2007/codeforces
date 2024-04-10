# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 5051;
int n, m;
char s[MAXN], t[MAXN];
int fail[MAXN];
int cnt1[MAXN], cnt2[MAXN];
int solve(int pos){
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));
	fail[pos - 1] = pos - 2;
	for (int i = pos; i <= n; i++){
		int p = fail[i - 1];
		while (p != pos - 2 && s[p + 1] != s[i]) p = fail[p];
		fail[i] = p + 1;
	}
	int nw = pos - 1;
	for (int i = 1; i <= m; i++){
		while (nw != pos - 2 && s[nw + 1] != t[i]) nw = fail[nw];
		cnt1[++nw]++;
	}
	nw = pos - 1;
	for (int i = 1; i <= n; i++){
		while (nw != pos - 2 && s[nw + 1] != s[i]) nw = fail[nw];
		cnt2[++nw]++;
	}
	for (int i = n; i >= pos; i--){
		cnt1[fail[i]] += cnt1[i];
		cnt2[fail[i]] += cnt2[i];
	}
	for (int i = pos; i <= n; i++){
		if (cnt1[i] == 1 && cnt2[i] == 1) return i - pos + 1;
	}
	return 1e9;
}
int main(){
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	int ans = 1e9;
	for (int i = n; i >= 1; i--){
		ans = min(ans, solve(i));
	}
	if (ans == 1e9) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}