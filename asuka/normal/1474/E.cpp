#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,n,a[100015];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n == 2){
			printf("1\n2 1\n1\n1 2\n");
			continue;
		}
		if(n == 3){
			printf("5\n2 3 1\n2\n1 3\n3 2\n");
			continue;
		}
		ll ans = 0;
		rep(i,2,n) ans += max(1ll*(n-i)*(n-i),1ll*(i-1)*(i-1));
		int m = n/2;
		a[1] = m+1; rep(i,m+1,n-1) a[i] = i+1;
		a[n] = 2; rep(i,2,m) a[i] = (i%m)+1;
		printf("%lld\n",ans);
		rep(i,1,n) printf("%d ",a[i]); printf("\n");
		printf("%d\n",n-1);
		while(a[1] != n) printf("%d %d\n",a[1],1),swap(a[1],a[a[1]]);
		while(a[n] != 1) printf("%d %d\n",a[n],n),swap(a[n],a[a[n]]);
		printf("%d %d\n",a[1],1);
	}
	return 0;
}