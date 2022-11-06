#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
const int mxn = 1e5+5;
int main(){
	int n,dp[mxn],ans=-1;
	scanf("%d",&n);
	vector<pair<int,int> > ab(n);
	rep(i,0,n) scanf("%d%d",&ab[i].first,&ab[i].second);
	sort(ab.begin(),ab.end());
	rep(i,0,n){
		int a = ab[i].first;
		int b = ab[i].second;
		int l = -1, u = i;
		while(l < u-1){
			int m = (l+u)/2;
			if(ab[m].first<a-b)
				l = m;
			else
				u = m;
		}
		dp[i] = (l == -1 ? 0 : dp[l])+1;
		ans = max(ans, dp[i]);
	}
	printf("%d\n",n-ans);
}