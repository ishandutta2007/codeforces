//by dxm
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

int n,a[200005];
void solve(){
	scanf("%d",&n);rep(i,n)scanf("%d",&a[i]);
	rep(i,n-1)if(a[i+1]-a[i]>=2||a[i+1]-a[i]<=-2){printf("YES\n%d %d\n",i+1,i+2);return;}
	printf("NO\n");
}
int main(){
	int T;scanf("%d",&T);while(T--)solve();
	return 0;
}