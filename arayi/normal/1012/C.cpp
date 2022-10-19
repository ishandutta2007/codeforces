#include <bits/stdc++.h>
using namespace std;

const int mxN=5e5, INF=1e9;
int n, a[mxN+3], dp[2][mxN+2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	a[0]=INF;
	a[1]=0;
	for(int i=2; i<=n+1; ++i)
		cin >> a[i];
	a[n+2]=0;
	memset(dp[0]+1, 0x3F, 4*(n+1));
	memset(dp[1], 0x3F, 8);
	for(int i=1; i<=(n+1)/2; ++i) {
		int b=INF, c=INF;
		for(int j=2; j<=n+1; ++j) {
			dp[i&1][j]=min(b+max(a[j-1]-a[j]+1, 0), dp[i&1^1][j-2]+max(min(a[j-1], a[j-2]-1)-a[j]+1, 0))+max(a[j+1]-a[j]+1, 0);
			b=min(dp[i&1^1][j-2], b);
			c=min(dp[i&1][j], c);
		}
		cout << c << " ";
		if(i==1)
			dp[0][0]=INF;
	}
}