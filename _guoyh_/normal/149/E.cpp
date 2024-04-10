# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
int n, m;
int fail[MAXN];
int f1[MAXN], f2[MAXN];
char s1[MAXN], p1[MAXN];
char s2[MAXN], p2[MAXN];
int getnxt(char p[], int pos, char c){
	while (pos != -1 && p[pos + 1] != c) pos = fail[pos];
	return pos + 1;
}
void match(char s[], char p[], int psz, int f[]){
	fail[0] = -1;
	for (int i = 1; i <= psz; i++) fail[i] = getnxt(p, fail[i - 1], p[i]);
	int nw = 0;
	for (int i = 1; i <= n; i++){
		nw = getnxt(p, nw, s[i]);
		f[i] = max(f[i - 1], nw);
	}
}
int main(){
	scanf("%s", s1 + 1);
	n = strlen(s1 + 1);
	for (int i = 1; i <= n; i++) s2[i] = s1[n - i + 1];
	scanf("%d", &m);
	int cnt = 0;
	for (int i = 1; i <= m; i++){
		scanf("%s", p1 + 1);
		int psz = strlen(p1 + 1);
		if (psz == 1) continue;
		for (int j = 1; j <= psz; j++) p2[j] = p1[psz - j + 1];
		memset(f1, 0, sizeof(f1));
		memset(f2, 0, sizeof(f2));
		match(s1, p1, psz, f1);
		match(s2, p2, psz, f2);
		// for (int j = 1; j <= n; j++) printf("%d ", f1[j]);
		// putchar('\n');
		// for (int j = n; j >= 1; j--) printf("%d ", f2[i]);
		// putchar('\n');
		bool flag = false;
		for (int j = 1; j <= n; j++){
			if (f1[j] + f2[n - j] >= psz){
				flag = true;
				break;
			}
		}
		cnt += flag;
	}
	printf("%d\n", cnt);
	return 0;
}