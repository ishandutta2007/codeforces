//by dxm
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

int n,a[100005];
void solve(){
	scanf("%d",&n);rep(i,n)scanf("%d",&a[i]);
	long long b=0,c=0;rep(i,n)c^=a[i];rep(i,n)b+=a[i];b+=c;
	printf("2\n%lld %lld\n",b,c);
}
int main(){
	int T;scanf("%d",&T);while(T--)solve();
	return 0;
}