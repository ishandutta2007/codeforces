//by dxm
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

int n,k1,k2,a[105],b[105];
void solve(){
	scanf("%d%d%d",&n,&k1,&k2);rep(i,k1)scanf("%d",&a[i]);rep(i,k2)scanf("%d",&b[i]);
	int maxa=0,maxb=0;rep(i,k1)maxa=max(maxa,a[i]);rep(i,k2)maxb=max(maxb,b[i]);
	if(maxa>maxb)printf("YES\n");else printf("NO\n");
}
int main(){
	int T;scanf("%d",&T);while(T--)solve();
	return 0;
}