# include <bits/stdc++.h>
# define int long long
using namespace std;
const int MAXN = 1005;
const int P = 1000000007;
struct Trie{
	struct Node{
		bool flag;
		int fail;
		int nxt[10];
	} t[MAXN * 31];
	int tsz, rt, hd;
	Trie(){
		tsz = 0;
		rt = ++tsz;
		hd = ++tsz;
		for (int i = 0; i < 10; i++) t[rt].nxt[i] = hd;
	}
	void insert(char s[], int len){
		int p = hd;
		for (int i = 0; i < len; i++){
			if (!t[p].nxt[s[i] - '0']) t[p].nxt[s[i] - '0'] = ++tsz;
			p = t[p].nxt[s[i] - '0'];
		}
		t[p].flag = true;
	}
	void getfail(){
		queue <int> q;
		t[hd].fail = rt;
		q.push(hd);
		while (!q.empty()){
			int nw = q.front();
			q.pop();
			for (int i = 0; i < 10; i++){
				if (t[nw].nxt[i]){
					t[t[nw].nxt[i]].fail = t[t[nw].fail].nxt[i];
					q.push(t[nw].nxt[i]);
				} else t[nw].nxt[i] = t[t[nw].fail].nxt[i];
			}
		}
	}
} trie;
int n1, n2;
char s[MAXN];
char l[55], r[55];
int a[55];
int f[55][MAXN * 31][2];
int dfs(int pos, int nw, bool f1){
	// printf("dfs %d %d %d %d\n", pos, nw, trie.t[nw].flag, f1);
	if (pos == n2 + 1) return trie.t[nw].flag;
	if (f[pos][nw][f1] != -1) return f[pos][nw][f1];
	int ans = 0;
	int mxn = f1 ? a[pos] : 9;
	for (int i = 0; i <= mxn; i++){
		int nxtn = trie.t[nw].flag ? nw : trie.t[nw].nxt[i];
		ans = (ans + dfs(pos + 1, nxtn, f1 && i == mxn)) % P;
	}
	return f[pos][nw][f1] = ans;
}
signed main(){
//	freopen("pi.in", "r", stdin);
//	freopen("pi.out", "w", stdout);
	scanf("%s", s + 1);
	scanf("%s", l + 1);
	scanf("%s", r + 1);
	n1 = strlen(s + 1);
	n2 = strlen(l + 1);
	int h2 = n2 / 2;
	for (int i = 1; i + h2 - 1 <= n1; i++) trie.insert(s + i, h2);
	trie.getfail();
	// printf("AAAAAAAAAAAAAA\n");
	for (int i = 1; i <= n2; i++) a[i] = r[i] - '0';
	// for (int i = 1; i <= n2; i++) printf("%d", a[i]);
	// putchar('\n');
	memset(f, -1, sizeof(f));
	int ans = dfs(1, trie.hd, true);
	for (int i = 1; i <= n2; i++) a[i] = l[i] - '0';
	for (int i = n2; i >= 1; i--){
		if (a[i] > 0){
			a[i]--;
			break;
		} else a[i] = 9;
	}
	// for (int i = 1; i <= n2; i++) printf("%d", a[i]);
	// putchar('\n');
	memset(f, -1, sizeof(f));
	ans -= dfs(1, trie.hd, true);
	printf("%lld\n", (ans + P) % P);
	return 0;
}