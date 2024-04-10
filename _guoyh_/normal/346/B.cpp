# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 105;
struct Node{
	char c;
	int u, v, w;
	Node(){}
	Node(char c, int u, int v, int w): c(c), u(u), v(v), w(w){}
};
int n, m, l, asz;
int fail[MAXN];
char a[MAXN];
int f[MAXN][MAXN][MAXN];
Node pre[MAXN][MAXN][MAXN];
char s1[MAXN], s2[MAXN], t[MAXN];
int getnxt(int nw, char c){
	while (nw != -1 && t[nw + 1] != c) nw = fail[nw];
	return nw + 1;
}
bool update(int &a, int b){
	bool flag = b > a;
	a = max(a, b);
	return flag;
}
int main(){
	scanf("%s%s%s", s1 + 1, s2 + 1, t + 1);
	n = strlen(s1 + 1);
	m = strlen(s2 + 1);
	l = strlen(t + 1);
	fail[0] = -1;
	for (int i = 1; i <= l; i++) fail[i] = getnxt(fail[i - 1], t[i]);
	Node ans = Node('\0', 0, 0, 0);
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++){
			for (int k = 0; k < l; k++){
				if (f[i][j][k] > f[ans.u][ans.v][ans.w]) ans = Node('\0', i, j, k);
				if (update(f[i + 1][j][k], f[i][j][k])) pre[i + 1][j][k] = Node('\0', i, j, k);
				if (update(f[i][j + 1][k], f[i][j][k])) pre[i][j + 1][k] = Node('\0', i, j, k);
				if (s1[i + 1] == s2[j + 1]){
					int nxtk = getnxt(k, s1[i + 1]);
					if (update(f[i + 1][j + 1][nxtk], f[i][j][k] + 1)) pre[i + 1][j + 1][nxtk] = Node(s1[i + 1], i, j, k);
				}
			}
		}
	}
	while (ans.u != 0 && ans.v != 0){
		if (pre[ans.u][ans.v][ans.w].c != '\0') a[++asz] = pre[ans.u][ans.v][ans.w].c;
		ans = pre[ans.u][ans.v][ans.w];
	}
	if (asz == 0) printf("0\n");
	else {
		for (int i = asz; i >= 1; i--) printf("%c", a[i]);
		putchar('\n');
	}
	return 0;
}