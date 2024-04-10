#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=1010;
int n,m,x,y;
ll ans,cnt;
char s[maxn][maxn];
int nxt[maxn][maxn],flag;
struct node {
	int a,b,c,len;
	friend bool operator == (node t1,node t2) {
		return t1.a==t2.a&&t1.b==t2.b&&t1.c==t2.c&&t1.len==t2.len;
	}
} d[maxn][maxn],A;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (int j=1;j<=m;j++) {
		for (int i=n;i>=1;i--) {
			if (s[i][j]==s[i+1][j]) nxt[i][j]=nxt[i+1][j];
			else nxt[i][j]=i+1;
			x=nxt[i][j];
			A=(node){0,0,0,0};
			if (x&&nxt[x][j]) {
				y=nxt[x][j];
				if (x-i==y-x&&nxt[y][j]-y>=x-i) {
					A.len=x-i;
					A.a=s[i][j]-'a'+1;
					A.b=s[x][j]-'a'+1;
					A.c=s[y][j]-'a'+1;
					//printf("%d %d %d %d %d %d\n",i,j,A.a,A.b,A.c,A.len);
				}
			}
			d[i][j]=A;
		}
	}
	for (int i=1;i<=n;i++) {
		cnt=0;
		for (int j=m;j>=1;j--) {
			if (!(d[i][j]==d[i][j+1])||j==m) cnt=1; else cnt++;
			if (d[i][j].a) ans+=cnt;
		}
	}
	printf("%lld\n",ans);
	return 0;
}