#include<bits/stdc++.h>
#define int long long
#define N 400015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,d,m,a[N],l[N],s[N],zl,zs,ans;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld%lld",&n,&d,&m);
	rep(i,1,n) {
		scanf("%lld",&a[i]);
		if(a[i] > m) l[++zl] = a[i];
		else s[++zs] = a[i];
	}
	if(zl == 0){
		rep(i,1,n) ans += a[i];
		printf("%lld\n",ans);
		return 0;
	}
	sort(l+1,l+zl+1,greater<int>()); sort(s+1,s+zs+1,greater<int>());
	rep(i,1,zl) l[i] += l[i-1]; rep(i,1,zs) s[i] += s[i-1];fill(s+zs+1,s+n+1,s[zs]);
	rep(i,(zl+d)/(d+1),zl){
		int num = (i-1)*(d+1)+1;
		int left = n-num;
		if(left >= 0) ans = max(ans,l[i]+s[left]);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
d = 3
1 2 3 4 5
1 0 0 0 1
*/