#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e16;
const int maxn=(2e5)+10;
typedef pair<pair<int,int>,int> p;
int n,m,k,s[maxn],t[maxn],d[maxn],w[maxn],t1,t2;
ll dp[maxn/2][210],ans;
struct cmp {
	bool operator() (p a,p b) {
		if (a>b) return 0; return 1;
	}
};
priority_queue<p,vector<p>,cmp> q;
struct node {
	int pos,P;
} a[maxn],b[maxn];
int vis[maxn],u[maxn];
bool cmp2(node x,node y) {
	return x.pos<y.pos;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); read(k);
	for (int i=1;i<=k;i++) {
		read(s[i]),read(t[i]),read(d[i]),read(w[i]);
		a[++t1]=(node){s[i],i};
		b[++t2]=(node){t[i],i};
	} sort(a+1,a+t1+1,cmp2);
	sort(b+1,b+t2+1,cmp2);
	int I1=1,I2=1;
	for (int i=1;i<=n;i++) {
		while (I1<=t1&&a[I1].pos==i) {
			q.push(make_pair(make_pair(w[a[I1].P],d[a[I1].P]),a[I1].P));
			I1++;
		}
		u[i]=-1;
		while (!q.empty()) {
			p A=q.top();
			u[i]=A.second;
			if (!vis[u[i]]) break;
			else q.pop(),u[i]=-1;
		}
		while (I2<=t2&&b[I2].pos==i) {
			vis[b[I2].P]=1;
			I2++;
		}
	}
	ans=INF;
	for (int i=n;i>=1;i--) {
		for (int j=0;j<=m;j++) {
			if (u[i]!=-1) dp[i][j]=dp[d[u[i]]+1][j]+w[u[i]];
			else dp[i][j]=dp[i+1][j];
			if (j) dp[i][j]=min(dp[i+1][j-1],dp[i][j]);
			if (i==1) ans=min(ans,dp[i][j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}