#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9);
int n,b,c,t1,t2,delta,ans;
char a[1010],s[60],t[60];
int dp[1010][55][55];
int nxt1[55][30],nxt2[55][30];
int main() {
	//freopen("1.txt","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%s",a+1);
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(a+1);
	b=strlen(s+1);
	c=strlen(t+1);
	memset(nxt1,-1,sizeof(nxt1));
	memset(nxt2,-1,sizeof(nxt2));
	nxt1[0][s[1]-'a'+1]=0;
	for (int i=1;i<=b;i++) {
		for (int ch=1;ch<=26;ch++) {
			if (i==b||ch+'a'-1==s[1]) nxt1[i][ch]=0;
			for (int j=1;j<=i;j++) {
				if (i==b&&j==1) continue;
				int flag=1;
				for (int k=j;k<=i;k++)
					if (s[k]!=s[k-j+1]) { flag=0; break; }
				//if (i==1&&ch==5) printf("%d %d\n",j,flag);
				if (i<b&&ch+'a'-1!=s[i-j+2]) flag=0;
				if (flag) { nxt1[i][ch]=i-j+1; break; }
			}
		}
	}
	//printf("%d\n",nxt1[1][5]);
	//return 0;
	nxt2[0][t[1]-'a'+1]=0;
	for (int i=1;i<=c;i++) {
		for (int ch=1;ch<=26;ch++) {
			if (i==c||ch+'a'-1==t[1]) nxt2[i][ch]=0;
			for (int j=1;j<=i;j++) {
				if (i==c&&j==1) continue;
				int flag=1;
				for (int k=j;k<=i;k++)
					if (t[k]!=t[k-j+1]) { flag=0; break; }
				if (i<c&&ch+'a'-1!=t[i-j+2]) flag=0;
				if (flag) { nxt2[i][ch]=i-j+1; break; }
			}
		}
	}
	for (int i=0;i<=n;i++)
	for (int x=0;x<=b;x++)
	for (int y=0;y<=c;y++) dp[i][x][y]=-INF;
	dp[0][0][0]=0;
	for (int i=0;i<n;i++)
	for (int x=0;x<b;x++)
	for (int y=0;y<c;y++) {
		if (dp[i][x][y]<=-INF) continue;
	//	printf("!! %d\n",dp[3][1][0]);
		for (int ch=1;ch<=26;ch++)
			if (a[i+1]=='*'||a[i+1]==ch+'a'-1) {
				t1=nxt1[x][ch]+1;
				t2=nxt2[y][ch]+1;
				//printf("%d %d %d %d %d\n",i,x,y,t1,t2);
				delta=0;
				if (t1==b) delta++,t1=nxt1[t1][1];
				if (t2==c) delta--,t2=nxt2[t2][1];
				dp[i+1][t1][t2]=max(dp[i+1][t1][t2],dp[i][x][y]+delta);
				//printf("%d\n",dp[1][0][0]);
				//printf("%d %d %d %d %d %d\n",i,t1,t2,dp[i+1][t1][t2],delta,dp[i][x][y]);
			}
	} ans=-INF;
	for (int x=0;x<b;x++)
	for (int y=0;y<c;y++)
		ans=max(ans,dp[n][x][y]);
	printf("%d\n",ans);
	return 0;
}