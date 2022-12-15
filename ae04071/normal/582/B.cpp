#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;

const int inf = 1e9;
class mat{
public:
	int a[301][301],n;
	mat() {}
	void init(int n) {
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) a[i][j] = -inf;
		this->n = n;
	}
	mat mul_max(mat &rhs) {
		mat res;
		res.init(n);
		for(int i=0;i<n;i++) for(int j=i;j<n;j++) {
			for(int k=i;k<=j;k++) res.a[i][j] = max(res.a[i][j], a[i][k] + rhs.a[k][j]);
		}
		return res;
	}
};

int n,T,a[100];
mat o;
mat power(mat a, int p) {
	mat res;
	res.init(301);
	for(int i=0;i<=300;i++) for(int j=i;j<=300;j++) res.a[i][j] = 0;
	while(p) {
		if(p&1) res=res.mul_max(a);
		a=a.mul_max(a);
		p>>=1;
	}
	return res;
}

int dp[101][301][301];
int DP(int idx,int val,int mx) {
	int &ret=dp[idx][val][mx];
	if(ret!=-1) return ret;

	if(idx==n) return ret=0;
	ret=DP(idx+1,val,mx);
	if(a[idx]>=val && a[idx]<=mx) ret = max(ret,DP(idx+1,a[idx],mx)+1);
	return ret;
}

int main() {
	scanf("%d%d",&n,&T);
	for(int i=0;i<n;i++) scanf("%d",a+i);

	o.init(301);
	memset(dp,-1,sizeof(dp));

	for(int i=1;i<301;i++) for(int j=i;j<=300;j++)
		o.a[i][j] = DP(0,i,j);
	
	o = power(o,T);
	int mx=1;
	for(int i=0;i<=300;i++) for(int j=0;j<=300;j++) 
		mx = max(mx,o.a[i][j]);
	printf("%d\n",mx);
	
	return 0;
}