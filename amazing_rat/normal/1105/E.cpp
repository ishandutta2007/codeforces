#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=(1e9)+7;
const ll M=998244353;
const int maxn=(1e5)+10;
int N,n,m,len,mid;
char s[50];
ll K[50];
int ans,vis[50];
int b[1<<20],c[1<<20];
int dp[1<<20][21];
bool a[50][50];
map<ll,int> t;
struct node {
	int op; ll h;
} d[maxn];
void dfs(int x,int s1,int s2,ll tmp,int cnt) {
	if (x>s2) {
		if (s1==1) b[tmp]=cnt;
		else c[tmp>>mid]=cnt;
		return;
	}
	dfs(x+1,s1,s2,tmp,cnt);
	for (int i=s1;i<x;i++)
		if (tmp&(1LL<<(i-1)))
			if (a[x][i]) return;
	dfs(x+1,s1,s2,tmp+(1LL<<(x-1)),cnt+1);
}
int main() {
//	freopen("1.txt","r",stdin);
	read(m); read(N);
	for (int i=1;i<=m;i++) {
		read(d[i].op);
		if (d[i].op==2) {
			scanf("%s",s+1);
			len=strlen(s+1);
			for (int j=1;j<=len;j++)
				d[i].h=(d[i].h*M%mod+s[j])%mod; 
			if (!t.count(d[i].h)) t[d[i].h]=++n;
		}
	} d[m+1].op=1;
	for (int i=1;i<=n;i++) a[i][i]=1;
	for (int i=1;i<=m+1;i++) {
		if (d[i].op==2) vis[t[d[i].h]]=1;
		else {
			for (int j=1;j<=n;j++)
			for (int k=j+1;k<=n;k++)
				if (vis[j]&&vis[k])
					a[j][k]=a[k][j]=1;
			memset(vis,0,sizeof(vis));
		}
	}
	if (n==1) { printf("%d\n",N); return 0; }
	mid=n/2;
	dfs(1,1,mid,0,0); dfs(mid+1,mid+1,n,0,0);
	//for (int i=1;i<=n;i++)
		//for (int j=i+1;j<=n;j++)
			//if (a[i][j]) printf("%d %d\n",i,j);
	for (int i=1;i<=mid;i++) {
		for (int j=mid+1;j<=n;j++)
			if (!a[i][j]) K[i]+=1LL<<(j-1);
	} ll tmp;
	for (int x=0;x<(1<<(n-mid));x++) {
		dp[x][n-mid]=c[x];
		for (int y=n-mid-1;y>=0;y--) {
			dp[x][y]=dp[x][y+1];
			if (x&(1<<y)) dp[x][y]=max(dp[x][y],dp[x-(1<<y)][y+1]);
		}
	}
	for (int t=0;t<(1LL<<mid);t++) {
		tmp=(1LL<<n)-1;
		for (int j=1;j<=mid;j++)
			if (t&(1LL<<(j-1))) tmp&=K[j];
		ans=max(ans,b[t]+dp[tmp>>mid][0]);
	}
	printf("%d\n",ans+N-n);
	return 0;
}