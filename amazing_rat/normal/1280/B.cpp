#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,m;
char s[65][65];
bool flag;
void solve() {
	flag=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		if (s[i][j]=='A') { flag=0; break; }
	if (flag) { printf("MORTAL\n"); return; }
	flag=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		if (s[i][j]=='P') { flag=0; break; }
	if (flag) { printf("0\n"); return; }	
	flag=1;
	for (int i=1;i<=n;i++)
		if (s[i][1]=='P') { flag=0; break; }
	if (flag) { printf("1\n"); return; }
	flag=1;
	for (int i=1;i<=n;i++)
		if (s[i][m]=='P') { flag=0; break; }
	if (flag) { printf("1\n"); return; }
	flag=1;
	for (int i=1;i<=m;i++)
		if (s[1][i]=='P') { flag=0; break; }
	if (flag) { printf("1\n"); return; }
	flag=1;
	for (int i=1;i<=m;i++)
		if (s[n][i]=='P') { flag=0; break; }
	if (flag) { printf("1\n"); return; }
	if (s[1][1]=='A'||s[1][m]=='A'||s[n][1]=='A'||s[n][m]=='A') {
		printf("2\n"); return;
	}
	for (int i=1;i<=n;i++) {
		flag=1;
		for (int j=1;j<=m;j++)
			if (s[i][j]=='P') { flag=0; break; }
		if (flag) { printf("2\n"); return; }
	}
	for (int j=1;j<=m;j++) {
		flag=1;
		for (int i=1;i<=n;i++)
			if (s[i][j]=='P') { flag=0; break; }
		if (flag) { printf("2\n"); return; }
	}
	flag=1;
	for (int i=1;i<=n;i++)
		if (s[i][1]=='A') { flag=0; break; }
	if (!flag) { printf("3\n"); return; }
	flag=1;
	for (int i=1;i<=n;i++)
		if (s[i][m]=='A') { flag=0; break; }
	if (!flag) { printf("3\n"); return; }
	flag=1;
	for (int i=1;i<=m;i++)
		if (s[1][i]=='A') { flag=0; break; }
	if (!flag) { printf("3\n"); return; }
	flag=1;
	for (int i=1;i<=m;i++)
		if (s[n][i]=='A') { flag=0; break; }
	if (!flag) { printf("3\n"); return; }
	printf("4\n");
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(m);
		for (int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		solve();
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/