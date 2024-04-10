#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps=1e-10;
const int mod=998244353;
const int MAXN=100005;
const int G=3;
const int InvG=332748118;
template <typename T>
void read(T &x) {
	T flag=1;
	char ch=getchar();
	for (; '0'>ch||ch>'9'; ch=getchar()) if (ch=='-') flag=-1;
	for (x=0; '0'<=ch&&ch<='9'; ch=getchar()) x=x*10+ch-'0';
	x*=flag;
}
template <typename T>
T mul(T x, T y) { return 1ll*x*y%mod; }
template <typename T>
T add(T x, T y) { return ((x+y)%mod+mod)%mod; }
void file() {
#ifdef lcwtxdy
	freopen("test.in", "r", stdin);
#endif
}
int ksm(int a, int b) {
	int ret=1;
	for (; b; b>>=1, a=mul(a, a)) if (b&1) ret=mul(ret, a);
	return ret;
}
int T;
int n, m;
char mp[505][505];
int stk[505], top;
void print() {
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			putchar(mp[i][j]);
		} putchar('\n');
	}
}
bool check(int x, int y) {
	x--;
	while (x>=1&&mp[x][y]!='X') {
		if (mp[x-1][y]=='X'&&mp[x][y-1]=='X') return false;
		if (mp[x-1][y]=='X'&&mp[x][y+1]=='X') return false;
		x--;
	}
	return true;
}
int main() { file();
	read(T);
	int tmp=T;
	for (int t=1; t<=T; t++) {
		top=0;
		read(n); read(m);
		for (int i=1; i<=n; i++) {
			scanf("%s", mp[i]+1);
		}
		for (int j=1; j<=m; j++) mp[n+1][j]='.';//add
//		if (t==9008&&tmp==10000) {
//			cout << n << " " << m << endl;
//			print();
//		}
		if (n%3==0||n%3==2) {
			for (int i=2; i<=n; i+=3) {
				for (int j=1; j<=m; j++) mp[i][j]='X';
			}
			
			for (int i=3; i<=n; i+=3) {
				bool flag=false;
				for (int j=1; j<=m; j++) {
					if (mp[i][j]=='X') {
						mp[i+1][j]='X';
						flag=true;
						break;
					}
					if (mp[i+1][j]=='X') {
						mp[i][j]='X';
						flag=true;
						break;
					}
				}
				if (flag) continue;
				mp[i][1]=mp[i+1][1]='X';
			}
		} else {
			for (int i=1; i<=n; i+=3) for (int j=1; j<=m; j++) mp[i][j]='X';
			for (int i=2; i<=n; i+=3) {
				bool flag=false;
				for (int j=1; j<=m; j++) {
					if (mp[i][j]=='X') {
						mp[i+1][j]='X';
						flag=true;
						break;
					}
					if (mp[i+1][j]=='X') {
						mp[i][j]='X';
						flag=true;
						break;
					}
				}
				if (flag) continue;
				mp[i][1]=mp[i+1][1]='X';
			}
		}
		print();
//		if (tmp<10000) print();
	}
	return 0;
}