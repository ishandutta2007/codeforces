# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 100051;
int n, q;
char s[MAXN];
bool flag[MAXN];
bool check(int pos){
	if (pos <= 0 || pos + 2 > n) return false;
	return s[pos] == 'a' && s[pos + 1] == 'b' && s[pos + 2] == 'c';
}
int main(){
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += (flag[i] = check(i));
	for (int i = 1; i <= q; i++){
		int u;
		char c;
		scanf("%d", &u);
		scanf(" %c", &c);
		s[u] = c;
		for (int j = 1; j <= 3 && u - j + 1 >= 1; j++){
			cnt -= flag[u - j + 1];
			cnt += (flag[u - j + 1] = check(u - j + 1));
		}
		printf("%d\n", cnt);
	}
	return 0;
}