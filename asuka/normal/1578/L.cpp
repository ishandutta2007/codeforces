#include<bits/stdc++.h>
#define ll long long
#define N 205
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int mod = 1e9 + 7;
int n, m, kmp[N], f[N][N][2], g[N][N][2];
char s[N];
void inc(int &x, int y) {
	x = (x + y >= mod) ? (x + y - mod) : (x + y);
}
void get(){
	int j = 0;
	rep(i, 2, m) {
		while(j && s[j + 1] != s[i]) j = kmp[j];
		if(s[j + 1] == s[i]) j++;
		kmp[i] = j;
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	scanf("%s", s + 1);
	m = strlen(s + 1);
	get();
	f[0][0][0] = 1;
	rep(i, 0, n * 2 - 1) {
		memset(g, 0, sizeof g);
		rep(k, 0, m) rep(p, -1, 1) rep(q, 0, 1) {
			if(p == 0) continue;
			char ch = (p == -1) ? ')' : '(';
			int nk = k;
			while(nk && s[nk + 1] != ch) nk = kmp[nk];
			if(s[nk + 1] == ch) nk++;
			rep(j, 0, n) {
				if(j + p >= 0) inc(g[j + p][nk][q | (nk == m)], f[j][k][q]);
			}
		}
		swap(f, g);
	}
	int ans = 0;
	rep(k, 0, m) inc(ans, f[0][k][1]);
	printf("%d\n", ans);
	return 0;
}
/*
5
()))()

5

3
(()

4

2
(((

0
*/