#include<bits/stdc++.h>
#define int long long
#define N 200015
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
int n,m,k,a[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	rep(i,1,m) scanf("%lld",&a[i]);
	int ans = 0,l = 1,st = 1,cur = 0;
	for(;l <= m;){
		int ed = st+k-1;
		int d = max(a[l]-cur-ed,0ll); st += k*((d+k-1)/k);
		int r = l;
		while(r+1 <= m && a[r+1]-cur <= st+k-1) r++;
		cur += r-l+1; ans++;
		l = r+1;
	}
	printf("%lld\n",ans);
	return 0;
}