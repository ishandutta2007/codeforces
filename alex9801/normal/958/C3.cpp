#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const int mod1 = 1e9 + 409;
const int mod2 = 1e9 + 433;
typedef long long lint;
using pi = pair<lint, lint>;

int n, k, p, a[MAXN];
int dp[2][MAXN];

int tree[105];

void add(int x, int v){
	while(x <= p){
		tree[x] = min(tree[x], v);
		x += x & -x;
	}
}

int query(int x){
	int ret = 1e9;
	while(x){
		ret = min(ret, tree[x]);
		x -= x & -x;
	}
	return ret;
}

int main(){
	scanf("%d %d %d",&n,&k,&p);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		a[i] += a[i-1];
		a[i] %= p;
	}
	fill(dp[0] + 1, dp[0] + n + 1, 1e9);
	for(int i=1; i<=k; i++){
		fill(tree, tree + 105, 1e9);
		int *prv = dp[(i+1)%2], *nxt = dp[i%2];
		int mxv = 1e9;
		nxt[0] = 1e9;
		for(int j=1; j<=n; j++){
			add(a[j-1] + 1, prv[j-1]);
			mxv = min(mxv, prv[j-1] + 1);
			nxt[j] = min(mxv, query(a[j] +1));
		}
		swap(prv, nxt);
	}
	cout << dp[k%2][n] * p + a[n];
}