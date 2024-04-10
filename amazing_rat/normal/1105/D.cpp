#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=1010;
int n,m,k,step[10],cnt;
char s[maxn][maxn];
bool vis[maxn][maxn];
int ans[10],d[maxn][maxn];
int fx[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct node {
	int x,y,t;
};
queue<node> q[10],Q;
void solve() {
	for (int i=1;i<=k;i++) printf("%d ",ans[i]); printf("\n");
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); read(k);
	for (int i=1;i<=k;i++) read(step[i]);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		if (s[i][j]=='#') d[i][j]=-1;
		else if (s[i][j]=='.') cnt++;
		else {
			d[i][j]=s[i][j]-'0';
			q[d[i][j]].push((node){i,j,0});
			ans[d[i][j]]++; vis[i][j]=1;
		}
	int x,y,a,b,t,flag=1;
	node A;
	while (flag) { flag=0;
		for (register int i=1;i<=k;++i) {
			while (!q[i].empty()) {
				A=q[i].front(); q[i].pop();
				Q.push((node){A.x,A.y,0});
			}
			while (!Q.empty()) {
				A=Q.front(); Q.pop(); flag=1;
				x=A.x; y=A.y; t=A.t;
				for (register int j=0;j<4;++j) {
					a=x+fx[j][0],b=y+fx[j][1];
					if (a<1||b<1||a>n||b>m||s[a][b]!='.'||vis[a][b]) continue;
					vis[a][b]=1; d[a][b]=i;
					ans[i]++; cnt--;
					if (!cnt) {
						solve(); return 0;
					}
					if (t+1==step[i]) q[i].push((node){a,b,0});
					else Q.push((node){a,b,t+1});
				}
			}
		}
	}
	solve();
	return 0;
}