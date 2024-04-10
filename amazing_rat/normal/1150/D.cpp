#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9);
int n,q,l[5];
char s[100010];
int nxt[100010][30];
int dp[255][255][255];
char a[5][255];
int tmp[5];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(q);
	scanf("%s",s+1);
	s[n+1]='a'+27;
	for (int i=1;i<=26;i++) nxt[n+1][i]=n+1;
	for (int i=n;i>=0;i--) {
		for (int j=1;j<=26;j++) nxt[i][j]=nxt[i+1][j];
		nxt[i][s[i+1]-'a'+1]=i+1;
	}
	char t[5]; int x;
	while (q--) {
		scanf("%s",t+1);
		read(x);
		if (t[1]=='+') {
			scanf("%s",t+1);
			a[x][++l[x]]=t[1];
			tmp[1]=tmp[2]=tmp[3]=0;
			tmp[x]=l[x];
			for (int x=tmp[1];x<=l[1];x++)
			for (int y=tmp[2];y<=l[2];y++)
			for (int z=tmp[3];z<=l[3];z++) {
				dp[x][y][z]=INF;
				if (x&&dp[x-1][y][z]<INF) dp[x][y][z]=min(dp[x][y][z],nxt[dp[x-1][y][z]][a[1][x]-'a'+1]);
				if (y&&dp[x][y-1][z]<INF) dp[x][y][z]=min(dp[x][y][z],nxt[dp[x][y-1][z]][a[2][y]-'a'+1]);
				if (z&&dp[x][y][z-1]<INF) dp[x][y][z]=min(dp[x][y][z],nxt[dp[x][y][z-1]][a[3][z]-'a'+1]);
			}
		} else l[x]--;
		if (dp[l[1]][l[2]][l[3]]<=n) printf("YES\n");
		else printf("NO\n");
	}	
	return 0;
}