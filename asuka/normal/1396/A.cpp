#include<bits/stdc++.h>
#define int long long
#define N 100015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,a[N],ans[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&n);
 	rep(i,1,n) scanf("%lld",&a[i]);
 	if(n==1){
 		printf("1 1\n%lld\n",-a[1]);a[1] = 0;
 		printf("1 1\n%lld\n",-a[1]);a[1] = 0;
 		printf("1 1\n%lld\n",-a[1]);a[1] = 0;
 		return 0;
 	}
 	printf("1 1\n%lld\n",-a[1]);a[1] = 0;
 	rep(i,2,n){
 		int m = a[i]%n;
 		ans[i] = m*(n-1);
 		a[i] += m*(n-1);
 	}
 	printf("2 %lld\n",n);
 	rep(i,2,n){
 		printf("%lld ",ans[i]);
 	}
 	printf("\n");
 	printf("1 %lld\n",n);
 	rep(i,1,n) printf("%lld ",-a[i]);
	return 0;
}