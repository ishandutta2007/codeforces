#include <bits/stdc++.h>
//#define int long long
#define ll long long
#define db double
#define fi first
#define se second
#define pii pair<int,int>
#define vi vector<int>

using namespace std;

int n,fa[205]; 

ll sum[205][205]; 
ll calcval(int x1,int x2,int y1,int y2) {
	if (x1>x2 || y1>y2) return 0;
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]; 
}
ll f[205][205]; 
int g[205][205]; 
ll calc(int l, int r) {
	return calcval(l,r,1,l-1)+calcval(l,r,r+1,n); 
}
int dfs(int l,int r) {
	if (l==r) return l;
	if (l>r) return 0; 
	int t=g[l][r]; 
	int ls=dfs(l,t-1),rs=dfs(t+1,r);
	fa[ls]=fa[rs]=t; 
	return t; 
}
int main() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			cin>>sum[i][j];
			sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
	for (int i=1;i<=n;i++) {
		f[i][i]=f[i+1][i]=0;
	}
	for (int len=2;len<=n;len++) {
		for (int l=1;l+len-1<=n;l++) {
			int r=l+len-1;
			f[l][r]=1e18; 
			for (int k=l;k<=r;k++) {
				ll d=f[l][k-1]+f[k+1][r]+calc(l,k-1)+calc(k+1,r);
				if (f[l][r]>d) {
					g[l][r]=k;
					f[l][r]=d; 
				}
			}
		}
	}
	dfs(1,n);
	for (int i=1;i<=n;i++) printf("%d ",fa[i]); 
	printf("\n"); 
	return 0;
}